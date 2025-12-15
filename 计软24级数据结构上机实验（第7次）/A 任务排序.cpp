/*
  @pintia psid=1993908583409287168 pid=1993908898275676160 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第7次）
  Title: 任务排序
  https://pintia.cn/problem-sets/1993908583409287168/exam/problems/type/7?problemSetProblemId=1993908898275676160
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
struct Edge {
    int VerAdj;
    int cost;
    Edge* link;
};
struct Vertex {
    int data;
    Edge* adjacent;
};

void getInDegree(Vertex Head[], int n, int InDegree[]) {
    for (int i = 0; i < n; i++) {
        InDegree[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (Edge* p = Head[i].adjacent; p != NULL; p = p->link) {
            InDegree[p->VerAdj]++;
        }
    }
}

bool TopoOrder(Vertex Head[], int n) {
    int InDegree[N];
    getInDegree(Head, n, InDegree);

    bool visited[N] = {false};
    for (int m = 0; m < n; m++) {
        int minNode = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && InDegree[i] == 0) {
                if (minNode == -1 || i < minNode) {
                    minNode = i;
                }
            }
        }

        if (minNode == -1) {
            return false;
        }

        cout << minNode << " ";
        visited[minNode] = true;

        for (Edge* p = Head[minNode].adjacent; p != NULL; p = p->link) {
            int k = p->VerAdj;
            InDegree[k]--;
        }
    }
    return true;
}


int main() {
    int n, e;
    cin >> n >> e;

    Vertex Head[N];
    for (int i = 0; i < n; i++) {
        Head[i].data = i;
        Head[i].adjacent = NULL;
    }

    for (int i = 0; i < e; i++) {
        int a, b;cin >> a >> b;
        Edge* newEdge = new Edge();
        newEdge->VerAdj = b;
        newEdge->cost = 0;
        newEdge->link = Head[a].adjacent;
        Head[a].adjacent = newEdge;
    }

    if (!TopoOrder(Head, n)) {
        cout << "unworkable project" << endl;
    } else {
        cout << endl;
    }

    return 0;
}
// @pintia code=end