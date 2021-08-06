#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree {
    vector<ll> tree;
    FenwickTree(ll n) : tree(n+1) {}
    void update(ll idx, ll val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    ll sum(ll idx) {
        ll ret = 0;
        while(idx>0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll N, val, M, com, idx, idx2;
    cin>>N;

    vector<ll> arr(N+1);
    FenwickTree ft = FenwickTree(N);

    for (int i = 1; i <= N; i++){
        cin>>arr[i];
        ft.update(i, arr[i]);
    }

    cin>>M;
    while(M--){
        cin>>com;
        if (com == 1){
            cin>>idx>>val;
            ft.update(idx, val-arr[idx]);
            arr[idx] = val;
        } else{
            cin>>idx>>idx2;
            cout<<ft.sum(idx2) - ft.sum(idx-1)<<'\n';
        }
    }

    return 0;
}
