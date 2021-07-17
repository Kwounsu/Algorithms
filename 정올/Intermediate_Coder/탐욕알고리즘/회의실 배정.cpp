#include<bits/stdc++.h>
using namespace std;

struct Meeting {
    int idx;
    int stime, etime;
    Meeting() {}
    Meeting(int idx, int stime, int etime)
        : idx(idx), stime(stime), etime(etime) {}
};

int n, a, b, c, i;
Meeting mt[512];

bool cmp(Meeting &a, Meeting &b) {return a.etime<b.etime;}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin>>n;
    for (i = 0; i < n; i++) {
        cin>>a>>b>>c;
        mt[i] = Meeting(a, b, c);
    }

    // 끝나는 시간 순으로 정렬
    sort(mt, mt+n, cmp);

    vector<int> ans;
    for (i = 0; i < n; i++) {
        vector<int> t;
        t.push_back(i);
        for (int j = i + 1; j < n; j++)
            if (mt[t.back()].etime <= mt[j].stime)
                t.push_back(j);
        
        // ans 업데이트
        if (ans.size() < t.size()) {
            ans.clear();
            for (int k = 0; k < t.size(); k++)
                ans.push_back(t[k]);
        }
    }

    
    cout<<ans.size()<<"\n";
    for (i = 0; i < ans.size(); i++)
        cout<<mt[ans[i]].idx<<" ";

    return 0;
}
