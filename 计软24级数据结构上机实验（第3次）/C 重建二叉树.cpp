/*
  @pintia psid=1983726306003910656 pid=1983727478804975616 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第3次）
  Title: 重建二叉树
  https://pintia.cn/problem-sets/1983726306003910656/exam/problems/type/7?problemSetProblemId=1983727478804975616
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

void preOrder(TreeNode *root, string &res)
{
    if (root == NULL)
        return;
    
    res += root->data;
    preOrder(root->left, res);
    preOrder(root->right, res);
}

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

TreeNode *buildTree(char *inorder, char *postorder, int n, bool &isValid)
{
    if (n <= 0)
        return NULL;

    char roots = postorder[n - 1];
    
    int k = findRoot(inorder, n, roots);
    if (k == -1)
    {
        isValid = false;
        return NULL;
    }

    TreeNode *right = buildTree(inorder + k + 1, postorder + k, n - k - 1, isValid);
    TreeNode *left = buildTree(inorder, postorder, k, isValid);

    if ((k > 0 && left == NULL) || (n - k - 1 > 0 && right == NULL)) {
        isValid = false;
        return NULL;
    }

    TreeNode *root = new TreeNode(roots);
    root->left = left;
    root->right = right;
    return root;
}



int getHeight(TreeNode *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int main()
{
    int height = 0;
    string inorder, postorder;
    while (getline(cin, postorder) && getline(cin, inorder))
    {
        bool isValid = true;
        
        TreeNode *root = buildTree(&inorder[0], &postorder[0], inorder.size(), isValid);

        if (!isValid || root == NULL)
        {
            cout << "INVALID" << endl;
        }
        else
        {
            cout << getHeight(root) << endl;
            string result;
            preOrder(root, result);
            cout << result << endl;
        }
    }
}


// @pintia code=end