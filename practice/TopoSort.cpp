#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
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

void getInDegree(Vertex Head[], int n, int InDegree[])
{
    for (int i = 0; i < n; i++)
    {
        InDegree[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (Edge *p = Head[i].adjacent; p != NULL; p = p->link)
        {
            InDegree[p->VerAdj]++;
        }
    }
}

bool TopoSort(Vertex Head[], int n)
{
    int InDegree[N];
    getInDegree(Head, n, InDegree);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (InDegree[i] == 0)
        {
            s.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            return false;
        int j = s.top();
        s.pop();
        printf("%d ",j);
        for (Edge *p = Head[i].adjacent; p != NULL; p = p->link)
        {
            int k = p->VerAdj;
            InDegree[k]--;
            if (InDegree[k] == 0)
            {
                s.push(k);
            }
        }
    }
    return true;
}