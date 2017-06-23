#undef MAP_SHARED
#undef MAP_PRIVATE
#undef MAP_TYPE
#undef MAP_FIXED
#undef MAP_ANON
#undef MAP_NORESERVE
#undef MAP_GROWSDOWN
#undef MAP_DENYWRITE
#undef MAP_EXECUTABLE
#undef MAP_LOCKED
#undef MAP_POPULATE
#undef MAP_NONBLOCK
#undef MAP_STACK
#undef MAP_HUGETLB
#undef MAP_FILE

#define MAP_FILE         0x0000
#define MAP_SHARED       0x0001
#define MAP_PRIVATE      0x0002
#define MAP_FIXED        0x0010
#define MAP_RENAME       0x0020
#define MAP_NORESERVE    0x0040
#define MAP_RESERVED0080 0x0080
#define MAP_NOEXTEND     0x0100
#define MAP_HASSEMAPHORE 0x0200
#define MAP_NOCACHE      0x0400
#define MAP_JIT          0x0800
#define MAP_FILE         0x0000
#define MAP_ANON         0x1000
