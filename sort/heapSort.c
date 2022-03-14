#include<stdio.h>
#include<stdlib.h>
#define LEFT(a) 2 * a
#define RIGHT(a) 2 * a + 1

#define swap(x,y)   do{typeof(x) t;t=x;x=y;y=t;}while(0)
int* heapfix_old(int*heap ,int k ,int size){
    int left = LEFT(k);
    int right = RIGHT(k);
    int ptr = k;
    if(left<=size && heap[ptr] > heap[left%size]) ptr = left%size;
    if(right<=size && heap[ptr] > heap[right%size]) ptr = right%size;
    if(ptr!=k){
        swap(heap[ptr],heap[k]);
        if(ptr!=0)
        heapfix_old(heap,ptr,size);
    }
}
// 堆的操作主要有两个 堆插入和堆删除
// 比对结果输出
int heapfix(int* nums,int num,int numsSize,int k){
    int left = LEFT(num);
    int right = RIGHT(num);
    int ptr = num;
    if(left <= k && nums[left%numsSize] > nums[ptr]){
        ptr = left%numsSize;
    }
    if(right <= k && nums[right%numsSize] > nums[ptr]){
        ptr = right%numsSize;
    }
    if(ptr!=num){
        swap(nums[ptr],nums[num]);
        heapfix(nums,ptr,numsSize,k);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    for(int i=k/2;i>=0;i--){
        //for()
    }
}
int compare_find(){
    return 1;
}
#define LEFT(a) 2 * a

void test_maro(int k){
    printf("%d\n",LEFT(k+1));
}

int* heap_fix_compare(int* data,int k,int size){
    int left = LEFT(k);
    int right = RIGHT(k);
    int temp =  k;
    if(left <= size && data[left%size] < data[temp]){
        temp = left;
    }
    if(right <= size && data[right%size] < data[temp]){
        temp = right;
    }
    if(temp != k){
        swap(data[temp],data[k]);
        heap_fix_compare(data,temp,size);
    }
    //return data;
}

void quick_sort(int* data,int left,int right){

    if(left >= right) return;

    int temp = left;
    int p = left;
    int q = right - 1;
    // p 所处的位置，值应该是要小于等于标准值的
    while (p < q){
        printf("%d %d %d %d\n",p,q,data[p],data[q]);
        // p 的左侧都是比标准值小的数
        while(p<q && data[temp] <= data[q]) q--;
        while(p<q && data[temp] >= data[p]) p++;
        if(p<q){
            swap(data[p],data[q]);
        }
    
    }
    swap(data[p],data[temp]);
    quick_sort(data,temp,p);
    quick_sort(data,p+1,right);

}

int main(){
    int a=3,b=2;
    int heap[] = {5,2,3,1};
    quick_sort(heap,0,sizeof(heap)/4);
    int size = sizeof(heap)/4;
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    return 0;

    // printf("\n");
    // for(int i=size/2;i>0;i--){
    //     heapfix(heap,i%size,size);
    // }
    // printf("heap %d\n",heap[1]);
    // printf("%d \n",heap[1]);
    // for(int i= 1;i < size ;i++){
    //     printf("a i %d %d \n",i,heap[1]);
    //     int temp = size-i;
    //     swap(heap[1],heap[temp]); //删除最后一个
    //     heapfix(heap,1,size-i);   //向下调整
       
    // }
    // for(int i=0;i<size;i++){
    //     printf("%d ",heap[i]);
    // }
    // printf("\n");

    // //free(heap);
    // int c1=29,d1=29;
    // swap(c1,d1);
    return 0;
}