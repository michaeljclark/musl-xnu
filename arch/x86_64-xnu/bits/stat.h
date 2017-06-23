struct stat {
	dev_t           st_dev;
	ino_t           st_ino;
	mode_t          st_mode;
	nlink_t         st_nlink;
	uid_t           st_uid;
	gid_t           st_gid;
	dev_t           st_rdev;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	off_t           st_size;
	blkcnt_t        st_blocks;
	blksize_t       st_blksize;
	unsigned        st_flags;
	unsigned        st_gen;
	unsigned        st_lspare;
	unsigned long   st_qspare[2];
};
