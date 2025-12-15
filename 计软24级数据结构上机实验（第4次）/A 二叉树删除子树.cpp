/*
  @pintia psid=1986347732241879040 pid=1986347969814888448 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第4次）
  Title: 二叉树删除子树
  https://pintia.cn/problem-sets/1986347732241879040/exam/problems/type/7?problemSetProblemId=1986347969814888448
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createBinTree()
{
    int k;
    cin >> k;
    if (k == 0)
        return nullptr;
    TreeNode *root = new TreeNode(k);
    root->left = createBinTree();
    root->right = createBinTree();
    return root;
}

void delTree(TreeNode *&root)
{
    if (root == nullptr)
        return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
}

bool delSubTree(TreeNode *&root, TreeNode *p)
{
    if (root == nullptr || p == nullptr)
        return false;
    if (root == p)
    {
        delTree(root);
        return true;
    }
    if (delSubTree(root->left, p))
        return true;
    return delSubTree(root->right, p);
}

TreeNode *searchByVal(TreeNode *root, int k)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == k)
        return root;
    TreeNode *ans = searchByVal(root->left, k);
    if (ans != nullptr)
        return ans;
    return searchByVal(root->right, k);
}

void inOrder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}

int main()
{
    TreeNode *root = createBinTree();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        bool flag;
        int val;
        scanf("%d", &val);
        TreeNode *p = searchByVal(root, val);
        flag = delSubTree(root, p);
        if (flag)
        {
            vector<int> res;
            inOrder(root, res);
            for (int i = 0; i < res.size(); i++)
            {
                printf("%d ", res[i]);
            }
            printf("\n");
        }
        else
        {
            printf("0\n");
            continue;
        }
    }

    return 0;
}
// @pintia code=end