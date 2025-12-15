/*
  @pintia psid=1979022247370915840 pid=1980995657295687680 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 表达式转换
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980995657295687680
*/
// @pintia code=start
#include <iostream>
#include <cassert>
#include <string>
#include <stack>
using namespace std;
string readnum(const string &s, int &i) {
    string num;
    while (i < s.size() && isdigit(s[i])) {
        num += s[i];
        ++i;
    }
    --i;
    return num;
}


string transform(string s){
    stack<char> OP;
    string res;
    int n = s.size();
    int p[128] = { 0 };
    p['+'] = p['-'] = 1; p['*'] = p['/'] = 2;
    for (int i = 0; i < n; i++) {
        if(s[i] == ' ') continue;

        if (isdigit(s[i])) {
            res += readnum(s, i);
            res += ' ';
        }
        else if (s[i] == '(') {
            OP.push(s[i]);
        }
        else if (s[i] == ')') {
            while (OP.top() != '(') {
                res += OP.top();
                res += ' ';
                OP.pop();
            }
            OP.pop();// 弹出左括号
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (!OP.empty() && OP.top() != '(' && p[OP.top()] >= p[s[i]]) {
                res += OP.top();
                res += ' ';
                OP.pop();
            }
            OP.push(s[i]);
        }
    }
    while (!OP.empty()) {
        res += OP.top();
        int n = OP.size();
        if(n!=1){
            res += ' ';
        }
        OP.pop();
    }
    return res;
}

int main() {
	string exp;
	getline(cin, exp);
	cout << transform(exp) << endl;
	return 0;
}
// @pintia code=end