#include<stdio.h>
#define bool int
#define false 0
#define true 1
bool istrue(char *p,char *s){
    return  *p== *s || *p == '.'; 

}

bool isMatch(char * s, char * p){
    if(*(p+1)=='\0' && *(s+1) == '\0' && (istrue(p,s) ||(istrue(p-1,s) && *p=='*'))){
        return true;
    }else{
        if( *p == *s || *p == '.'){
            if(*(s+1)!='\0' && *(p+1)!='\0')
                return isMatch(s+1,p+1);
        }else if(*p != *s && *p == '*'){
            if( istrue(p-1,s) && istrue(p+1,s+1)){//后面一个也匹配到了
                if(*(s+1)!='\0' && *(p+1) !='\0')
                return isMatch(s+1,p+1);
            }else if(istrue(p-1,s) && !istrue(p+1,s+1)){
                /*前一个匹配到了，后一个没匹配到 */
                bool a=0,b=0;
                if(*(p+1)!='\0'){
                    a = isMatch(s,p+1);
                }
                if(*(s+1)!='\0'){
                    b = isMatch(s+1,p);// '\0' *
                }
                return a || b;
            }else if(!istrue(p-1,s)){
                if(*(p+1)!='\0')
                    return isMatch(s,p+1);
            }
        }else if(*p!=*s&&*(p+1)!='\0'&&*(p+1)=='*'){
            p++;
            printf("eee\n");
            if(*(p+1)!='\0')
            return isMatch(s,++p);
        }else{
            return false;
        }

    }
    return false;
}
int main(){
    char p[]="a";
    char q[]="ab*";
    printf("%d\n",isMatch(p,q));

}