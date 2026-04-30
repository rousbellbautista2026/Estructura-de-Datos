#include<stdio.h>
int main(void){

    int *ptr ,a;
     ptr = &a;
        printf("%p", ptr);
     *ptr =6;
        printf("%d", *ptr);


    return 0;
}