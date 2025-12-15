/*
  @pintia psid=1986347732241879040 pid=1986347969814888449 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第4次）
  Title: 二叉树和等于某值路径
  https://pintia.cn/problem-sets/1986347732241879040/exam/problems/type/7?problemSetProblemId=1986347969814888449
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

TreeNode *createBinTree()
{
    int k;
    cin >> k;
    if (k == 0)
        return NULL;
    TreeNode *root = new TreeNode(k);
    root->left = createBinTree();
    root->right = createBinTree();
    return root;
}

void path(TreeNode *root, int value, vector<vector<int>> &res, vector<int> tmp, int sum)
{
    if (root == NULL)
        return;

    tmp.push_back(root->val);
    sum += root->val;

    if (root->left == NULL && root->right == NULL)
    {
        if (sum == value)
        {
            res.push_back(tmp);
        }
        return;
    }
    path(root->left, value, res, tmp, sum);
    path(root->right, value, res, tmp, sum);
}

int main()
{
    TreeNode *root = createBinTree();
    int value;
    scanf("%d", &value);

    vector<vector<int>> res;
    vector<int> tmp;
    path(root, value, res, tmp, 0);

    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// @pintia code=end