#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

};
struct stack{
    int len;
    int ptr;
    int(*add)(int val);
};
#define Stack struct stack
#define TreeNode struct TreeNode
int** levelOrderer(TreeNode* root,int* returnSize,int** returnColumnSizes){


}
void preTraveTree(TreeNode* root){
    TreeNode* ptr = root;
    if(ptr) printf("%d \n",ptr->val);
    if(ptr->left){
        preTraveTree(ptr->left);
    }
    if(ptr->right){
        preTraveTree(ptr->right);
    }

}
TreeNode* buildTree(int* source,int size){
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* ptr = root;
    
    //通过迭代遍历树
    int stack[15] = {0};

    int sp = 0;
    int tree_ptr = 1;
    TreeNode* Nodestack[15] = {};
    //stack[++sp] = tree_ptr;
    ptr -> val = source[tree_ptr];
    Nodestack[sp] = ptr;
    while(sp >= 0){ 
        if(tree_ptr  < size ){
            stack[++sp] = tree_ptr; 
            printf("%d\n",source[tree_ptr]);
            tree_ptr *=2;

        }else{
            tree_ptr = stack[sp--] * 2 + 1;
        }
        

    }
    return root;
}
#define null NULL
int main(){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    //st->add = 
    int a[] = {0,1,2,3,4,5,6,7,8};
    TreeNode*root = buildTree(a,sizeof(a)/4);
    //preTraveTree(root);
    return 0;
}