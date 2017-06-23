#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <bits/mach-o.h>

#define VM_PROT_WRITE 0x02

void __rebase_macho(uintptr_t image_base, intptr_t slide)
{
	struct mach_header_64* mh = (struct mach_header_64*)(image_base + slide);
	size_t cmd_count = mh->ncmds;
	struct load_command* cmds = (struct load_command*)(((char*)mh) + sizeof(*mh));
	struct load_command* cmd = cmds;
	struct segment_command_64* linkedit_seg = 0;
	struct segment_command_64* data_seg = 0;
	struct dysymtab_command* dynsymtab = 0;
	for (size_t i = 0; i < cmd_count; ++i) {
		switch (cmd->cmd) {
			case LC_SEGMENT_64: {
					struct segment_command_64* seg = (struct segment_command_64*)cmd;
					if (strcmp(seg->segname, SEG_LINKEDIT) == 0) linkedit_seg = seg;
					struct section_64* section_start =
						(struct section_64*)((char*)seg + sizeof(struct segment_command_64));
					struct section_64* section_end = &section_start[seg->nsects];
					for (struct section_64* sect = section_start; sect < section_end; ++sect) {
						uint8_t type = sect->flags & SECTION_TYPE;
						if (type == S_NON_LAZY_SYMBOL_POINTERS) {
							size_t ptr_cnt = sect->size / sizeof(uintptr_t);
							uintptr_t* sym_ptr = (uintptr_t*)(sect->addr + slide);
							for (size_t j = 0; j < ptr_cnt; ++j) {
								sym_ptr[j] += slide;
							}
						}
					}
					if ((data_seg == 0) && (seg->initprot & VM_PROT_WRITE)) {
						data_seg = seg;
					}
				}
				break;
			case LC_DYSYMTAB: {
				dynsymtab = (struct dysymtab_command *)cmd;
				break;
			}
		}
		cmd = (struct load_command*)(((char*)cmd)+cmd->cmdsize);
	}
	uintptr_t reloc_base = data_seg->vmaddr + slide;
	struct relocation_info* reloc_start = (struct relocation_info*)
		(linkedit_seg->vmaddr + slide + dynsymtab->locreloff - linkedit_seg->fileoff);
	struct relocation_info* reloc_end = &reloc_start[dynsymtab->nlocrel];
	for (struct relocation_info* reloc = reloc_start; reloc < reloc_end; ++reloc) {
		if (reloc->r_length != 3) abort();
		if (reloc->r_type != X86_64_RELOC_UNSIGNED) abort();
		*((uintptr_t*)(reloc->r_address + reloc_base)) += slide;
	}
}

