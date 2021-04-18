#include<stdlib.h>
int main(){
    int* a = malloc(0x100);
    
    *(a+4)=20;
    free(a);
}