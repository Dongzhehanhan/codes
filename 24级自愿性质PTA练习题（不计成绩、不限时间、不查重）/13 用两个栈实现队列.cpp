/*
  @pintia psid=1979022247370915840 pid=1979023629670928384 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 用两个栈实现队列
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1979023629670928384
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    stack<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        char op;
        scanf(" %c", &op);
        if (op == 'I')
        {
            int num;
            scanf("%d", &num);
            s1.push(num);
        }
        else if (op == 'O')
        {
            int time = 0;
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                    time += 2;
                }
                if (s2.empty())
                {
                    printf("ERROR\n");
                    continue;
                }
            }
            int outval = s2.top();
            s2.pop();
            time += 1;
            printf("%d %d\n", outval, time);
        }
    }

    return 0;
}
// @pintia code=end