#include<bits/stdc++.h>
using namespace std;

struct line{int x1, y1, x2, y2;};
vector<line> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int T, n;
    bool safe;
    
    cin>>T;
    while(T--){
        cin>>n;
        v.resize(n);
        for(int i=0;i<n;i++)
            cin>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
        
        safe = true;
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(min(v[i].x1,v[i].x2) <= max(v[j].x1,v[j].x2)
                && min(v[j].x1,v[j].x2) <= max(v[i].x1,v[i].x2)
                && min(v[i].y1,v[i].y2) <= max(v[j].y1,v[j].y2)
                && min(v[j].y1,v[j].y2) <= max(v[i].y1,v[i].y2))
                    cout<<"DANGEROUS\n", safe = false, i=n, j=n;
        if(safe) cout<<"SAFE\n";
    }
}
