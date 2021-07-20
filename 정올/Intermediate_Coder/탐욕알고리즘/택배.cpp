#include <bits/stdc++.h>
using namespace std;

class Info{
public:
    int a, b, q;
    Info(int A = 0, int B = 0, int Q = 0){
        a = A;
        b = B;
        q = Q;
    }
    bool operator <(const Info & i)const{
        if (b != i.b) return b < i.b;
        return a < i.a;
    }
};

int n, c, m, box[2001], ans;
vector<Info> info;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>c>>m;
    int a,b,q,i;
    for (i = 0; i < m; i++) {
        cin>>a>>b>>q;
        info.push_back({a,b,q});
    }
    sort(info.begin(), info.end());

    int box_max, empty_space;
    for(auto truck:info) {
        // 구간 내 가장 많이 적재된 양
        box_max = 0;
        for (i = truck.a; i < truck.b; i++)
            box_max = max(box_max, box[i]);

        // 트럭에 추가 가능한 양
        empty_space = min(truck.q, c - box_max);
        ans += empty_space;

        // 해당 구간 추가 적재
        for (i = truck.a; i < truck.b; i++)
            box[i] += empty_space;
    }

    cout<<ans;

    return 0;
}
