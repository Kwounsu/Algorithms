#include <bits/stdc++.h>
using namespace std;

long long a[1010][1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    long long x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>x;
            a[i][j] += a[i][j - 1] + a[i - 1][j] + x - a[i-1][j-1];
        }
    }

    int m, sr, sc, er, ec;
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>sr>>sc>>er>>ec;
        cout<<a[er][ec] - a[er][sc-1] - a[sr-1][ec] +a[sr-1][sc-1]<<'\n';
    }

    return 0;
}
