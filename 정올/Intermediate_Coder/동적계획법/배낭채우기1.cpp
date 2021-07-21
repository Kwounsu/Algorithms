#include <bits/stdc++.h>
using namespace std;

struct Jewel {
    int weight, value;
};

vector<Jewel> jewels;
int n, w, dp[10050];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>w;
    int a, b;
    for(int i = 1; i <= n; i++) {
        cin>>a>>b;
        jewels.push_back({a, b});
    }

    for(int i = 1; i <= w; i++) {
        int m = 0;
        for(auto jewel : jewels)
            if(i >= jewel.weight)
                m = max(m, dp[i - jewel.weight] + jewel.value);
        dp[i] = m;
    }

    cout<<dp[w];
}
