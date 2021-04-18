#include<stdio.h>
#include "uthash/uthash.h"
struct my_struct *users = NULL;    /* important! initialize to NULL */
struct my_struct {
    int id;                    /* key */
    char name[10];
    UT_hash_handle hh;         /* makes this structure hashable */
};
void add_user(int user_id, char *name) {
    struct my_struct *s;

    s = malloc(sizeof(struct my_struct));
    s->id = user_id;
    strcpy(s->name, name);
    HASH_ADD_INT(users, id, s);  /* id: name of key field */
}


// void edit_user(int user_id, char *name) {
//     struct my_struct *s;

//     s = malloc(sizeof(struct my_struct));
//     s->id = user_id;
//     strcpy(s->name, name);
//     HASH_REPLACE (users, id, s);  /* id: name of key field */
// }
struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT(users, &user_id, s);  /* s: output pointer */
    printf("%s\n",s->name);
    return s;
}
void delete_user(struct my_struct *user) {
    HASH_DEL(users, user);  /* user: pointer to deletee */
    free(user);             /* optional; it's up to you! */
}
int main(){
    add_user(1,"Tom");
    add_user(1,"dddd");
    find_user(1);
}