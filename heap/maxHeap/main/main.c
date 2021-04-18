#include<stdio.h>
#include<stdlib.h>


#define n 20
#define LEFT(f) f*2
#define RIGHT(f) f*2 + 1
void swap(int *a,int* b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int* maxheapify(int* heap, int ptr){
    int left = LEFT(ptr);
    int right = RIGHT(ptr);
    int max_ptr = 0;
    if( left <= n && heap[left] > heap[ptr]){
        max_ptr = left;
    }else max_ptr = ptr;
    if( right <= n && heap[right] > heap[max_ptr]) max_ptr = right;
    if(ptr!=max_ptr){
        swap(heap[ptr],heap[max_ptr]);
        maxheapify(heap,max_ptr);
    }
}
#define FINDROOT(a) a/2
int* heapify(int* heap,int ptr){
    int swap_ptr = ptr;
    if(LEFT(ptr) <= n && heap[LEFT(ptr)] > heap[ptr]){
        swap_ptr = LEFT(ptr);
    }
    if(RIGHT(ptr) <=n && heap[RIGHT(ptr)] > heap[swap_ptr]){
        swap_ptr  = RIGHT(ptr);
    }
    if(swap_ptr!= ptr){
        swap(&heap[ptr],&heap[swap_ptr]);
        heapify(heap,swap_ptr);
    }
    return heap;
}
void build_heap_rec(){
    int *heap = (int*)malloc(0x300);
    for(int i=1;i<n;i++){
        heap[i] = i;
    }
    for(int i=n/2;i>0;i--){
        heapify(heap,i);
    }

}
void build_heap(){
    int a[n] ={};
    int ptr = 0;
    int swap_ptr = 0;
    for(int i=0;i<n;i++){
        a[i] = i;
    }
    for(int i=1;i<n;i++){
        ptr = i;
        swap_ptr = ptr;
        while(ptr){
            if(FINDROOT(ptr)> 0 && a[FINDROOT(ptr)] < a[ptr]){
                swap_ptr =  FINDROOT(ptr);
            }
            if(ptr != swap_ptr){
                swap(&a[ptr],&a[swap_ptr]);
                ptr = FINDROOT(ptr);
            }else{
                break;
            }

        }
    }
   // int* heap = (int*)malloc(0x300);


}

int main(){
    //int a=3,b=4;
    //swap(&a,&b);
    //printf("%d %d\n",a,b);
    //build_heap();
    build_heap_rec();
    return 0;

}