#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos>0) {
            ret += tree[pos];
            pos&=(pos-1);
        }
        return ret;
    }
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;

    return 0;
}
