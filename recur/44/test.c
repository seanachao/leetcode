#include<stdio.h>
int test(){
    return 0 ;
}
int test1(){
    return 1 ;
}
int zuhe(){
    return test() || test1();

}
int main(){
    printf("%d\n",zuhe());
}