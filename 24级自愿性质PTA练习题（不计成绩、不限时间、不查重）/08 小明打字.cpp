/*
  @pintia psid=1979022247370915840 pid=1980991924822306816 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 小明打字
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980991924822306816
*/
// @pintia code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string edit(string &input)
{
    stack<char> left, right;
    bool insert = true;

    for (char c : input)
    {
        switch (c)
        {
        case '[': // home
            while (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
            break;

        case ']': // end
            while (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
            break;

        case '{': // ←
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
            break;

        case '}': // →

            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
            break;

        case '-': // insert
            insert = !insert;
            break;

        case '=': // backspace
            if (!left.empty())
                left.pop();
            break;

        default: // input characters
            if (insert)
                left.push(c);
            else
            {
                if (!right.empty())
                {
                    right.pop();
                }
                left.push(c);
            }
            break;
        }
    }

    while (!right.empty())
    {
        left.push(right.top());
        right.pop();
    }

    string result;
    while (!left.empty())
    {
        result = left.top() + result;
        left.pop();
    }

    return result;
}

int main()
{
    string input;
    getline(cin, input);
    cout << edit(input);
    return 0;
}
// @pintia code=end