/*
  @pintia psid=1988824816654635008 pid=1988825531288539138 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第5次）
  Title: 珍珠项链
  https://pintia.cn/problem-sets/1988824816654635008/exam/problems/type/7?problemSetProblemId=1988825531288539138
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e4 + 10;
int head[maxN];


int FIND(int x)
{ 
    if (head[x] != x){
        head[x] = FIND(head[x]);
    }
    return head[x];
}

void UNION(int a,int b){
    int ha = FIND(a);
    int hb = FIND(b);
    if (ha != hb)
    {
        head[hb]=ha;
    }

}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1;i<=n;i++){
            head[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            UNION(a, b);
        }
        for(int i = 1;i<=n;i++){
            printf("%d ",FIND(i));
        }
        printf("\n");
    }
    return 0;
}
// @pintia code=end