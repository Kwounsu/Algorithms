#include<bits/stdc++.h>
using namespace std;

struct Temp {
    int x, y;
    Temp() {}
    Temp(int x, int y) : x(x), y(y) {}
} t[128];

bool cmp(Temp &a, Temp &b) {return a.y < b.y;}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, x, y;

    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        if (x > y) swap(x, y);
        t[i] = Temp(x, y);
    }

    sort(t, t + n, cmp);

    int cnt = 1, j = 0;
    for (int i = 0; i < n - 1; i = j) {
        for (j = i + 1; j < n; j++) {
            if (t[i].y < t[j].x) {
                cnt++;
                break;
            }
        }
    }

    cout<<cnt;

    return 0;
}
