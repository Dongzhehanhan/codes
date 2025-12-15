/*
  @pintia psid=1979022247370915840 pid=1983797166729805824 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 顺序存储的二叉树的最近的公共祖先问题
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1983797166729805824
*/
// @pintia code=start
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
    }
    int i, j;
    cin >> i >> j;
    
    if (tree[i - 1] == 0) {
        cout << "ERROR: T[" << i << "] is NULL" << endl;
        return 0;
    }
    if (tree[j - 1] == 0) {
        cout << "ERROR: T[" << j << "] is NULL" << endl;
        return 0;
    }
    
    int idx_i = i - 1;
    int idx_j = j - 1;
    
    while (idx_i != idx_j) {
        if (idx_i > idx_j) {
            idx_i = (idx_i - 1) / 2;
        } 
        else {
            idx_j = (idx_j - 1) / 2; 
        }
    }
    
    cout << idx_i + 1 << " " << tree[idx_i] << endl;
    
    return 0;
}
// @pintia code=end