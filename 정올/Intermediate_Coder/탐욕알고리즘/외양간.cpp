#include<bits/stdc++.h>
using namespace std;

int m, s, c;
int cnt[256];
int diff[256];

bool cmp(int a, int b) {return a>b;}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin>>m>>s>>c;
    for (int i = 0; i < c; i++)
        cin>>cnt[i];

    sort(cnt, cnt+c);

    for (int i = 0; i < c - 1; i++) {
        diff[i] = cnt[i+1] - cnt[i] - 1;
    }

    sort(diff, diff+c-1, cmp);

    int len = cnt[c-1] - cnt[0] + 1;
    for (int i = 0; i < m - 1; i++) {
        len -= diff[i];
    }

    cout<<len<<"\n";

    return 0;
}
