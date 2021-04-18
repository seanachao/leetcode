#include<stdio.h>
#include<vector>
using namespace std;

 struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define N 11
int root[11] = { 10,5,-3,3,2,NULL,11,3,-2,NULL,1};
struct TreeNode* treeNode;
void tree_build(int data[],struct TreeNode* tree){
    //2n+1 left,前序遍历，后序遍历，中序遍历
    //2n+2 right
    //traverse the binary
    // 1. 访问根节点 ，根节点入栈
    // 2. 访问栈顶元素，判断左子树是否为空 
    // 3. 如果左子树非空，左子树入栈，访问左子树,进入 1
    
    // 4. 如果为空，判断右子树是否存在，
    
    // 5. 如果右子树非空，右子树入栈,进入1
    // 6. 如果为右子树为空，弹栈，访问栈顶元素，弹出栈顶，访问右子树，
    // poi 代表遍历树的走向
    // stack 数组是栈
    vector<int> stack;
    stack.push_back(0);
    int value = -1;
    int pointer = 0 ;
    while (stack.size()!= 0){
        /* code */
        value = stack.back();
        printf("the value is %d \n", value );
        //break;
        if ( 2 * value +1 < N  && root[2 * value + 1] != NULL){
            //访问左子树
            stack.push_back(2 * value + 1);
        }else if(2 * value + 2 < N &&  root[ 2*value + 2 ] != NULL){
            stack.pop_back();
            stack.push_back(2 * value + 2);

        }else{
            stack.pop_back();
        }

    }
    
    

}
int pathSum(struct TreeNode* root,int sum){

}
int main(){
    printf("-----start------\n");
    tree_build(root,treeNode);
    return 0;
}