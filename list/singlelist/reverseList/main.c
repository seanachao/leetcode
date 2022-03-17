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
 
void make_list(Node* list,int* list_put,int num){
    Node* ptr = list;
    for(int i=0; i<num; i++){
        Node* b = (Node*)malloc(sizeof(Node));
        b->val = list_put[i];
        b->next = NULL;
        ptr->next = b;
        ptr = b;
    }
    //return list;
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

#define ListNode node
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
void mergetwo(struct ListNode* head ,struct ListNode* list1,struct ListNode* list2){
    struct ListNode* up_ptr = list1;
    struct ListNode* down_ptr = list2;
    if (list1 == NULL || list2 == NULL){
        return;
    }
    if(up_ptr -> val >= down_ptr ->val){
        head -> next = down_ptr;
        down_ptr = down_ptr -> next;
        list2->next = up_ptr;
        head = head -> next;
    }else{
        //下面的比上面的大
        up_ptr = up_ptr -> next;
    }
    mergetwo(head,up_ptr,down_ptr);

}

void merge_two(struct ListNode* head,struct ListNode* list1,struct ListNode* list2){
    if(list1 == NULL){
        head -> next = list2;
        return;
    }
    if(list2 == NULL){
        head -> next = list1;
        return;
    }
    struct ListNode* up_ptr = list1;
    struct ListNode* down_ptr = list2;
    if(list1->val >= list2->val){
        head -> next = list2;
        head = head ->next;
        down_ptr = list2 -> next;
        list2 -> next = NULL;
    }else{
        head->next = list1;
        head = head->next;
        up_ptr = list1 -> next;
        list1 -> next = NULL;
    }
    merge_two(head,up_ptr,down_ptr);

}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    //printf("%d\n",list1->val);
    //return list1;
    struct ListNode* head = (struct ListNode*)malloc(sizeof *head);
    head -> next = NULL;
    struct ListNode* cur_head = head;
    //merge_tw0(cur_head,list1,list2);
    print_list(head);


}
/*
通过递归找到倒数第二个元素,记录下第一个head,并不断更新

*/
struct ListNode* reverse_com(struct ListNode* cur_tail,struct ListNode* head_ptr)
{
    if(cur_tail != NULL){
        reverse_com(cur_tail->next,head_ptr);
    }
};

struct ListNode* reverse(struct ListNode* cur_tail,struct ListNode* head_ptr){
    if(cur_tail->next != NULL){
        head_ptr = reverse(cur_tail->next,head_ptr);
        if(head_ptr->next != NULL && head_ptr != cur_tail){
            cur_tail ->next -> next = head_ptr->next; //尾部指向 head->next
            head_ptr->next = cur_tail->next;//head ->next -> cur
            head_ptr = cur_tail->next->next;//调整 head的位置
            cur_tail ->next = NULL;    //尾部变空
            if(head_ptr->next == cur_tail) head_ptr = head_ptr->next;
        }
    }
    return head_ptr;
}
// 1 2 3
void reorderList(struct ListNode* head){
    struct ListNode* head_ptr = NULL;
    head_ptr = head;
    reverse(head,head_ptr);
}
void two_reverse(){}
struct ListNode* swapPairs(struct ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        /*
        head  head1   head2
              tmp 
        */
       struct ListNode* tmp = head->next;
       head->next = tmp->next;
       tmp->next = head;
       head->next = swapPairs(head->next);
       return tmp;
}
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* tmp  = NULL;
    tmp = reverseList(head->next);
    head->next = head;
    head->next = NULL;
    return tmp;

}
struct ListNode* mer2list(struct ListNode* list1,struct ListNode* list2){


}
int main(){
    struct node* t1 = (struct node*)malloc(sizeof(struct node));
    t1->next = NULL;
    struct node* t2 = (struct node*)malloc(sizeof(struct node));
    t2->next = NULL;
    int l1[] = {1,2,3,4,5};
    //1 2 3 4 5 
    //1->5 2->3->4
    //1->5->2->4
    int l2[] = {1,3,4};
    make_list(t1,l1,sizeof(l1)/4);
    //make_list(t2,l2,sizeof(l1)/4);
    //print_list(t1 -> next);
    //print_list(t2 -> next);
    //mergeTwoLists(t1->next,t2->next);
    //Node* re_list = reverse_list(t);
    //print_list(re_list);
    //Node* n = recur_list(t);
    //t->next = NULL;
    //Node* n = reverse_list2(t);
    //Node* n = reverseKGroup(t->next,9);
    //print_list(n);
    //reorderList(t1->next);
    t1->next = swapPairs(t1->next);
    print_list(t1->next);

}