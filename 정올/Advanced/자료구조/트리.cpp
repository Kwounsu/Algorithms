#include <bits/stdc++.h>
using namespace std;

int n,q,a,par[100010]={-1},clr[100050],visit[100050],A[100050],level;

int LCA(int a,int b){
    level++;
    for(int i=0; i<=1000&&a>=0; i++)
    {
        visit[a]=level;
        a=par[a];
    }
 
    while(visit[b]!=level) b=par[b];
 
    return b;
}

void paint(int a,int b,int c){
    int root = LCA(a,b);
 
    while(a!=root) {clr[a]=c; a=par[a];}
    while(b!=root) {clr[b]=c; b=par[b];}
 
}

int Count(int a, int b){
    int root = LCA(a,b);
    int cnt=0;
 
    while(a!=root) {A[cnt++]=clr[a]; a=par[a];}
    while(b!=root) {A[cnt++]=clr[b]; b=par[b];}
 
    sort(A,A+cnt);
 
    cnt = unique(A,A+cnt)-A;
 
    return cnt;
}

int main(){
    scanf("%d %d",&n,&q);
 
    int r,a,b,c;
 
    for(int i=0;i<q;i++){
        scanf("%d %d %d",&r,&a,&b);
        if(r==1){
            scanf("%d",&c);
            paint(a,b,c);
        }
        else if(r==2) par[a]=b;
        else printf("%d\n", Count(a,b));
    }
 
    return 0;
}
