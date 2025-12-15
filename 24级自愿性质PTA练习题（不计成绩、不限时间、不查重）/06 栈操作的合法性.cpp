/*
  @pintia psid=1979022247370915840 pid=1979023657848295424 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 栈操作的合法性
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979023657848295424
*/
// @pintia code=start
#include <stack>
#include <iostream>
using namespace std;

int stackJudge(string command, const int &maxSize)
{
    stack<char> s;
    int count = 0;
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == 'S')
        {
            s.push('S');
            count++;
        }
        else
        {
            if (s.empty())
            {
                return 0;
            }
            else
            {
                s.pop();
                count--;
            }
        }
        if (count > maxSize)
        {
            return 0;
        }
    }

    return s.empty() ? 1 : 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (stackJudge(command, m))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
// @pintia code=end