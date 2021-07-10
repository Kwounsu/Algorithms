#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define M 7

using namespace std;

int dna_map[M+5][M+5];
bool a[M+5];
string dna[M+5];
int N, removed = -1;

// find matching sizes for each combination
void make_map(){
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int smaller_dna = min(dna[i].size(),dna[j].size());
            for(int k=1; k<=smaller_dna; k++)
                if(!dna[i].substr(dna[i].size()-k,k).compare(dna[j].substr(0,k)))
                    dna_map[i][j] = k;
            if(i == j)
                dna_map[i][j] = 0;
        }
    }
}

void dfs(int n, int sum, int cnt, int start){
    if(cnt >= N - 1) {
        removed = max(removed, sum);
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!a[i] && i != start) {
            a[i] = true;
            dfs(i, sum + dna_map[n][i], cnt+1, start);
            a[i] = false;
        }
    }
}

int main() {
    int total_sum = 0;

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>dna[i];
        total_sum += dna[i].size();
    }

    make_map();

    for(int i = 0; i < N; i++)
        dfs(i, 0, 0, i);

    cout<<total_sum - removed<<'\n';

    return 0;
}
