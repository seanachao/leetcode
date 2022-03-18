#include<stdio.h>
#define bool int
#define false 0
#define true 1
bool istrue(char *p,char *s){
    return  *p== *s || *p == '.'; 

}
bool isNULL(char *p){
    return *p == '\0';
}
bool isMatch(char *s ,char* p){
    if(*s == *p || (*p== '.' && *s!='\0')){
        if(*p=='\0' && *s== '\0'){
            return true;
        }else if (isNULL(s)){
            return isMatch(s,p+1);
        }else if(isNULL(p)){
            return isMatch(s+1,p);
        }else if(*(p+1)=='*'){
            return isMatch(s+1,p+1) || isMatch(s,p+2);
        }else
            return isMatch(s+1,p+1);
    }else{
        if(isNULL(s)){
            if( *p== '*') return isMatch(s,p+1);
            else if(*(p+1) == '*') return isMatch(s,p+2);
            else return false;
        }else if(isNULL(p)){
                printf("eddd\n");
                return false;
        }else{
            if(*p=='*'){
                if(istrue(p-1,s)) return isMatch(s+1,p) || isMatch(s,p+1) || isMatch(s+1,p+1) ;  // 匹配到前者
                else return (isMatch(s,p+1) || isMatch(s-1,p+1));
            }else{
                if(*(p+1)=='*') return isMatch(s,p+2);
                else {printf("hell %c %c %c \n",*p,*(p+1),*s);return false;}
            }
        }
    }
}

int main(){
    char p[]="bbbba";
    //char q[]= ".*..a*";
    char q[] =".*a*a";
    printf("%d\n",isMatch(p,q));

}