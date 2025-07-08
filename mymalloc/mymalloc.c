#include "mymalloc.h"
#include <stdio.h>

char memory[MEMORY_SIZE];  

struct block *freeList = (void*)memory;  
 
void initialize() {
    freeList = (struct block*)memory;
    freeList->size = MEMORY_SIZE - sizeof(struct block);
    freeList->free = 1;
    freeList->next = NULL;
}

void split(struct block *fitting_slot, size_t size) {
    struct block *new = (struct block*)((char*)fitting_slot + size + sizeof(struct block));
    new->size = fitting_slot->size - size - sizeof(struct block);
    new->free = 1;
    new->next = fitting_slot->next;

    fitting_slot->size = size;
    fitting_slot->free = 0;
    fitting_slot->next = new;
}


void *MyMalloc(size_t noofbytes) {
    struct block *curr;
    void *result = NULL;

    
    if (freeList->size == 0) {
        initialize();
        printf("<<<-Memory initialized\n");
    }

    curr = freeList;
    while ((curr->size < noofbytes || curr->free == 0) && curr->next != NULL) {
        curr = curr->next;
        printf("One block checked\n");
    }

    if (curr->size == noofbytes) {
        curr->free = 0;
        result = (void*)(curr + 1);
        printf("Exact fitting block allocated\n");
    } else if (curr->size > noofbytes + sizeof(struct block)) {
        split(curr, noofbytes);
        result = (void*)(curr + 1);
        printf("Block split and allocated\n");
    } else {
        printf("No sufficient memory to allocate->>>\n");
    }

    return result;
}


void merge() {
    struct block *curr = freeList;
    while (curr != NULL && curr->next != NULL) {
        if (curr->free && curr->next->free) {
            curr->size += curr->next->size + sizeof(struct block);
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void Myfree(void *ptr) {
    if (ptr == NULL) return;

    if (ptr >= (void*)memory && ptr < (void*)(memory + MEMORY_SIZE)) {
        struct block* curr = (struct block*)ptr - 1;
        curr->free = 1;
        merge();
    } else {
        printf("Please provide a valid pointer allocated by MyMalloc\n");
    }
}
