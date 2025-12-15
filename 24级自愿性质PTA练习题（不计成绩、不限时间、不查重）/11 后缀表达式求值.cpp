/*
  @pintia psid=1979022247370915840 pid=1979023391691018240 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 后缀表达式求值
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979023391691018240
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int ERROR_RES = 1e9;

int calculate(const vector<string>& tokens, stack<int>& s) {
    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            s.push(stoi(token));
        } 
        else {
            if (s.size() < 2) {
                cout << "错误：表达式不规范。" << endl;
                return ERROR_RES;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int res;
            
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                if (b == 0) {
                    cout << "错误：除法操作分母为零。" << endl;
                    return ERROR_RES;
                }
                res = a / b;
            }
            else if (token == "%") {
                if (b == 0) {
                    cout << "错误：取模操作除数为零。" << endl;
                    return ERROR_RES;
                }
                res = a % b;
            }
            else {
                cout << "错误：表达式不规范。" << endl;
                return ERROR_RES;
            }
            s.push(res);
        }
    }

    if (s.size() != 1) {
        cout << "错误：表达式不规范。" << endl;
        return ERROR_RES;
    }
    return s.top();
}

int main() {
    string exp;
    getline(cin, exp); 
    istringstream iss(exp);
    vector<string> tokens;
    string token;
    while (iss >> token) { 
        tokens.push_back(token);
    }
    stack<int> s;
    int result = calculate(tokens, s);
    cout << result << endl;
    return 0;
}
// @pintia code=end