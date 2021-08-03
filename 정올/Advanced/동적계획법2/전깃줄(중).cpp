#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 100010
using namespace std;

pair<int, int> D[MAX];
int path[MAX], ans[MAX];
vector<int> v;
int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y; scanf("%d%d", &x, &y);
        D[i] = { x,y };
    }
    sort(D, D + N);
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int x = upper_bound(v.begin(), v.end(), D[i].Y) - v.begin();
        if (x == v.size()) v.push_back(D[i].Y);
        else v[x] = D[i].Y;
        path[i] = v[x - 1];
    }
    printf("%d\n", N -v.size() + 1);
    int y = v[v.size() - 1];
    for (int i = N - 1; i >= 0; i--) {
        if (y == D[i].Y) {
            ans[i] = 1;
            y = path[i];
        }
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] == 0) printf("%d\n", D[i].X);
    }
    return 0;
}
