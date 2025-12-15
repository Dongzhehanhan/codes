/*
  @pintia psid=1979022247370915840 pid=1979024667022970880 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 计算二叉树高度
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979024667022970880
*/
// @pintia code=start
#include <iostream>
using namespace std;
struct treeNode{
    treeNode* left;
    treeNode* right;
    int val;
    treeNode(int x):val(x),left(NULL),right(NULL){}
};

int calTreeHeight(treeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftSub=calTreeHeight(root->left);
    int rightSub=calTreeHeight(root->right);

    return max(leftSub,rightSub)+1;
}
int main(){
    int l,r,u;
    cin>>l,r,u;
    treeNode* root = new treeNode(u);
    root->left=new treeNode(l);
    root->right=new treeNode(r);
    int height =calTreeHeight(root);

    cout<<height<<endl;
    
    return 0;
}
// @pintia code=end