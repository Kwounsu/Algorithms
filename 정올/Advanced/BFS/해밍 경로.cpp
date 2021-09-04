#include <bits/stdc++.h>
using namespace std;

struct data{
    int id, num;
    bool operator <(const data &r)const{
        return num<r.num;
    }
}A[100001],B[100001], t;

int path[100001], visited[100001], n, k, m;
queue <data> q;

int bsearch(int s,int e,int tg){
    while(s<=e){
        int m=(s+e)/2;
        if (B[m].num==tg) return B[m].id;
        if (B[m].num<tg) s=m+1;
        else e=m-1;
    }
    return 0;
}

// (now_idx, now_num, pre_idx)
void push(int ni,int nn, int pi){
    if (visited[ni]) return;
    visited[ni]=1;
    path[ni]=pi;
    q.push({ni,nn});
}

void bfs(){
    push(1, A[1].num, 0);
    while(!q.empty()){
        t=q.front(); q.pop();
        for (int i=0;i<k;i++){
            int num = t.num^(1<<i);
            int id = bsearch(1,n,num);
            if (id==0) continue;
            push(id,num,t.id);
        }
    }
}

void output(int j){
    if (j==1){
        printf("%d ",j);
        return;
    }
    output(path[j]);
    printf("%d ",j);
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++){
        int bin=0, a;
        for (int j=0;j<k;j++){
            scanf("%1d",&a);
            bin=bin*2+a; //Horner's method
        }
        A[i]=B[i]={i,bin};
    }

    sort(B+1,B+n+1);

    bfs();

    scanf("%d", &m);
    for (int i=1;i<=m;i++){
        scanf("%d", &k);
        if (path[k]==0) {
            printf("-1\n");
        }else {
            output(k);
            printf("\n");
        }
    }

    return 0;
}
