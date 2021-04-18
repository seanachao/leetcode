#include<stdio.h>
#include<stdlib.h>
#define heapSize 0x300
#define LEFT(root) root*2
#define RIGHT(root) root*2+1
// 第k大的数字，那么下面的数字都比顶部的大
#define swap(a,b) do{a^=b;b^=a;a^=b;}while(0)
void heapfix(int* heap,int ptr,int k,int numsSize){
    int left = LEFT(ptr);
    int right = RIGHT(ptr);
    int swap_ptr = ptr;
    if(left <= k && heap[left%numsSize] < heap[ptr]){       
        swap_ptr = left%numsSize;
    }
    if(right <=  k && heap[right%numsSize] < heap[swap_ptr]){
        swap_ptr = right%numsSize;
    }
    if(swap_ptr != ptr){
        swap(heap[swap_ptr],heap[ptr]);
        if(swap_ptr !=0){
            heapfix(heap,swap_ptr,k,numsSize);
        }
    }

}
int findKthLargest(int* heap,int numsSize,int k){

    if(numsSize<=1) return heap[0];
    //构造大小为k的堆
    for(int i=k/2;i>0;i--){
        heapfix(heap,i,k,numsSize);
    }
    // 2 1 2
    // 首元素已经在树里了
    for(int i = k+1; i <= numsSize ;i++){
        if(heap[1] < heap[i%numsSize]){
            swap(heap[1] ,heap[i%numsSize]);
            heapfix(heap,1,k,numsSize);
        }
    }
    printf("%d\n",heap[1]);
    return heap[1];

}
int main(){
    
    int nums[] = {2,1};
    int k = 1;
    findKthLargest(nums,sizeof(nums)/sizeof(int),k);
    return 0;
}