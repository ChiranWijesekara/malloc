#include<stdio.h>
#include "mymalloc.h"

int main(){

    char*p = (char*)MyMalloc(5000*sizeof(char));
    printf("%p",p);

   
    
   char*q = (char*)MyMalloc(25000);
   /* MyFree(q);
    MyFree(p);

    int*r = (int*)MyMalloc(5000*sizeof(int));
    char*x = (char*)MyMalloc(4000*sizeof(char));
    MyFree(q);
    char*y = (char*)MyMalloc(1000*sizeof(char));
    MyFree(r);
    char*z = (char*)MyMalloc(10000*sizeof(char));
    */
}