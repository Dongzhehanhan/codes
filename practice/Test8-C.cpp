/**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1000;
const int INF = 0x3f3f3f3f;
struct Edge{
    int head;
    int tail;
    int cost;
};
Edge E[N];
int Parent[N];
void Make_set(int x){
    Parent[x] = 0;
}

int Find(int x){
    if(Parent[x]<=0) return x;
    Parent[x] = Find(Parent[x]);
    return Parent[x];
}

void Union(int a,int b){
    int fa = Find(a);
    int fb = Find(b);
    if(fa==fb) return;
    if(Parent[fa]<Parent[fb]){
        Parent[fb] = fa;
    }
    else if(Parent[fb]<Parent[fa]){
        Parent[fa] = fb;
    }
    else{
        Parent[fa] = fb;
        Parent[fb]--;
    }
}
bool cmp(const Edge& a,const Edge& b){
    return a.cost<b.cost;
}

int Kruskal(Edge E[],int n,int e){
    for(int i = 0;i<=n;i++){
        Make_set(i);
    }
    sort(E,E+e,cmp);
    int sum = 0,k=0;
    for(int i = 0;i<e;i++){
        int u = E[i].head,v=E[i].tail,w=E[i].cost;
        if(Find(u)!=Find(v)){
            k++;
            sum+=w;
            Union(u,v);
        }
        if(k==n-1) return sum;
    }
    return INF;
}
int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int total_v = n+1;
    vector<int> RouterCost(n);
    for(int i = 0;i<n;i++){
        scanf("%d",&RouterCost[i]);
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        E[count].head = n;
        E[count].tail = i;
        E[count].cost = RouterCost[i];
        count++;
    }

    for(int i = 0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E[count].head=u;
        E[count].tail=v;
        E[count].cost=w;
        count++;
    }

    int res = Kruskal(E,total_v,count);
    printf("%d\n",res);
    return 0;
}