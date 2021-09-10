#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj{{},
    {2,4},{1,3,5},{2,6},
    {1,5,7},{2,4,6,8},{3,5,9},
    {4,8},{5,7,9},{6,8}};
unordered_map<int,int> visited, path;
struct dat{int arr[10],step;};
queue<dat> q;

void track(int x){
    if(x == -1) return;
    track(path[x]);
    cout<<path[x];
}

int num(int a[]){
    int ret = 0;
    for(int i=1;i<10;i++)
        ret = ret*10 + a[i];
    return ret;
}

int loc(int a[]){
    for(int i=1;i<10;i++)
        if(a[i]!=i) return i; 
    return -1;
}

void bfs(){
    while(!q.empty()){
        dat cur=q.front(); q.pop();
        int n = num(cur.arr);
        if(n == 123456780){
            cout<<cur.step<<'\n';
            track(9);
            break;
        }
        if(visited[n]) continue;
        visited[n] = 1;
        int x = loc(cur.arr);
        for(int el:adj[x]){
            int narr[10] = cur.arr;
            narr[x] = narr[el];
            narr[el] = 0;
            q.push({narr,cur.step+1,cur.arr[el]});
            path[]
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int arr[10];
    char ch;
//    for(int i=1;i<10;i++){
//        cin>>ch;
//        arr[i] = ch!='X'?ch-'0':0;
//    }
    ifstream fin("input.txt");
    for(int i=1;i<10;i++){
        fin>>ch;
        arr[i] = ch!='X'?ch-'0':0;
    }

    q.push({arr,0});
    bfs();

//    for(int i=1;i<10;i++){
//        cout<<i<<": ";
//        for(auto x:adj[i]){
//            cout<<x<<' ';
//        }
//        cout<<'\n';
//    }

//    for(int i=1;i<10;i++)
//        cout<<arr[i]<<' ';
//    cout<<'\n';

    return 0;
}
