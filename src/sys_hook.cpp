#define __USE_GNU
#include <dlfcn.h>
#include <stdio.h>

typedef ssize_t (*read_pfn_t)(int fildes, void *buf, size_t nbyte);
static read_pfn_t g_sys_read_func = (read_pfn_t)dlsym(RTLD_NEXT, "read");

ssize_t read(int fildes, void *buf, size_t nbyte)
{
    return g_sys_read_func(fd, buf, nbyte);
}
