#include "../uthash.h"
#include<stdio.h>
#define false 0
#define true 1
#define Bool int
struct hash_entry {
    int id;
    int length;
    UT_hash_handle hh;
};
struct hash_entry* nums = NULL;
void add_num(int num,int len){
    struct hash_entry* s = NULL;
    HASH_FIND_INT(nums,&num,s);
    if(s == NULL){
        s = (struct hash_entry*)malloc(sizeof *s);
        s->id = num;
        s->length = len;
        HASH_ADD_INT(nums,id,s);
    }
}
struct hash_entry* find_num(int num){
    struct hash_entry* s = NULL;
    HASH_FIND_INT(nums,&num,s);
    if(s == NULL){
        return NULL;
    }
    return s;
}
void delte_num(int num){
    struct hash_entry* s = NULL;
    HASH_FIND_INT(nums,&num,s);
    if(s != NULL){
        HASH_DEL(nums,s);
    }else{
        printf("NOT FOUND DELETE NUM!\n");
    }
}
int longestConsecutive(int* inputs, int numsSize){
    //for(int i=0;i<numsSize;i++){
    //    add_num(inputs[i]);
    //}
    //nums
    int max_length = -1;
    for(int i=0;i<numsSize;i++){
        struct hash_entry* s = find_num(inputs[i]);
        if(!s){
            struct hash_entry* s_l = find_num(inputs[i] - 1);
            struct hash_entry* s_r = find_num(inputs[i] + 1);
            int left = s_l == NULL ? 0 : s_l -> length;
            int right = s_r == NULL ? 0 : s_r -> length;
            int cur_length = 1 + left + right;
            if (cur_length > max_length) max_length = cur_length;

            s->length = cur_length;
            s_l = find_num(inputs[i]-left);
            if(s_l) s_l -> length = cur_length; else add_num(inputs[i] - left ,cur_length);
            s_r = find_num(inputs[i]-left);
            if(s_r) s_r -> length = cur_length; else add_num(inputs[i] - right, cur_length);

        }
    }
    return max_length;
}
int main(){
    int input[] = {0,3,7,2,5,8,4,6,0,1};
    int res = longestConsecutive(input,sizeof(input)/4);
    printf("the longest is %d\n",res);
    return 0;
}