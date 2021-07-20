#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int> > flowers;
int days[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int to_days(int m, int d){
    int day = d;
    for (int i = 0; i < m - 1; i++)
        day += days[i];
    return day;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    int sm,sd,em,ed;
    for (int i = 0; i < n; i++) {
        cin>>sm>>sd>>em>>ed;
        flowers.push_back({to_days(sm,sd), to_days(em,ed)});
    }
    sort(flowers.begin(), flowers.end());

    int cur = 60, i = 0, len = flowers.size();
    while (cur < 335) {
        int max_end = cur;
        while (i < n && flowers[i].first <= cur){
            if (flowers[i].second >= max_end)
                max_end = flowers[i].second;
            i++;
        }
        if (cur == max_end) break;
        cur = max_end;
        ans++;
    }
    if (cur < 335) cout<<0;
    else cout<<ans;

    return 0;
}
