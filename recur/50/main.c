#include<stdio.h> 
double myPow1(double x, int n){
     if (n == 0) {
            return 1.0;
        } else if ((n & 1) == 0) {
            return myPow1(x * x, n / 2);
        } else {
            return (n > 0 ? x : 1.0 / x) * myPow1(x * x, n / 2); 
        }
}
// x/2 /2 /2 /2  3/2 = 1 2/2 = 1 1/2 =0 
// -2/2 = -1
/*
2 ^ 4
myPow1(2*2 ,2)
myPow1(4*4 , 1)
myPow1()

x ^ n
n = -4 -> 1/(f(2)*f(2))
n = -3 -> 1/(f(2)*2)
n = -2 -> 1/(x*x)
n = -1 -> 1/x
n = 0 -> 1
n = 1 -> x
n = 2 -> f(1)*f(1)
n = 3 -> f(2) * x
n = 4 -> f(2) * f(2)
n = 5 -> f(4) * x
n = 6 -> f(3) * f(3)
n = 7 -> f(6) * x
*/
double myPow(double x, int n){
    printf("hello");
    if(n>=0){
        if (n & 1){
            //if( x == 1) return 1;
            return myPow(x*x,n/2) * x;
        }
        if(n==2){
            return x*x;
        }
        if(n==0){
            return 1;
        }
        return myPow(x*x,n/2);
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