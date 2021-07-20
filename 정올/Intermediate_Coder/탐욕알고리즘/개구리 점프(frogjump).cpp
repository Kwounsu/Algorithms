#include <bits/stdc++.h>
using namespace std;

class Log{
public:
    int x1, x2, num;
    static int num_count;
    Log(int X1 = 0, int X2 = 0){
        x1 = X1;
        x2 = X2;
        num = ++num_count;
    }
    bool operator <(const Log & other)const{
        if (x1 != other.x1) return x1 < other.x1;
        return x2 < other.x2;
    }
};

int Log::num_count = 0;
vector<Log> logs;
int n, q;
int root[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>q;
    int x1,x2,y, i;
    for (i = 0; i < n; i++) {
        cin>>x1>>x2>>y;
        logs.push_back({x1, x2});
    }
    sort(logs.begin(), logs.end());

    // 각 통나무를 사이클별로 구분 (Union-find)
    int cur = 0, r = 0;
    for(i = 0; i < n; i++) {
        if(cur < logs[i].x1 )
            r++;
        cur = max(cur, logs[i].x2);
        root[logs[i].num] = r;
    }

    // 같은 사이클에 있으면 1, 아니면 0.
    int s, e;
    for(i = 0; i < q; i++) {
        cin>>s>>e;
        if (root[s] == root[e]) cout<<"1\n";
        else cout<<"0\n";
    }

    return 0;
}
