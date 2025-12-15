/*
  @pintia psid=1983726306003910656 pid=1983726499976073216 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第3次）
  Title: 二叉树的创建与遍历
  https://pintia.cn/problem-sets/1983726306003910656/exam/problems/type/7?problemSetProblemId=1983726499976073216
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

void visit(int v)
{
    printf("%d ", v);
}

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

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    visit(root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    visit(root->data);
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    visit(root->data);
}


int main()
{
    TreeNode *root = createBinTree();
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
// @pintia code=end