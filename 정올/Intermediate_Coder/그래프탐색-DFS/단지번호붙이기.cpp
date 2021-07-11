#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int grid[31][31];
int visited[31][31] = {0};
vector<int> v;

void bfs(int i, int j){
    if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] > 0 && !visited[i][j]) {
        cnt++;
        visited[i][j] = 1;

        bfs(i - 1, j);
        bfs(i, j - 1);
        bfs(i + 1, j);
        bfs(i, j + 1);
    }
}

int main() {
    cin>>n;
    
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin>>c;
            if (c == '0') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] > 0 && !visited[i][j]) {
                cnt = 0;
                bfs(i, j);
                if (cnt > 0)
                    v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    printf("%d\n", v.size());
    for (auto x : v)
        printf("%d\n", x);
    
    return 0;
}
