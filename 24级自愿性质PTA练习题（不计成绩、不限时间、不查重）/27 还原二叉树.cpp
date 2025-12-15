/*
  @pintia psid=1979022247370915840 pid=1979024695989538816 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 还原二叉树
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979024695989538816
*/
// @pintia code=start
#include <iostream>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : data(x), left(NULL), right(NULL) {}
};



int findRoot(char *inorder, int size, char val)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *buildTree(char *preorder, char *inorder, int n)
{
    if (n <= 0)
        return NULL;

    char roots = preorder[0];
    
    int k = findRoot(inorder, n, roots);
    if (k == -1)
        return NULL;

    TreeNode *right = buildTree(preorder + 1 + k, inorder + k + 1, n - k - 1);
    TreeNode *left = buildTree(preorder + 1, inorder, k);

    TreeNode *root = new TreeNode(roots);
    root->left = left;
    root->right = right;
    return root;
}



int getHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int main()
{
    int size = 0;
    string preorder, inorder;
    cin >> size;
    cin.ignore();  // Ignore the newline character after the size input
    getline(cin, preorder);
    getline(cin, inorder);

    bool isValid = true;

    TreeNode *root = buildTree(&preorder[0], &inorder[0], size);

            cout << getHeight(root) << endl;
    
}

// @pintia code=end