#include<stdio.h>

int maxArea(int* height, int heightSize){
    //取或者不取的问题
    int max_area = height[1]-height[0];
    int left = 0;
    int right = 1;
    for(int i=0;i<heightSize;i++){
        if((i-left)*(height[i]-height[left])> max_area){
            right = i;
        }
        if((i-right))
    }


}




int main(){
    int a[5] = {4,3,2,1,4};
    int n = 5;
    maxArea(a,n);
    return 0;
}