#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr && right == nullptr) return nullptr; // 1.
        if(left == nullptr) return right; // 3.
        if(right == nullptr) return left; // 4.
        return root; // 2. if(left != null and right != null)
    }
};
//前序遍历
void preOrderer(TreeNode* root){
    if(!root) return;
    if(root->left){
        preOrderer(root->left);
    }
    printf("%d ",root->val);
    if(root->right){
        preOrderer(root->right);
    }
}
//后序遍历
//中序遍历
//层序遍历
void levelOrderer(TreeNode* root){
    TreeNode* ptr = root;
    TreeNode* queue[100] = {};
    int head =  -1;
    int tail =  -1;
    queue[++tail] = ptr;
    int level_sign = tail;
    //使用level_sign 标记每一层的最后一个元素

    while(head < tail){
        ptr = queue[++head];
        printf("%d ",ptr->val);
        if(ptr->left) queue[++tail] = ptr->left;
        if(ptr->right) queue[++tail] = ptr->right;
        //走到第二层的时候，会标记第二层的最后一个元素
        //依此类推
        if(level_sign == head){
            level_sign = tail;
            //one level
            printf("\n");
        }
    }

}
//前序遍历
// struct queue{
//     int data[100];
//     void* pop();
// }
//层序遍历
void levelTree(TreeNode* root){
    int head = 0;
    int tail = 0;
    //int a,b = -1,-1;
    TreeNode* queue[100] ={};
    queue[tail++] = root;
    while(head < tail){
        TreeNode* temp = queue[head++];
        printf("%d ",temp->val);
        if(temp->left != NULL){
            queue[tail++] = temp->left;
        }
        if(temp->right != NULL){
            queue[tail++] = temp->right;
        }
    }
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
/*
1 2 3 4 5 6 7
       0
   1       2     
3    4   5  6 
2n+1 
2n+2
 
*/
TreeNode* getTree(int* source,int size){
    TreeNode* treenodes = (TreeNode*)malloc(sizeof(TreeNode)*size);
    //最低的两个等级关系运算符， 最后是与或 ，条件操作符，赋值
    printf("the size is %d\n",size);
    for(int i=0;i<size;i++){
        if(source[i] != NULL && i <= size-1 >> 1){
            if(2*i +1 < size && source[2*i + 1] != NULL)
            treenodes[i].left = &treenodes[2*i + 1];
            if(2*i+2<size  && source[2*i + 2] != NULL)
            treenodes[i].right = &treenodes[2*i + 2];
            treenodes[i].val = source[i];
        
        }else{
            treenodes[i].left = NULL;
            treenodes[i].right = NULL;
            treenodes[i].val = source[i];
        }
    }
    return treenodes;
}
    vector<vector<int>> levelOrderTest(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;
        res.push_back(vector<int>{});
        TreeNode* queues[100] = {};
        int head = -1, tail = -1;
        queues[++tail] = root;
        int level_sign = tail;
        int level = 0,poi = 0;
        while(head < tail){
            TreeNode* temp = queues[++head];
            if(temp->val)
                res[level].push_back(temp->val);
            if(temp->left) queues[++tail] = temp->left;
            if(temp->right) queues[++tail] = temp->right;
            if(head == level_sign){
                level_sign = tail;
                level ++ ;
                res.push_back(vector<int>{});
            }
        }
        if(head == level_sign)
            res.pop_back();
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                printf("%d ",res[i].at(j));
            }
            printf("\n");
        }
        return res;
    }
int main(){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    //st->add = 
    // NULL
    int a[13] = {3,5,1,6,2,7,8,4,5,7,4};
    TreeNode*root = getTree(a,sizeof(a)/4);

    levelOrderer(root);
    
    levelOrderTest(root);
    preOrderer(root);
    int k = 0;
    if(k== NULL) printf("The K is NULL\n");
    
    return 0;
}