#include <bits/stdc++.h>
using namespace std;

int g, s, t, cheese[101][101], check[101][101];

int counta(){
    int sum=0;
    for(int i=1; i<=s; i++)
        for(int j=1; j<=g; j++)
            if(cheese[i][j] == 2)
                sum++;
    return sum;
}

void melt() {
    for(int i=1; i<=s; i++)
        for(int j=1; j<=g; j++)
            if(cheese[i][j] == 2)
                cheese[i][j] = 0;
}

bool is_no_cheese(){
    for(int i=1; i<=s; i++)
        for(int j=1; j<=g; j++)
            if(cheese[i][j] == 1)
                return false;
    return true;
}

void dfs(int r,int c)
{
    if(r<1 || c<1 || r>s || c>g) return;
    if(check[r][c]) return;
    
    check[r][c] = 1;
    if(cheese[r][c] == 1){
        cheese[r][c] = 2;
        return;
    }
    
    dfs(r+1, c);
    dfs(r, c+1);
    dfs(r-1, c);
    dfs(r, c-1);
}

int main(){
    int i, j, t = 0;
    scanf("%d %d",&s,&g);
    for(i=1; i<=s; i++)
        for(j=1; j<=g; j++)
            scanf("%d",&cheese[i][j]);
 
    for(i=0; ;i++){
        t++;
        for(i=1; i<=s; i++)
            for(j=1; j<=g; j++)
                check[i][j] = 0;
        dfs(1, 1);
        if(is_no_cheese()) break;
        melt();
    }
    
    printf("%d\n%d\n", t, counta());
 
    return 0;
}
