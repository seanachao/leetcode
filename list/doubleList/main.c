#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int val;
    int key;
    // 由于对齐的原因
    struct node* pre;
    struct node* next;

};

// 需要重写
#define Node struct node
#define put_print(a,b,c){\
    lRUCachePut(a,b,c);\
    print_list(cache->node);\
}
#define get_print(a,b){\
    lRUCacheGet(a,b);\
    print_list(a->node);\
}
void print_list(Node* list){
    Node* ptr = list;
    while( ptr != NULL ){
        printf(" %2d",ptr->key);
        ptr = ptr->next;

    }
    printf("\n");
    ptr = list;
    while( ptr != NULL ){
        printf(" %2d",ptr->val);
        ptr = ptr->next;

    }
    printf("\n");
}
typedef struct {
    struct node* record;
    struct node* node;
} LRUCache;
Node* put_node(Node* ptr,int key,int value){
    Node* record =  NULL;
    Node* head = ptr;
    ptr = ptr->next;
    while(ptr!=NULL){
        //printf("test\n");
        if(ptr->key == key ){ 
            ptr->val = value; 
            if(ptr->next == NULL) break;          
            ptr->pre->next = ptr->next;
            ptr->next->pre = ptr->pre;
            record = ptr;            
        }
        if(ptr->next == NULL){
            // 如果没有找到
            if(record==NULL){
                record = head->next;                                
                record->key = key;
                record->val = value;
                if(record != ptr){                    
                    // 删除头节点
                    head->next = head->next->next;
                    head-> next-> pre = head;
                    record->pre = ptr;
                    ptr->next = record;
                    record->next = NULL;
                }
            }else{
                ptr->next = record;
                record->pre = ptr;
                record->next = NULL;
            }           
            break;
        }       
        ptr = ptr->next;
    }
    return head;    
}
int get_Node(Node*ptr,int key){
    Node* head = ptr;
    Node* record = NULL;
    ptr = ptr->next;
    while(ptr){
        if(ptr->key == key && ptr->next != NULL){
            record = ptr;
            ptr->next->pre = ptr->pre;
            ptr->pre->next = ptr->next;
        }
        if(ptr->key == key && ptr->next == NULL){
            return ptr->val;
        }
        if(ptr->next==NULL && ptr->key!=key){
            if(record!=NULL){
                ptr->next = record;
                record->pre = ptr;
                record->next = NULL;
                return record->val;
            }
            return -1;
        }
        ptr = ptr->next;
    }
    return -1;
}
Node* build_list_node(int n){
    Node* head = NULL;
    Node* tail = NULL;
    Node* ptr = (Node*)malloc(sizeof(Node));
    Node* temp = NULL;
    head = ptr;
    head -> pre = NULL;
    head -> key = -1;
    head -> val = -1;
    for(int i=1; i<= n;i++){
        temp = (Node*)malloc(sizeof(Node));
        temp -> val = -1;
        temp -> key = -1;
        ptr -> next = temp;
        //ptr -> pre  = temp;
        temp -> next = NULL;
        temp -> pre = ptr;
        ptr = temp;
    }
    return head;
}
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* Lru = (LRUCache*)malloc(sizeof(LRUCache));
    Lru->node = build_list_node(capacity);
    return Lru;
}
int lRUCacheGet(LRUCache* obj, int key) {
    return get_Node(obj->node,key);
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    obj->node = put_node(obj->node,key,value);
}
void lRUCacheFree(LRUCache* obj) {

}
int main(){
    // LRUCache* cache = lRUCacheCreate(2);
    // print_list(cache->node);
    // create_print(cache,1,1);
    // create_print(cache,2,2);

    char opera[][10] = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    int opera_num[][2] = {{10,0},{10,13},{3,17},{6,11},{10,5},{6,10},{13},{2,19},{2},{3},{10,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    LRUCache* cache;
    for(int i=0;i<sizeof(opera_num)/8;i++){
        printf("%s %d %d\n",opera[i],opera_num[i][0],opera_num[i][1]);
        if(!strcmp(opera[i],"LRUCache")){
            cache = lRUCacheCreate(opera_num[i][0]);
        }
        if(!strcmp(opera[i],"put")){
            put_print(cache,opera_num[i][0],opera_num[i][1]);
        }
        if(!strcmp(opera[i],"get")){
            get_print(cache,opera_num[i][0]);
        }
    }
    


    return 0;
}