/*
  @pintia psid=1979022247370915840 pid=1980992649178566656 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 好后缀
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992649178566656
*/
// @pintia code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> longestRepeatingPrefix(const string& s) {
    int n = s.length();
    if (n == 0) return vector<int>();

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
    return next;
}

int longestRepeatingSuffix(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    vector<int>next = longestRepeatingPrefix(reversed);
    int maxLen = 0;
    for(int i =0;i<reversed.length();i++){
        maxLen = max(maxLen, next[i]);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << longestRepeatingSuffix(s) << endl;
    return 0;
}

// @pintia code=end