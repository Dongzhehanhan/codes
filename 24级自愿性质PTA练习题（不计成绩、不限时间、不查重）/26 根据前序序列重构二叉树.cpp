/*
  @pintia psid=1979022247370915840 pid=1979024681405947904 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 根据前序序列重构二叉树
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979024681405947904
*/
// @pintia code=start
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<string>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == "#") {
        index++;
        return nullptr;
    }

    // 将字符串转换为整数
    int val = stoi(preorder[index]);
    index++;
    
    TreeNode* node = new TreeNode(val);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);
    
    return node;
}


void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->val << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> preorder;
    string s;
    
    while (iss >> s) {//定义的字符流式输入对象向字符串s中输入数据
        preorder.push_back(s);//插入到s的末尾
    }
    
    // 构建二叉树
    int index = 0;
    TreeNode* root = buildTree(preorder, index);
    
    // 输出前序遍历结果
    preorderTraversal(root);
    
    return 0;
}
// @pintia code=end