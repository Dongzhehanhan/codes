/*
  @pintia psid=1991407512734584832 pid=1991407781862146049 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第6次）
  Title: 图深度优先遍历
  https://pintia.cn/problem-sets/1991407512734584832/exam/problems/type/7?problemSetProblemId=1991407781862146049
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;

struct Edge
{
    int VerAdj;
    Edge *link;
};

struct Vertex
{
    int data;
    Edge *adjacent = NULL;
};

void visit(int v)
{
    cout << v << " ";
}

void DFS(Vertex Head[], int v, int visited[])
{
    visit(v);
    visited[v] = 1;
    for (Edge *p = Head[v].adjacent; p != NULL; p = p->link)
    {
        int k = p->VerAdj;
        if (visited[k] == 0)
        {
            DFS(Head, k, visited);
        }
    }
}

void DisconnectDFS(Vertex Head[], int n)
{
    int visited[N];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(Head, i, visited);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Vertex> Ver;
    for (int i = 0; i < n; i++)
    {
        Vertex v;
        v.data = i;
        v.adjacent = NULL;
        Ver.push_back(v);
    }

    vector<vector<int>> tempAdj(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        tempAdj[u].push_back(v);
    }
    
    for (int i = 0; i < n; i++)
    {
        sort(tempAdj[i].begin(), tempAdj[i].end());
        for (int j = tempAdj[i].size() - 1; j >= 0; --j)
        {
            Edge *p = new Edge;
            p->VerAdj = tempAdj[i][j];
            p->link = Ver[i].adjacent;
            Ver[i].adjacent = p;
        }
    }

    DisconnectDFS(Ver.data(), n);
    return 0;
}
// @pintia code=end