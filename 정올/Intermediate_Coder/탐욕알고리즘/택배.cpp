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

int n, c, m, box[2001];
vector<Info> info;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>c>>m;
    int a,b,q;
    for (int i = 0; i < m; i++) {
        cin>>a>>b>>q;
        info.push_back({a,b,q});
    }
    sort(info.begin(), info.end());

    for(auto i:info)
        cout<<i.a<<' ';

    return 0;
}
