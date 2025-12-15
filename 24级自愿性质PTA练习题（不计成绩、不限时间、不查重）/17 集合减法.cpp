/*
  @pintia psid=1979022247370915840 pid=1980992245866868736 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 集合减法
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992245866868736
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> B(m);
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }
    
    vector<int> result;
    
    for(int x : A) {
        if (!binary_search(B.begin(), B.end(), x)) {
            result.push_back(x);
        }
    }
      
    if (result.empty()) {
        cout << "0";
    } else {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i]<< " ";
        }
        cout << "\n";
    }
    
    return 0;
}

// @pintia code=end