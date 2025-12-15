/*
  @pintia psid=1993908583409287168 pid=1993908898279870464 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第7次）
  Title: 关键路径
  https://pintia.cn/problem-sets/1993908583409287168/exam/problems/type/7?problemSetProblemId=1993908898279870464
*/
// @pintia code=start
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 210;
struct Edge {
	int VerAdj;
	int cost;
	Edge* link;
};

struct Vertex {
	int data;
	Edge* adjacent;
};

Vertex Head[N];

struct CriticalEdge {
	int u, v;
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

bool TopoOrder(Vertex Head[], int n, int ve[], int Topo[]) {
	int InDegree[N];
	getInDegree(Head, n, InDegree);
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (InDegree[i] == 0)
			s.push(i);
	}

	int index = 0;
	while (!s.empty()) {
		int j = s.top(); s.pop();
		Topo[index] = j;
		index++;
		for (Edge* p = Head[j].adjacent; p != NULL; p = p->link) {
			int k = p->VerAdj;
			InDegree[k]--;
			if (InDegree[k] == 0) s.push(k);
			if (ve[j] + p->cost > ve[k]) {
				ve[k] = ve[j] + p->cost;
			}
		}
	}
	return (index == n);
}

void VLtime(Vertex Head[], int n, int Topo[], int ve[], int vl[]) {
	for (int j = 0; j < n; j++) {
		vl[j] = ve[Topo[n - 1]];//汇点vl=ve；
	}
	for (int j = n - 1; j > 0; j--) {
		for (Edge* p = Head[j].adjacent; p != NULL; p = p->link) {
			int k = p->VerAdj;
			if (vl[k] - p->cost < vl[Topo[j]]) {
				vl[Topo[j]] = vl[k] - p->cost;
			}
		}
	}
}

bool cmp(const CriticalEdge& a, const CriticalEdge& b) {
	if (a.u != b.u) return a.u < b.u;
	return a.v < b.v;
}
int main() {
	int n, e;
	while (cin >> n >> e) {

		for (int i = 0; i < n; i++) {
			Head[i].data = i;
			Head[i].adjacent = NULL;
		}
		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			Edge* newEdge = new Edge();
			newEdge->VerAdj = b;
			newEdge->cost = c;
			newEdge->link = Head[a].adjacent;
			Head[a].adjacent = newEdge;
		}

		int ve[N] = { 0 }, vl[N] = { 0 }, Topo[N];
		if (!TopoOrder(Head, n, ve, Topo)) {
			printf("unworkable project\n");
			continue;
		}

		VLtime(Head, n, Topo, ve, vl);
		printf("%d\n", ve[Topo[n - 1]]);

		vector<CriticalEdge> cEdges;
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (Edge* p = Head[i].adjacent; p != NULL; p = p->link) {
				int j = p->VerAdj;
				int e_val = ve[i];
				int l_val = vl[j] - p->cost;
				if (e_val == l_val)
				{
					cEdges.push_back({ i + 1,j + 1 });
				}
			}
		}

		sort(cEdges.begin(), cEdges.end(), cmp);
		for (auto& edge : cEdges) {
			printf("%d->%d\n", edge.u, edge.v);
		}
	}
	return 0;
}

// @pintia code=end