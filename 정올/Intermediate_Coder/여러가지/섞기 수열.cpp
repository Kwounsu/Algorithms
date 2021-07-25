#include<bits/stdc++.h>
using namespace std;

int pattern[20020];
vector<int> cycle;
bool visit[20020];

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
int lcm(int a, int b){return a / gcd(a, b) * b;}

void dfs(int step, int cur) {
    if (visit[cur]){
        cycle.push_back(step);
        return;
    }
    visit[cur] = true;
    dfs(step + 1, pattern[cur]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, i;

	cin>>n;
	for(i = 1; i <= n; i++)
        cin>>pattern[i];

    // find cycles
    for (i = 1; i <= n; i++) {
        if (visit[i]) continue;
        dfs(0, i);
    }

    // get LCM of cycles
    int len = cycle.size();
    if (len <= 1) {
        cout<<cycle[0];
    } else if (len == 2) {
        cout<<lcm(cycle[0], cycle[1]);
    } else {
        int ans = lcm(cycle[0], cycle[1]);
        for(i = 2; i < len; i++) {
            ans = lcm(ans, cycle[i]);
        }
        cout<<ans;
    }

    return 0;
}
