/*
  @pintia psid=1991407512734584832 pid=1991407781866340352 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第6次）
  Title: 悟空救唐僧
  https://pintia.cn/problem-sets/1991407512734584832/endxam/problems/type/7?problemSetProblemId=1991407781866340352
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int grid[MAXN][MAXN];
bool vis[MAXN][MAXN][2];

struct Node
{
    int x;
    int y;
    int time = 0;
    bool super = false;
};

bool feasible(int nx, int ny, int n, int m)
{
    return nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 1;
}

int bfs(int n, int m, int T, int startx, int starty, int endx, int endy)
{
    queue<Node> q;
    memset(vis, false, sizeof(vis));
    q.push({startx, starty, 0, false});
    vis[startx][starty][0] = true;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.x == endx && cur.y == endy)
            return cur.time;

        for (int d = 0; d < 4; d++)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (feasible(nx, ny, n, m) && !vis[nx][ny][cur.super])
            {
                vis[nx][ny][cur.super] = true;
                q.push({nx, ny, cur.time + 1, cur.super});
            }
        }
    }
    return -1;
}

int main()
{
    int n, m, T;

    while (cin >> n >> m >> T)
    {
        int startx, starty, endx, endy;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 3)
                    startx = i, starty = j;
                if (grid[i][j] == 4)
                    endx = i, endy = j;
            }

        int res = bfs(n, m, T, startx, starty, endx, endy);

        if (res == -1)
            cout << "can not save" << endl;
        
        else{
            res = res - T + 1;
            if(res <= 0) res = 1;
            cout << res << endl;
        }
    }
    return 0;
}
// @pintia code=end