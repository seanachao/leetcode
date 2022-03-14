#include<stdio.h>
#define swap1(a,b) {a=a+b;b=a-b;a=a-b;}
void swap(int*a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int* data,int left,int right){

    if(left >= right) return;

    int temp = left;
    int p = left;
    int q = right - 1;
    // p 所处的位置，值应该是要小于等于标准值的
    while (p < q){
        //printf("%d %d %d %d\n",p,q,data[p],data[q]);
        // p 的左侧都是比标准值小的数
        while(p<q && data[temp] <= data[q]) q--; 
        while(p<q && data[temp] >= data[p]) p++;
        if(p<q){
            swap(&data[p],&data[q]);
        }
    
    }
    swap(&data[p],&data[temp]);
    quick_sort(data,temp,p);
    quick_sort(data,p+1,right);

}
/*
堆排序，以大根堆为例子，堆顶是最大的数
保持每一个的子节点小于父节点
20 个数字里面选择 10 个最大的 小根堆
 3 4 5 6 7 8 9 10 11 12
 
 12 11 10 9 8 7 6 5 3

*/

//
void HeapFix(int* data, int cur,int num){
    //
    if(cur >= (num-1)/2) return; //2*cur + 1 >= num
    int left = cur *  2 + 1;
    int right = cur * 2 + 2;
    int temp = cur;
    if(data[left] > data[temp]) temp = left;
    if(data[right] > data[temp]) temp = right;
    if(temp!=cur) {
        swap(data[cur],data[temp]);
        HeapFix(data,temp,num);
    }
}
int main(){
    int heap[] = {-1,2,-8,-10};
    
    quick_sort(heap,0,sizeof(heap)/4);
    int size = sizeof(heap)/4;
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}