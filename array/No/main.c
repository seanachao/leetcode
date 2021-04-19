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
int heightTree(TreeNode* root){
    TreeNode* ptr = root;
    int height = 0;
    //通过层序遍历
    TreeNode** queue = (TreeNode**)malloc(0x10000);
    int head = -1,tail = -1,offset = -1;
    int last = 0;
    int level = 0;
    queue[++tail] = ptr;
    int record[100] = {};
    //record[++offset] = ptr->val;
    while(head < tail){

        //
        ptr = queue[++head];
        //printf("%d ",ptr->val);
        record[++offset]  = ptr->val;
        if(ptr->left) queue[++tail] = ptr->left;
        if(ptr->right) queue[++tail] = ptr->right;
        if(last == head){
            last = tail;
            level ++;
            for(int i=0;i<=offset;i++){
                printf("%2d ",record[i]);
            }
            printf("\n");
            offset = -1;
        }

    }
    //printf("%2d\n",level);
    return level;
}
int heightTreeRecur(TreeNode* root){
    if(!root) return 0;
    int a = heightTreeRecur(root->left);
    int b = heightTreeRecur(root->right);
    return a > b ? a + 1 : b + 1;
}
void levelOrdererTraversal(TreeNode* root){
    int h = heightTree(root);
    printf("%2d\n",h);

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
    // 前序遍历
    while(sp >= 0){ 
        if(tree_ptr  < size ){
            stack[++sp] = tree_ptr; 
            Nodestack[sp] = ptr;            
            //printf("%d\n",source[tree_ptr]);
            ptr->val = source[tree_ptr];//访问节点
            tree_ptr *= 2;
            if(tree_ptr < size) {//如果有左孩子的话
                TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
                ptr->left = node;
                ptr = ptr->left;
            }           
        }else{
            tree_ptr = stack[sp] * 2 + 1;
            if(tree_ptr < size && Nodestack[sp]){//如果有右孩子的话
                Nodestack[sp]->right = (TreeNode*)malloc(sizeof(TreeNode));
                ptr =Nodestack[sp]->right;
            }
            sp --;
            
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
    //levelOrdererTraversal(root);
    heightTree(root);
    return 0;
}