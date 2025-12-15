/*
  @pintia psid=1986347732241879040 pid=1986347969814888450 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第4次）
  Title: ab间路径
  https://pintia.cn/problem-sets/1986347732241879040/exam/problems/type/7?problemSetProblemId=1986347969814888450
*/
// @pintia code=start

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int n) : val(n), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode *createBinTree()
{
    int k;
    cin >> k;
    if (k == 0)
        return NULL;
    TreeNode *root = new TreeNode(k);

    root->left = createBinTree();
    if (root->left != NULL)
    {
        root->left->parent = root;
    }

    root->right = createBinTree();
    if (root->right != NULL)
    {
        root->right->parent = root;
    }
    return root;
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

vector<int> getPath(TreeNode *p)
{
    vector<int> path;
    while (p != nullptr)
    {
        path.push_back(p->val);
        p = p->parent;
    }
    return path;
}

int main()
{
    TreeNode *root = createBinTree();
    int T;
    scanf("%d", &T);

    for (int m = 0; m < T; m++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        TreeNode *A = searchByVal(root, a);
        TreeNode *B = searchByVal(root, b);

        vector<int> pathA = getPath(A);
        vector<int> pathB = getPath(B);

        int i = pathA.size() - 1;
        int j = pathB.size() - 1;
        while (i >= 0 && j >= 0 && pathA[i] == pathB[j])
        {
            i--;j--;
        }
        int lca = pathA[i + 1];

        vector<int> pathBReversed;
        for (int k = 0; k <= j + 1; k++)
        {
            pathBReversed.push_back(pathB[k]);
        }
        reverse(pathBReversed.begin(), pathBReversed.end());

        vector<int> finalPath;
        
        for (int k = 0; k <= i + 1; k++)
        {
            finalPath.push_back(pathA[k]);
        }

        for (int k = 1; k < pathBReversed.size(); k++)
        {
            finalPath.push_back(pathBReversed[k]);
        }

        printf("%d\n", finalPath.size() - 1);
        for (int k = 0; k < finalPath.size(); k++)
        {
            printf("%d ", finalPath[k]);
        }
        printf("\n");
    }
    return 0;
}

// @pintia code=end