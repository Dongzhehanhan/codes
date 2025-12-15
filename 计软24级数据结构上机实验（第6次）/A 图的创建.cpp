/*
  @pintia psid=1991407512734584832 pid=1991407781862146048 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第6次）
  Title: 图的创建
  https://pintia.cn/problem-sets/1991407512734584832/exam/problems/type/7?problemSetProblemId=1991407781862146048
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int VerAdj;
    int cost;
    Edge *link;
    Edge(int v, int w) : VerAdj(v), cost(w), link(NULL) {}
};

struct Vertex
{
    int data;
    Edge *adjacent = NULL;
    Vertex(int n) : data(n), adjacent(NULL) {}
};

bool cmp(Edge *a, Edge *b)
{
    return a->VerAdj < b->VerAdj;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Vertex> Ver;
    for (int i = 0; i < n; i++)
    {
        Ver.push_back(Vertex(i));
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge *p = new Edge(v, w);
        p->link = Ver[u].adjacent;
        Ver[u].adjacent = p;
    }

    for (int j = 0; j < n; j++)
    {
        Vertex &curVer = Ver[j];
        if (curVer.adjacent == NULL)
        {
            continue;
        }

        vector<Edge *> edges;
        Edge *p = curVer.adjacent;
        while (p != NULL)
        {
            edges.push_back(p);
            p = p->link;
        }

        sort(edges.begin(), edges.end(), cmp);

        printf("%d:", curVer.data);
        for (Edge *edge : edges)
        {
            printf("(%d,%d,%d)", curVer.data, edge->VerAdj, edge->cost);
        }
        printf("\n");
    }
    return 0;
}
// @pintia code=end