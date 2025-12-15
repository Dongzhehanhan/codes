/*
  @pintia psid=1996060208809046016 pid=1996060507510648832 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第8次）
  Title: 双十一
  https://pintia.cn/problem-sets/1996060208809046016/exam/problems/type/7?problemSetProblemId=1996060507510648832
*/
// @pintia code=start
#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
struct Edge {
	int VerAdj;
	int cost;
	Edge* link;
};
struct Vertex {
	int data;
	Edge* adjacent;
};
void Dijkstra(Vertex Head[], int n, int u, int dist[]) {
	bool S[N] = { false };
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	dist[u] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[u],u });

	while (!pq.empty()) {
		auto k = pq.top(); pq.pop();
		int v = k.second;
		int v_dist = k.first;
		if (S[v] == true) continue;
		S[v] = true;
		for (Edge* p = Head[v].adjacent; p != NULL; p = p->link) {
			int w = p->VerAdj;
			if (dist[w] > dist[v] + p->cost) {
				dist[w] = dist[v] + p->cost;
				pq.push({ dist[w],w });
			}
		}
	}
}
int main() {
	int n, e;
	while (cin >> n >> e) {
		Vertex Head[N];
		for (int i = 0; i < n; i++) {
			Head[i].data = i;
			Head[i].adjacent = NULL;
		}
		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			Edge* newEdge = new Edge();
			newEdge->VerAdj = b;
			newEdge->cost = c;
			newEdge->link = Head[a].adjacent;
			Head[a].adjacent = newEdge;

			Edge* newEdge1 = new Edge();
			newEdge1->VerAdj = a;
			newEdge1->cost = c;
			newEdge1->link = Head[b].adjacent;
			Head[b].adjacent = newEdge1;
		}
		
		int min = INF;
		int bestPoint = -1;
		for (int u = 0; u < n; u++) {
			int dist[N];
			Dijkstra(Head, n, u, dist);
			int sum = 0;
			for (int v = 0; v < n; v++) {
				if (v != u) {
					sum += dist[v];
				}
			}
			if (sum < min) {
				min = sum;
				bestPoint = u;
			}
		}
		cout << bestPoint << endl;
	}
	return 0;
}
// @pintia code=end