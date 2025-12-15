/*
  @pintia psid=1983726306003910656 pid=1983726499976073217 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第3次）
  Title: 二叉树查找结点及父结点
  https://pintia.cn/problem-sets/1983726306003910656/exam/problems/type/7?problemSetProblemId=1983726499976073217
*/
// @pintia code=start
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode *createBinTree()
{
    int k;
    scanf("%d",&k);
    if (k == 0)
        return NULL;
    TreeNode *root = new TreeNode(k);
    root->left = createBinTree();
    root->right = createBinTree();
    return root;
}

TreeNode* searchByVal(TreeNode* root,int k){
        if(root == NULL)
            return NULL;
        if(root->data == k)
            return root;
        TreeNode* ans = searchByVal(root->left,k);
        if(ans != NULL)
            return ans;
        return searchByVal(root->right,k);
    }

TreeNode* findParent(TreeNode* root, TreeNode* node) {
        if (root == NULL || node == root) {
            return NULL;
        }
        if (root->left == node || root->right == node) {
            return root;
        }
        TreeNode* ans = findParent(root->left, node);
        if (ans != NULL) {
            return ans;
        }
        return findParent(root->right, node);
    }


int main(){
    int m,k;

    TreeNode* root = createBinTree();

    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        scanf("%d",&k);
        TreeNode* res = NULL,*cmp = NULL;
        cmp = searchByVal(root,k);
        res=findParent(root,cmp);
        if (res != NULL && cmp != NULL) {
            printf("%d\n", res->data);
        } else {
            printf("0\n");
        }
    }
}
// @pintia code=end