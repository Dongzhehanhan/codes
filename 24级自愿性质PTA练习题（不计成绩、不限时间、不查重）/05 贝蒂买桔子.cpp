/*
  @pintia psid=1979022247370915840 pid=1980992474712301568 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 贝蒂买桔子
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980992474712301568
*/
// @pintia code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct elem
{
    vector<char> current;
    int start;
};

int main()
{
    int n;
    scanf("%d", &n);

    vector<char> chars;
    for (int i = 0; i < n; i++)
    {
        chars.push_back('a' + i);
    }

    stack<elem> s;
    s.push({{}, 0});
    while (!s.empty())
    {
        elem e = s.top();
        s.pop();

        printf("{");
        for (int i = 0; i < e.current.size(); i++)
        {
            if (i > 0)
                printf(",");
            printf("%c", e.current[i]);
        }
        printf("}\n");
        for (int i = n - 1; i >= e.start; --i)
        {
            vector<char> nextCurrent = e.current;
            nextCurrent.push_back(chars[i]);
            s.push({nextCurrent, i + 1});
        }
    }
}
// @pintia code=end