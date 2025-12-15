/*
  @pintia psid=1996060208809046016 pid=1996060507514843137 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第8次）
  Title: 网络布线
  https://pintia.cn/problem-sets/1996060208809046016/exam/problems/type/7?problemSetProblemId=1996060507514843137
*/
// @pintia code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1000;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int head;
    int tail;
    int weight;
};

int Parent[N];
Edge E[N];

void Make_set(int x)
{
    Parent[x] = 0;
}
int Find(int x)
{
    if (Parent[x] <= 0)
        return x;
    Parent[x] = Find(Parent[x]);
    return Parent[x];
}
int Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx == fy)
        return;
    if (Parent[fx] < Parent[fy])
    {
        Parent[fy] = fx;
    }
    else if (Parent[fy] < Parent[fx])
    {
        Parent[fx] = fy;
    }
    else
    {
        Parent[fx] = fy;
        Parent[fy]--;
    }
}
bool cmp(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}
int Kruskal(Edge E[], int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        Make_set(i);
    }

    sort(E, E + e, cmp);

    int sum = 0;
    int k = 0;
    for (int i = 0; i < e; i++)
    {
        int u = E[i].head, v = E[i].tail, w = E[i].weight;
        if (Find(u) != Find(v))
        {
            k++;
            sum += w;
            Union(u, v);
        }
        if (k == n - 1)
        {
            return sum;
        }
        return INF;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> routerCost(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &routerCost[i]);
    }

    int edgeCount = 0;
    for (int i = 0; i < n; i++)
    {
        E[edgeCount].head = n;
        E[edgeCount].tail = i;
        E[edgeCount].weight = routerCost[i];
        edgeCount++;
    }

    for(int i = 0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        E[edgeCount].head=u;
        E[edgeCount].tail=v;
        E[edgeCount].weight=w;
        edgeCount++;
    }
    int result = Kruskal(E,n+1,edgeCount);
    printf("%d\n",result);
    return 0;
}
// @pintia code=end