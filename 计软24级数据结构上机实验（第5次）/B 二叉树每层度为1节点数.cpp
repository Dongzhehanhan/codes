/*
  @pintia psid=1988824816654635008 pid=1988825531288539136 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第5次）
  Title: 二叉树每层度为1节点数
  https://pintia.cn/problem-sets/1988824816654635008/exam/problems/type/7?problemSetProblemId=1988825531288539136
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : data(x), left(NULL), right(NULL) {}
};

TreeNode *createBinTree()
{
    char ch;
    cin >> ch;
    if (ch == '#')
        return NULL;
    TreeNode *root = new TreeNode(ch);
    root->left = createBinTree();
    root->right = createBinTree();
    return root;
}


void levelOrderCounting(TreeNode *root)
{
    if(root == NULL)
    {
        printf("0\n");
        return;
    }

    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int levelCount = Q.size();
        int count = 0;
        for (int i = 0; i < levelCount; i++)
        {
            TreeNode *p = Q.front();
            Q.pop();
            if ((p->left == NULL) != (p->right == NULL))
                count += 1;
            if (p->left != NULL)
                Q.push(p->left);
            if (p->right != NULL)
                Q.push(p->right);
        }
        printf("%d\n", count);
    }
}



int main()
{
    TreeNode *root = createBinTree();
    if (root == NULL)
    {
        printf("0\n");
        return 0;
    }
    levelOrderCounting(root);

    return 0;
}

// @pintia code=end