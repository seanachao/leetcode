#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0 
bool isNULL(char *p){
    return *p == '\0';
}
bool is_match(char *s,char *p){
    /*
    a  a   a
    a  ?   *
    */
    if(*p == *s || *p == '?'){
        return 1;//(s+1,p+1)
    }else if(*p == '*'){
        return 2;//(s,p+1) || (s+1,p) || (s+1,p+1)
    }else{
        return false;
    }

}
bool isMatch2(char * s, char * p){
    //printf("enter %c %c\n",*s,*p);
    if(isNULL(s)&& isNULL(p)){
        return true;
    }else if(isNULL(s) && *p=='*'){
        // s="" p="*"
        return isMatch2(s,p+1);
    }else if(isNULL(s) && *p!='*'){
        return false;
    }else if(isNULL(p)){
        //s='a' p=""
        return false;
    }else{
        //printf(" %c =? %c\n",*s,*p);
        if(*p == *s || *p == '?'){
            return isMatch2(s+1,p+1);//(s+1,p+1)
        }else if(*p == '*'){
                    // c  c            d  *                   d c
            //printf("*p %c %c\n",*s,*p);
            while(*(p+1)=='*') p++;
            return  (isMatch2(s,p+1) || isMatch2(s+1,p));
            
        }else{
            //printf(" %c =? %c\n",*s,*p);
            return false;
        }
    }
}
int get_length(char* p){
    int i = 0;
    while (*(i+p)!='\0') i++;
    return i;
}
/*
0 1 2 3
4 5 6 7

k/src_len=hor
k%src_len=col
*/
#include<strings.h>
bool isMatch(char* s,char* p){
    int src_len = get_length(s);
    int pat_len = get_length(p); 
    pat_len = pat_len + 1;
    src_len = src_len + 1;
    printf("%d %d\n",src_len,pat_len);
    char** k = (char**)malloc((pat_len) * sizeof(char*));
    int i = 0,j=0;
    while(i<pat_len) {*(k+i) = (char*)malloc(src_len+2);memset(*(k+i),'P',src_len);i++;}
    
    k[0][0] = 'T';
    
    for(i=0;i<pat_len-1;i++){
        for(j=0;j<src_len;j++){
            printf("i j %d %d\n",i,j);
            if(k[i][j] == 'T' && (*(s+j) == *(p+i) || *(p+i)=='?') ){
                k[i+1][j+1] = 'T';
            }else if(  (*(p+i)=='*') && k[i][j] == 'T' ){
                printf("eee\n");
                k[i][j] = 'T';
                k[i][j+1] = 'T';
                k[i+1][j+1] = 'T';
                k[i+1][j] = 'T';
            }else{
                k[i][j] = 'x';
            }

        }
    }
    
   
    // printf("  ");
    // for (j=0;j<src_len;j++){
    //     printf("%c ",*(s+j));
    // }
    // printf("\n");
    // for(i=0;i<pat_len;i++){
    //     printf("%c " ,*(p+i));
    //     for(int j=0;j<src_len;j++){
    //         printf("%c ",k[i][j]);
    //     }
    //     printf("\n");
    // }
    //if((*(p+pat_len-1) == *(s+src_len-1) || *(p+pat_len-1)=='?' || *(p+pat_len-1)=='*') && (k[pat_len-1][src_len-1]=='T')){
    //    return true;

    //}
    if(k[pat_len-1][src_len-1] == 'T') return true;
    return false;
    

}
int main(){
    //char p[]="adceb";
    //char q[]="*a*b";
    //char p[]="aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaabab";
    //char q[]="a*********b";
    //  a a b b b b b c
    //a
    //*   T T T T T T T
    //c
    //char p[] = "aa";
    //char q[] = "a";
    char*p = "aa";
    char*q = "*";
    printf("%d\n",isMatch(p,q));

}