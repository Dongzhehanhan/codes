/*
  @pintia psid=1979022247370915840 pid=1980994095965978624 compiler=GXX
  ProblemSet: 24级自愿性质PTA练习题（不计成绩、不限时间、不查重）
  Title: 特殊队列（简单版）
  https://pintia.cn/problem-sets/1979022247370915840/exam/problems/type/7?problemSetProblemId=1980994095965978624
*/
// @pintia code=start
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    vector<vector<int>> allResults;

    while (T--) {
        cin >> n;
        queue<int> q;
        vector<int> currentResults;

        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;

            if (op == "ENQUEUE") {
                int x;
                cin >> x;
                q.push(x);
            } else if (op == "DEQUEUE") {
                if (!q.empty()) {
                    q.pop();
                }
            } else if (op == "REVERSE") {
                queue<int> temp;
                while (!q.empty()) {
                    int val = q.front();
                    q.pop();
                    temp.push(-val); // 每个元素取反
                }
                q = temp;
            } else if (op == "MAXIMUM") {
                if (!q.empty()) {
                    queue<int> temp = q;
                    int maxVal = temp.front();
                    temp.pop();
                    while (!temp.empty()) {
                        if (temp.front() > maxVal) {
                            maxVal = temp.front();
                        }
                        temp.pop();
                    }
                    currentResults.push_back(maxVal);
                }
            }
        }

        allResults.push_back(currentResults);
    }

    
    for (int i = 0; i < allResults.size(); i++) {
        if (i > 0) {
            cout << endl;
        }
        for (int val : allResults[i]) {
            cout << val << endl;
        }
    }

    return 0;
}
// @pintia code=end