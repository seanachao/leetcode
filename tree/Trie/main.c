#include<stdio.h>
#include<string.h>
#define bool int
#define false 0
#define true 1
typedef struct Trie{
    Trie* children[26];
    bool isEnd;
} Trie;
Trie* trieCreate() {
    Trie* newTrie = (Trie*)malloc(sizeof(Trie));
    newTrie->isEnd = false;
    return newTrie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int word_len = strlen(word);
    for(int i=0;i<word_len;i++){
        int poi = word[i]-'a';
        if(obj->children[poi]!=NULL){
            obj->children[poi] = trieCreate();
           
        }
        obj = obj->children[poi];
    }
    obj-> isEnd = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
  
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
  
}

void trieFree(Trie* obj) {
    
}
int main(){
    char* trin_data[26] = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    
    
    return 0;
}