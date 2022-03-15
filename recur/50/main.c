#include<stdio.h> 
double myPow(double x, int n){
    if(n>=0){
        if (n & 1){
            if( x == 1) return 1;
            return myPow(x,n-1) * x;
        }
        if(n==2){
            return x*x;
        }
        if(n==0){
            return 1;
        }
        return myPow(x,n/2) * myPow(x,n/2);
    }else{
        return 1/myPow(x,-n);
    }
}
int main(){
    double x = 1.00000;
    int n = -2147483648;
    double res = 0.0;
    res = myPow(x,n);
    printf("%f\n",res);
    return 0;
}