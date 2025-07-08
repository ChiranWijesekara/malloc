#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>

#define MEMORY_SIZE 25000

struct block {
    size_t size;
    int free;
    struct block *next;
};

void initialize();
void split(struct block *fitting_slot, size_t size);
void *MyMalloc(size_t noofbytes);
void merge();
void Myfree(void* ptr);

#endif 
