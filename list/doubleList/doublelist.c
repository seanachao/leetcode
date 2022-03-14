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
    char name[10];
    Node* node;
    UT_hash_handle hh; /* makes this structure hashable */
};
struct LRUHash *lru_hash = NULL;


#define put_print(a,b,c){\
    lRUCachePut(a,b,c);\
    print_list(a->Cache);\
}
#define get_print(a,b){\
    printf("%d\n",lRUCacheGet(a,b));\
    print_list(a->Cache);\
}


void add_hash_node(int key,Node* ptr){
  
    struct LRUHash *s;
    s = malloc(sizeof(struct LRUHash));
    s->key = key;
    s->node  = ptr;
    //strcpy(s->name, name);
    HASH_ADD_INT(lru_hash, key, s);  /* id: name of key field */
}

Node* find_hash_node(int key) {
    struct LRUHash *s;

    HASH_FIND_INT(lru_hash, &key, s);  /* s: output pointer */
    if(s)
        printf("%d\n",s->node->val);
    return s->node;
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
Node* addNode(Node* node,Node* addnode){    
    addnode->next = node;
    addnode->pre = node->pre;    
    node->pre->next = addnode;
    node->pre = addnode;
}
int lRUCacheGet(LRUCache* obj, int key) {
    Node* ptr = obj->Cache;
    Node* record = NULL;
    while(ptr->next){
        ptr = ptr->next;
        if(ptr->key == key){
            record = deleteNode(ptr);
        }
    }
    if(record == NULL){
        return -1;
    }
    addNode(ptr,record);
    return record->val;
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* ptr = obj->Cache;
    Node* record = NULL;
    while(ptr->next){
        ptr = ptr->next;
        if(ptr->key == key){
            record = deleteNode(ptr);
            obj->size -= 1;
            record->val = value;
        }
    }
    if(record == NULL){
        record = deleteNode(obj->Cache->next);
        obj->size -=1;
        record->key = key;
        record->val = value;
    }
    addNode(ptr,record);
    obj->size += 1;
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
    ptr->next = NULL;h
    return cache;
}
void lRUCacheFree(LRUCache* obj) {

}
int main(){
    LRUCache* cache = lRUCacheCreate(10);
    Node* ptr = cache->Cache;
    for(int i=1;i<5;i++){
        add_hash_node(i,ptr);
        ptr = ptr->next;
        find_hash_node(i);
    }
    // char opera[][10] = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    // int opera_num[][2] = {{10,0},{10,13},{3,17},{6,11},{10,5},{6,10},{13},{2,19},{2},{3},{10,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    // LRUCache* cache;
    // for(int i=0;i<sizeof(opera_num)/8;i++){
    //     printf("%s %d %d\n",opera[i],opera_num[i][0],opera_num[i][1]);
    //     if(!strcmp(opera[i],"LRUCache")){
    //         cache = lRUCacheCreate(opera_num[i][0]);
    //     }
    //     if(!strcmp(opera[i],"put")){
    //         put_print(cache,opera_num[i][0],opera_num[i][1]);
    //     }
    //     if(!strcmp(opera[i],"get")){
    //         get_print(cache,opera_num[i][0]);
    //     }
    // }
    return 0;
}