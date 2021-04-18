#include<stdio.h>

#include<stdlib.h>
#define bool int 

struct ListNode
{
    /* data */
    int val;
    struct ListNode *next;
};
struct ListNode* build_list(int a[],int len){
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = ptr;
    ptr->val = a[0];
    ptr->next = NULL;
    for(int i= 1;i<len;i++){
        ptr -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        ptr = ptr-> next;
        ptr->val = a[i];
        ptr->next = NULL;
    }
    return head;
}
void print_list(struct ListNode* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
struct ListNode* addTwoNumbersAdv(struct ListNode* l1, struct ListNode* l2){
    int a=0,b=0;
    int flag=0;
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = ptr;
    struct ListNode* tail = ptr;
    do{
        a = 0;b=0;
        if(l1!=NULL){
            a = l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL){
            b = l2->val;
            l2 = l2->next;
        }
        ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
        ptr->val = (a+b+flag) %10;
        flag = (a+b+flag) /10;
        ptr->next = NULL;
        tail -> next = ptr;
        tail = tail->next;
    }while(l1!=NULL || l2 !=NULL || flag !=0);
    return head->next;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int a=0,b=0;
    int flag=0;
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = ptr;
    ptr->next = NULL;
    ptr->val = 0;
    do{
        if( l1 == NULL){
            a = 0;
        }else{
            a = l1 -> val;
            l1 = l1-> next;
        }
        if(l2 == NULL){
            b = 0;
        }else{
            b = l2-> val;
            l2 = l2 -> next;
        }
        //printf("the a b is %d %d \n",a,b);
        ptr-> val =( a + b  + flag )%10;
        flag = (a+b+flag)/10;
        //printf("the flag is %d\n",flag);
        if(flag!=0 || l1!= NULL || l2!=NULL)
        ptr -> next = (struct ListNode*)malloc(sizeof(struct ListNode));;
        ptr = ptr -> next;

    }while(l1 !=NULL || l2 !=NULL || flag!=0);
    return head;
}
int main(){
    int array1[7] =  {9,9,9,9,9,9,9};
    int array2[4] =  {9,9,9,9};
    struct ListNode* l1 = build_list(array1,7);
    struct ListNode* l2 = build_list(array2,4);
    struct ListNode* l3 = addTwoNumbers(l1,l2);
    struct ListNode* l4 = addTwoNumbersAdv(l1,l2);
    print_list(l1);
    print_list(l2);
    print_list(l3);
    print_list(l4);
}
