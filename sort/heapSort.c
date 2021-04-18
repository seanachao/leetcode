#include<stdio.h>
#include<stdlib.h>
#define LEFT(a) 2 * a
#define RIGHT(a) 2 * a + 1
#define swap(a,b){if(&a!=&b) {a^=b;b^=a;a^=b;}}
int* heapfix(int*heap ,int k ,int size){
    int left = LEFT(k);
    int right = RIGHT(k);
    int ptr = k;
    if(left<=size && heap[ptr] > heap[left%size]) ptr = left%size;
    if(right<=size && heap[ptr] > heap[right%size]) ptr = right%size;
    if(ptr!=k){
        swap(heap[ptr],heap[k]);
        if(ptr!=0)
        heapfix(heap,ptr,size);
    }
}
// 堆的操作主要有两个 堆插入和堆删除
int main(){
    int a=3,b=2;
    // int* heap = (int*)malloc(0x300);
    // int size = 30;
    // for(int i=0;i<size;i++){
    //     heap[i] = rand()%100;
    // }
    int heap[] = {1,1,3,4,1,2};
    int size = sizeof(heap)/4;
    //printf("%d")
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    for(int i=size/2;i>0;i--){
        heapfix(heap,i%size,size);
    }
    printf("heap %d\n",heap[1]);
    printf("%d \n",heap[1]);
    //1-30
    for(int i= 1;i < size ;i++){
        // 1 30
        // 2 29
        // 3 28
        // 4 27
        printf("a i %d %d \n",i,heap[1]);
        int temp = size-i;
        swap(heap[1],heap[temp]); //删除最后一个
        heapfix(heap,1,size-i);   //向下调整
       
    }
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");

    //free(heap);
    int c1=29,d1=29;
    swap(c1,d1);
    return 0;
}