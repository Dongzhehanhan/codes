/*
  @pintia psid=1979022247370915840 pid=1980992557889536000 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 好中缀
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992557889536000
*/
// @pintia code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int secondLongestEqualPrefixSuffix(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    
    vector<int> next(n, 0);
    
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
    int longest = next[n - 1];
    if (longest == 0) return 0;
    
    return next[longest - 1];
}

int calculateX(const string& s) {
    int secondLen = secondLongestEqualPrefixSuffix(s);
    int qLen = max(0, (int)s.length() - 2 * secondLen);
    if(qLen < 0) qLen = 0;
    return qLen;
}

int main() {
    string s;
    cin >> s;
    cout << calculateX(s) << endl;
    return 0;
}
// @pintia code=end