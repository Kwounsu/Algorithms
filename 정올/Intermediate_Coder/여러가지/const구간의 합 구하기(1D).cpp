#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    long long a[n+1] = {0};
    long long x;
    for (int i = 1; i <= n; i++) {
        cin>>x;
        a[i] += a[i - 1] + x;
    }

    int m, s, e;
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>s>>e;
        cout<<a[e] - a[s-1]<<'\n';
    }

    return 0;
}
