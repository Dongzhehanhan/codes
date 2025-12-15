/*
  @pintia psid=1996060208809046016 pid=1996060507514843136 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第8次）
  Title: 去火车站
  https://pintia.cn/problem-sets/1996060208809046016/exam/problems/type/7?problemSetProblemId=1996060507514843136
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
const int INF = 0x3f3f3f3f;

struct metroTime
{
    int start;
    int end;
    int cost;
    metroTime(int a, int b, int c) : start(a), end(b), cost(c) {}
};
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

int findMin(int S[], int dist[], int n)
{
    int v = -1, min = INF;
    for (int i = 1; i <= n; i++)
    {
        if (S[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            v = i;
        }
    }
    return v;
}

void Dijkstra(Vertex Head[], int n, int u, int dist[])
{
    int pre[N] = {0};
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        pre[i] = -1;
    }
    int S[N] = {0};
    dist[u] = 0;

    for (int i = 1; i <= n; i++)
    {
        int v = findMin(S, dist, n);
        if (v == -1)
            return;
        S[v] = 1;
        for (Edge *p = Head[v].adjacent; p != NULL; p = p->link)
        {
            int w = p->VerAdj;
            if (S[w] == 0 && dist[v] + p->cost < dist[w])
            {
                dist[w] = dist[v] + p->cost;
                pre[w] = v;
            }
        }
    }
}

int main()
{
    int n, s, t;
    Vertex Head[N];

    while (cin >> n >> s >> t)
    {
        for (int i = 1; i <= n; i++)
        {
            Head[i].data = i;
            Head[i].adjacent = NULL;
        }
        int busNo;
        cin >> busNo;
        while (busNo--)
        {
            int a, b, c;
            cin >> a >> b >> c;

            Edge *p = new Edge;
            p->VerAdj = b;
            p->cost = c;
            p->link = Head[a].adjacent;
            Head[a].adjacent = p;

            Edge *q = new Edge;
            q->VerAdj = a;
            q->cost = c;
            q->link = Head[b].adjacent;
            Head[b].adjacent = q;
        }

        int schoolDist[N];
        Dijkstra(Head, n, s, schoolDist);
        int stationDist[N];
        Dijkstra(Head, n, t, stationDist);
        int busTime = schoolDist[t];

        int metroNo;
        cin >> metroNo;
        vector<metroTime> metros;
        while (metroNo--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            metroTime st0(x, y, z);
            metros.push_back(st0);
            metroTime st1(y, x, z);
            metros.push_back(st1);
        }

        int transferTime = INF;
        int transfer = -1;
        for (metroTime mt : metros)
        {
            int x = mt.start;
            int y = mt.end;
            int z = mt.cost;

            if (schoolDist[x] != INF && stationDist[y] != INF)
            {
                int total = schoolDist[x] + z + stationDist[y];
                if (total < transferTime)
                {
                    transferTime = total;
                    transfer = x;
                }
                else if (total == transferTime && x < transfer)
                {
                    transfer = x;
                }
            }
        }

        if (transferTime < busTime)
        {
            cout << transferTime << endl;
            cout << transfer << endl;
        }
        else
        {
            cout << busTime << endl;
            cout << "no metro" << endl;
        }
    }

    return 0;
}
// @pintia code=end