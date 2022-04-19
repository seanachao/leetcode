#include<stdio.h>
#define bool int
#define false 0
#define true 1
bool find(int,char*,char*);
bool istrue(char *p,char *s){
    return  *p== *s || (*p == '.' && *s!='\0'); 

}
bool isNULL(char *p){
    return *p == '\0';
}
int isSame(char*s ,char*p){
    if (*p == *s || (*p == '.' && *s != '\0')){
        /*
        a
        a*
        ab
        ab
        */
        if(*(p+1) == '*') {printf("h\n");return 6;} //(s,p+2) || (s+1,p+1)
        else return 3;// (s+1,p+1) 
    }else if(*p == '*' && istrue(p-1,s)){
        /*
        aa
        a*
        */
        return 4;//(s+1,p) || (s,p+1) || (s+1,p+1)
    }else if(*p=='*' && *(p-1)!=*s){
        /*
        ba
        b*a
        */
        return 1; //(s,p+1)
    }else if(*p!='*' && *(p+1)=='*'){
        /*
        a
        c*
        */
        return 5;//(s,p+2);
    }else{
        return false;
    }
    
}
bool isMatch(char *s ,char* p){
    int jmp_table = 0;
    if(isNULL(s) && isNULL(p)){
        return true;//保证前面的都匹配到了
    }else if(isNULL(s)){
        /* 
        a
        a*.
        */
        jmp_table = isSame(s,p);
        if(jmp_table > 0) return isMatch(s,p+1);
        else return false;
        //(s,p+2)
    }else if(isNULL(p)){
        return false;
    }else{
        jmp_table = isSame(s,p);
        return find(jmp_table,s,p);
    }
}
bool find( int t,char* s, char* p){
    switch (t)
    {
    case 1:
        return isMatch(s,p+1);
    case 2:
        return isMatch(s+1,p);
    case 3:
        return isMatch(s+1,p+1); 
    case 4:
        return isMatch(s,p+1) || isMatch(s+1,p) || isMatch(s+1,p+1);
    case 5:
        return isMatch(s,p+2);
    case 6:
        return isMatch(s,p+2) || isMatch(s+1,p+1);
    default:
        return false;
        break;
    }
}
// bool isMatch(char *s ,char* p){
//     if(*s == *p || (*p== '.' && *s!='\0')){
//         if(*p=='\0' && *s== '\0'){
//             return true;
//         }else if (isNULL(s)){
//             return isMatch(s,p+1);
//         }else if(isNULL(p)){
//             return isMatch(s+1,p);
//         }else if(*(p+1)=='*'){
//             return isMatch(s+1,p+1) || isMatch(s,p+2);
//         }else
//             return isMatch(s+1,p+1);
//     }else{
//         if(isNULL(s)){
//             if( *p== '*') return isMatch(s,p+1);
//             else if(*(p+1) == '*') return isMatch(s,p+2);
//             else return false;
//         }else if(isNULL(p)){
//                 printf("eddd\n");
//                 return false;
//         }else{
//             if(*p=='*'){
//                 if(istrue(p-1,s)) return isMatch(s+1,p) || isMatch(s,p+1) || isMatch(s+1,p+1) ;  // 匹配到前者
//                 else return isMatch(s,p+1) || isMatch(s-1,p+1);
//             }else{
//                 if(*(p+1)=='*') return isMatch(s,p+2);
//                 else {return false;}
//             }
//         }
//     }
// }


int main(){
    char p[]="ab";
    char q[] =".*";
    printf("%d\n",isMatch(p,q));

}