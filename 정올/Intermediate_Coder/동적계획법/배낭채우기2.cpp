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

    for (auto jewel : jewels)
        for (int i = w; i > 0; i--)
            if (jewel.weight <= i)
                dp[i] = max(dp[i], jewel.value + dp[i - jewel.weight]);

    cout<<dp[w];
}
