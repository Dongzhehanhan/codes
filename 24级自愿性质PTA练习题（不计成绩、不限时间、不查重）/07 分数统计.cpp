/*
  @pintia psid=1979022247370915840 pid=1980991983274127360 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 分数统计
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980991983274127360
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> score(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> score[i];
  }

  const int MAX_SCORE = 1000;
  vector<int> count(MAX_SCORE + 1, 0);
  for (int s : score)
  {
    count[s]++;
  }

  vector<int> prefix(MAX_SCORE + 1, 0);
  prefix[0] = count[0];
  for (int i = 1; i <= MAX_SCORE; ++i)
  {
    prefix[i] = prefix[i - 1] + count[i];
  }

  for (int s : score)
  {
    int less = (s == 0) ? 0 : prefix[s - 1];
    cout << less << " ";
  }

  return 0;
}

// @pintia code=end