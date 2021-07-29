#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;

struct Node{
    int idx, val;
    Node(int a=0, int b=0) {idx=a, val=b;}
    bool operator<(const Node & b)const {return val<b.val;}
}tree[MAXN*4];

const Node NUL = Node(-1,1000000001);

int N, M;

// query(트리노드번호, 구간시작, 구간끝, 쿼리시작, 쿼리끝)
Node query(int cur, int s, int e, int qs, int qe){
    if (e < qs || qe < s) return NUL;
    if (qs <= s && e <= qe) return tree[cur];
    int m = (s + e) / 2;
    Node left = query(cur*2, s, m, qs, qe);
    Node right = query(cur*2+1, m+1, e, qs, qe);
    return min(left, right);
}

// update(트리노드번호, 구간시작, 구간끝, 목표 위치, 업데이트할 값)
void update(int cur, int s, int e, int target, int val){
    if (s == e) {
        tree[cur] = Node(target, val);
        return;
    }
    int m = (s + e) / 2;
    if (target <= m) update(cur*2, s, m, target, val);
    else update(cur*2+1, m+1, e, target, val);
    tree[cur] = min(tree[cur*2], tree[cur*2+1]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for (int i = 1; i <= N*4; i++)
        tree[i] = NUL;

    int a, b, c;
    for (int i = 1; i <= M; i++) {
        cin>>a>>b>>c;

        if (a==1) update(1, 1, N, b, c);
        else {
            Node ans = query(1, 1, N, b, c);
            if (a==2 && ans.val != NUL.val)
                cout<<ans.idx<<'\n';
            else if (a==3)
                update(1, 1, N, ans.idx, 1000000001);
        }
    }

    return 0;
}
