/*
  @pintia psid=1993908583409287168 pid=1993908898271481856 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第7次）
  Title: 最少点字典序最短路径
  https://pintia.cn/problem-sets/1993908583409287168/exam/problems/type/7?problemSetProblemId=1993908898271481856
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int VerAdj;
    int cost;
    Edge *link;
};
struct Vertex
{
    int data;
    Edge *adjacent;
};

bool isPathSmaller(int u, int v, int pre[]) {
    vector<int> pathU, pathV;
    for (int i = u; i != -1; i = pre[i]) {
        pathU.push_back(i);
    }
    for (int i = v; i != -1; i = pre[i]) {
        pathV.push_back(i);
    }
    reverse(pathU.begin(), pathU.end());
    reverse(pathV.begin(), pathV.end());
    
    int n = min(pathU.size(), pathV.size());
    for (int i = 0; i < n; i++) {
        if (pathU[i] < pathV[i]) return true;
        if (pathU[i] > pathV[i]) return false;
    }
    return pathU.size() < pathV.size();
}

int findMin(int S[], int dist[], int count[], int n)
{
    int v = -1, minDist = INF, minCount = INF;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 0)
        {
            if (dist[i] < minDist)
            {
                minDist = dist[i];
                minCount = count[i];
                v = i;
            }
            else if (dist[i] == minDist)
            {
                if (count[i] < minCount)
                {
                    minCount = count[i];
                    v = i;
                }
                else if (count[i] == minCount && (v == -1 || i < v))
                {
                    v = i;
                }
            }
        }
    }
    return v;
}

void Dijkstra(Vertex Head[], int n, int u, int dist[], int pre[], int count[])
{
    int S[N] = {0};
    memset(dist, 0x3f, sizeof(int)*n);
    memset(pre, -1, sizeof(int)*n);
    memset(count, 0x3f, sizeof(int)*n);
    
    dist[u] = 0;
    count[u] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = findMin(S, dist, count, n);
        if (v == -1)
            return;
        S[v] = 1;
        for (Edge *p = Head[v].adjacent; p != NULL; p = p->link)
        {
            int w = p->VerAdj;
            if (S[w] == 0)
            {
                int newDist = dist[v] + p->cost;
                int newCount = count[v] + 1;
                if (newDist < dist[w])
                {
                    dist[w] = newDist;
                    pre[w] = v;
                    count[w] = newCount;
                }
                else if (newDist == dist[w])
                {
                    if (newCount < count[w])
                    {
                        count[w] = newCount;
                        pre[w] = v;
                    }
                    else if (newCount == count[w] && pre[w] != -1)
                    {
                        if (isPathSmaller(v, pre[w], pre)) {
                            pre[w] = v;
                        }
                    }
                    else if (pre[w] == -1) {
                        pre[w] = v;
                    }
                }
            }
        }
    }
}

void PrintPath(int pre[], int v)
{
    if (pre[v] == -1)
    {
        printf("%d", v);
        return;
    }
    PrintPath(pre, pre[v]);
    printf("->%d", v);
}
int main()
{
    int n, e;
    cin >> n >> e;
    Vertex Head[N];
    for (int i = 0; i < n; i++)
    {
        Head[i].data = i;
        Head[i].adjacent = NULL;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge *newEdge = new Edge();
        newEdge->VerAdj = b;
        newEdge->cost = c;
        newEdge->link = Head[a].adjacent;
        Head[a].adjacent = newEdge;
    }

    int dist[N];
    int pre[N];
    int count[N];
    Dijkstra(Head, n, 0, dist, pre, count);

    for (int i = 1; i < n; i++)
    {
        if (dist[i] != INF)
        {
            PrintPath(pre, i);
            printf("\n");
        }
    }
    return 0;
}
// @pintia code=end