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
    for(int i=1;i<=10;i++){
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
算法设计:
思路，每次反转k个
start    记录初始节点
record   记录next节点
swap_ptr 指向当前反转节点
ptr 指向上一个节点
record 每次变化k-- k=1 的时候反转结束
start 指向 
*/

#define ListNode struct Node
Node* reverseKGroup(Node* head, int k){
    //确定头节点
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->next = head;
    Node* cur_ptr = head;
    Node* record = head->next;
    Node* swap_ptr = head->next;
    Node* end = NULL;
    Node* start_ptr = head;
    //Node* mid_ptr = ptr;
    int step = 1;
    int flag = 0;
    //反转前k个
    //统计后面是否有k个，如果有，则继续反转，但需要更新一些值
    //record始终记录下一个节点的值
    //start 始终记录起点的值
    //end记录终点的值
    while(record){
        //cur_ptr = record;
        while(record &&(step) < k){
            record = record->next;
            swap_ptr -> next = cur_ptr;
            cur_ptr = swap_ptr;
            swap_ptr = record;
            step++;
        }
        // 记录头节点
        if(flag == 0){
            ptr->next = cur_ptr;flag = 1;
        }
        // 找下一链表表尾部
        step = 1;
        end = record;
        while( end && step < k){
            end = end->next;
            step++;
        }
        step = 1;
        if(!end  && step < k){
            start_ptr->next = record;
            break;
        }
        start_ptr->next = end;
        start_ptr = record;
        cur_ptr = record; 
        record = record->next;
        swap_ptr = record;
    }
    return ptr->next;    
}

Node* reverseKGroup_recur(Node* head, int k){
//反转k 个链表返回头和尾
}
/*
一定要记录下一个指针
当前指针
下一个指针
链接
更新
*/
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
Node* reverse_list2(Node* list){
    //printf("%d\n",list->val);
    Node* ptr =  list;
    if(!list->next){
        return list;
    }
    
    Node* record_ptr = ptr->next;
    Node* swap_ptr = record_ptr;
    while(record_ptr){
        record_ptr = record_ptr->next;
        swap_ptr -> next = ptr;
        ptr = swap_ptr;
        swap_ptr = record_ptr;
    }
    list->next = NULL;
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
    //Node* n = recur_list(t);
    //t->next = NULL;
    //Node* n = reverse_list2(t);
    Node* n = reverseKGroup(t->next,9);
    print_list(n);

}