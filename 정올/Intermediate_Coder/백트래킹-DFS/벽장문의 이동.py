#include <stdio.h>
#include <stdlib.h>

using namespace std;

int arr[100];
int n, m, answer = 2e7;

void dfs(int lev,int l,int r,int cost){
    if(l>=r) return;
    if(lev==m){
        if(answer>cost && cost!=0) answer=cost;
        return;
    }
    dfs(lev+1, arr[lev], r, abs(l-arr[lev]) + cost);
    dfs(lev+1, l, arr[lev], abs(r-arr[lev]) + cost);
}

int main(){
    int i, l, r;
    
    scanf("%d",&n);
    scanf("%d%d",&l,&r);
    scanf("%d",&m);
    for(i=0; i<m; i++) scanf("%d",&arr[i]);
    
    dfs(0, l, r, 0);
    printf("%d", answer);
    
    return 0;
}
