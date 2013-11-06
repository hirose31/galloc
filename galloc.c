#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void* (*orig_malloc)(size_t size) = NULL;
static void  (*orig_free)(void *ptr)   = NULL;

static void galloc_init(void) {
    orig_malloc = dlsym(RTLD_NEXT, "malloc");
    if (orig_malloc == NULL) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }

    orig_free = dlsym(RTLD_NEXT, "free");
    if (orig_free == NULL) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
}

void *malloc(size_t size) {
    if(orig_malloc == NULL) {
        galloc_init();
    }

    void *p = NULL;
    p = orig_malloc(size);
    fprintf(stderr, "Gachapin .oO(malloc(%d) = %p)\n", size, p);
    return p;
}

void free(void *ptr) {
    if(orig_free == NULL) {
        galloc_init();
    }

    orig_free(ptr);
    fprintf(stderr, "Mukku    .oO(free = %p)\n", ptr);
}

