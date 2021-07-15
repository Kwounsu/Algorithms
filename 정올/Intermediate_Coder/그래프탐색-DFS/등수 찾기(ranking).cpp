#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
int N, M, X;
vector<vector<int> > better_than;
vector<vector<int> > worse_than;

int better_check(int a) {
    int sum = 0;
    for (int i=0; i<(int)better_than[a].size(); i++) {
        if (!visited[better_than[a][i]]) {
            visited[better_than[a][i]] = 1;
            sum += 1 + better_check(better_than[a][i]);
        }
    }
    return sum;
}

int worse_check(int a) {
    int sum = 0;
    for (int i=0; i<(int)worse_than[a].size(); i++) {
        if (!visited[worse_than[a][i]]) {
            visited[worse_than[a][i]] = 1;
            sum += 1 + worse_check(worse_than[a][i]);
        }
    }
    return sum;
}

int main() {
    cin>>N>>M>>X;
    better_than.resize(N + 10, vector<int>(0,0));
    worse_than.resize(N + 10, vector<int>(0,0));
    visited.resize(N + 10, 0);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin>>a>>b;
        better_than[a].push_back(b);
        worse_than[b].push_back(a);
    }

    cout<<1 + worse_check(X)<<" "<<N - better_check(X);
    return 0;
}
