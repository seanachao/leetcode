// 核心思想是链表的置换
// 通过create 可以创建 n 个空间的链表

//每一次的get -> 如果该元素存在于链表中，则让该元素插入到节点末尾

//每一次的put 先检查该元素是否存在于该链表中，如果存在，则摘除该元素，并插入到节点末尾
// 如果不存在于链表中，则摘除第一个元素，并插入到节点末尾
// hash表中存储的是 key - 节点addr

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "uthash/uthash.h"
struct node{
    int key;
    int val;
    struct node* pre;
    struct node* next;

};
#define  Node struct node
typedef struct{
    int size;
    struct node* record;

    struct node* Cache;
} LRUCache;
struct LRUHash{
    int key;            /* we'll use this field as the key */
    Node* node;
    UT_hash_handle hh; /* makes this structure hashable */
};
struct LRUHash *lru_hash = NULL;


#define put_print(a,b,c){\
    lRUCachePut(a,b,c);\
    printf("the get value is NULL\n");\
    print_list(a->Cache);\
}
#define get_print(a,b){\
    printf("the get value is %d\n",lRUCacheGet(a,b));\
    print_list(a->Cache);\
}

void add_hash_node(int key,Node* ptr){
  
    struct LRUHash *s;
    s = (struct LRUHash*)malloc(sizeof(struct LRUHash));
    s->key = key;
    s->node  = ptr;
    //strcpy(s->name, name);
    HASH_ADD_INT(lru_hash, key, s);  /* id: name of key field */
}

struct LRUHash* find_hash_node(int key) {
    struct LRUHash *s;
    HASH_FIND_INT(lru_hash, &key, s);  /* s: output pointer */
    if(s)
        return s;
    return NULL;
}

void delete_hash(struct LRUHash *s) {
    if(s){
        HASH_DEL(lru_hash, s);  /* user: pointer to deletee */
        free(s);             /* optional; it's up to you! */
    }

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
Node* deleteNode(Node* node){
    Node* ptr = node;
    node->next->pre = node->pre;
    node->pre->next = node->next;
    return node;
}
void addNode(Node* node,Node* addnode){    
    addnode->next = node;
    addnode->pre = node->pre;    
    node->pre->next = addnode;
    node->pre = addnode;
}
int lRUCacheGet(LRUCache* obj, int key) {
    struct LRUHash* ptr = find_hash_node(key);
    Node* record = NULL;
    if(ptr){        
        record = deleteNode(ptr->node); 
        addNode(obj->Cache->pre,record);
        return record->val;
    }
    return -1;
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    struct LRUHash* ptr = find_hash_node(key);
    Node* record = NULL;
    if(ptr){        
        record = deleteNode(ptr->node);
        delete_hash(find_hash_node(record->key));
        record->val = value;
        record->key = key;
    }
    if(record==NULL){
        record = deleteNode(obj->Cache->next);
        delete_hash(find_hash_node(record->key));
        record->key = key;
        record->val = value;
    }
    addNode(obj->Cache->pre,record);
    add_hash_node(key,record);

}

LRUCache* lRUCacheCreate(int capacity){
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->size = 0;
    cache->Cache = (Node*)malloc(sizeof(Node));
    Node* ptr = cache->Cache;
    ptr->key = -1;
    ptr->pre = NULL;
    for(int i=1;i<=capacity+1;i++){
        ptr->next = (Node*)malloc(sizeof(Node));
        ptr->next->pre = ptr;
        ptr = ptr->next;
        ptr->key = -1;
        ptr->val = -1;
    }
    ptr->next = NULL;
    cache->Cache->pre = ptr;
    return cache;
}
void lRUCacheFree(LRUCache* obj) {
    Node* ptr = obj->Cache;
    while(ptr){
        Node* free_ptr = ptr;
        ptr= ptr->next;
        free(free_ptr);
    }
    struct LRUHash* q, *p;
    HASH_ITER(hh, lru_hash, p, q) {
        HASH_DEL(lru_hash, p);
        free(p);
    }
    free(obj);
}

int main(){
    // LRUCache* cache = lRUCacheCreate(10);
    // Node* ptr = cache->Cache;
    // for(int i=1;i<5;i++){
    //     add_hash_node(i,ptr);
    //     ptr = ptr->next;
    //     find_hash_node(i);
    // }
    //char opera[][10] = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    //int opera_num[][2] = {{10,0},{10,13},{3,17},{6,11},{10,5},{6,10},{13},{2,19},{2},{3},{10,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    char opera[][10] = {"LRUCache","put","put","get","put","put","get"};
    int opera_num[][2] ={{2},{2,1},{2,2},{2},{1,1},{4,1},{2}};
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