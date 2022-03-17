#include<stdio.h>
#define bool int
#define false 0
#define true 1
bool isMatch(char * s, char * p){

    if(*(s+1) =='\0' && (*s==*p|| *p=='*' || *p=='.')){
        return true;
    }

    //printf("start compare : %c%c\n",*s,*p);
    if(*p == *s || *p == '.'){
        //printf("start1 compare 1: %c %c\n",*s,*p);
        return isMatch(++s ,++p);
    }else if(*p != *s && *p != '*' && *(p+1)!='*'){
        return false;
    }else if(*p != *s && *(p+1)=='*'){
        p = p + 2;
        return isMatch(s,p);
    }
    else if(*p == '*' && (*s == *(p-1) || *(p-1) == '.')){
        return isMatch(++s,p);
    }else if(*p =='*' && *s != *(p-1) && *(p-1)!='.'){
        //return isMatch(++s,++p);
        return false;
    }else{
        return isMatch(++s,++p);
    }
    /*
    aababbbbbbbaaab
    .ab*aaab
    */
    
}
int main(){
    char p[]="aab";
    char q[]="c*a*b";
    printf("%d\n",isMatch(p,q));

}