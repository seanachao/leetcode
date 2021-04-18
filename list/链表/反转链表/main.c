#include<stdio.h>
#include<stdlib.h>
// 通过双指针解决问题
// 一共分四步
// 记录下一个待处理节点的指针 record_ptr
// 指向下一个节点节点的指针   next_ptr
// 当前节点的指针           ptr
/*
    next_ptr = record_ptr;
    record_ptr = record_ptr -> next;
    next_ptr -> next = ptr;
    ptr  = next_ptr;
*/
struct node{
    int val;
    struct node*  next;
};
#define Node struct node
Node* revese_list(Node* ptr){
    if(ptr->next == NULL) return ptr;
    Node* record = revese_list(ptr->next);
    record -> next = ptr;
    return record;
}
 
Node* make_list(Node* list){
    Node* ptr = list;
    for(int i=0;i<10;i++){
        Node* b = (Node*)malloc(sizeof(Node));
        b->val = i;
        b->next = NULL;
        ptr->next = b;
        ptr = b;
    }
    return list;
}
void print_list(Node* list){
    Node* ptr = list;
    while( ptr  !=NULL ){
        printf("the value is %d\n",ptr->val);
        ptr = ptr->next;

    }
    
}
/*
一定要记录下一个指针
当前指针
下一个指针
链接
更新
*/
#define ListNode struct Node
Node* reverseList(Node* head){
    Node* ptr = head;
    if(head==NULL) return head;
    Node* record_ptr = ptr->next;

    Node* next_ptr = NULL;
    while(record_ptr){
        next_ptr = record_ptr;
        record_ptr = record_ptr -> next;
        next_ptr -> next = ptr;
        ptr = next_ptr;
    }
    head->next = NULL;
    return ptr;
}

Node* recur_list(Node* list){
    if(list->next == NULL ){
        return list;
    }
    Node* head = recur_list(list->next);
    list->next ->next = list;
    return head;
}
Node* reverse_list(Node* list){
    Node* ptr = list->next;    
    Node* record_ptr = ptr->next;
    Node* next_ptr = NULL;
    //双指针
    while(record_ptr){
        next_ptr = record_ptr;
        record_ptr = record_ptr ->next;
        next_ptr -> next = ptr;     
        ptr = next_ptr;            
    }
    list->next->next = NULL;
    return ptr;

}
int func(void){
    static int counter = 1;
    return ++counter;
}
int main(){

    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->next = NULL;
    t = make_list(t);
    //print_list(t);
    //Node* re_list = reverse_list(t);
    //print_list(re_list);
    Node* n = recur_list(t);
    t->next = NULL;
    print_list(n);

}