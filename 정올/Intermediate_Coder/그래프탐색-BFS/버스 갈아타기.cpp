#include<bits/stdc++.h>
using namespace std;

struct Line {
    int x1, y1;
    int x2, y2;
    Line() {}
    Line(int x1, int y1, int x2, int y2) :
        x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int m, n, k;
vector<Line> lines;
int sx, sy, dx, dy;
bool visited[8192];

void bfs() {
    queue<pair<int, int>> que;

    // 시작점에서 탈 수 있는 버스들 큐에 넣기
    for (int i = 0; i < k; i++)
        if (lines[i].x1 <= sx && sx <= lines[i].x2 
         && lines[i].y1 <= sy && sy <= lines[i].y2) {
            que.push({1, i});
            visited[i] = 1;
        }

    // BFS
    while (!que.empty()) {
        pii p = que.front(); que.pop();
        int bus_cnt = p.first;  // 버스 탄 수
        int u = p.second;     // 
        if (lines[u].x1 <= dx && dx <= lines[u].x2 
         && lines[u].y1 <= dy && dy <= lines[u].y2) {
            cout<<bus_cnt<<"\n";
            break;
        }
        // 탄적 없고, 환승 가능하면 버스 타기
        for (int v = 0; v < k; v++) {
            if (visited[v]) continue;
            if (lines[u].x1 <= lines[v].x2 
             && lines[v].x1 <= lines[u].x2
             && lines[u].y1 <= lines[v].y2 
             && lines[v].y1 <= lines[u].y2) {
                visited[v] = 1;
                que.push({bus_cnt+1, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int b, x1, y1, x2, y2;

    cin>>m>>n>>k;
    for (int i = 0; i < k; i++) {
        cin>>b>>x1>>y1>>x2>>y2;
        // 버스 행선 앞이 작고 뒤가 크게끔 처리
        if (x1>x2) swap(x1, x2);
        else if (y1>y2) swap(y1, y2);
        lines.push_back(Line(x1, y1, x2, y2));
    }
    cin>>sx>>sy>>dx>>dy;

    bfs();

    return 0;
}
