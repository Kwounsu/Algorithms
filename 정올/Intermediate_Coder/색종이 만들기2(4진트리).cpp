#include <stdio.h>

int arr[1030][1030];

void solution(int sx,int sy,int fx,int fy) {
    int flag=0;
    int c=arr[sx][sy];
    for(int i=sx;i<fx;i++){
        for(int j=sy;j<fy;j++){
            if(c != arr[i][j]) {
                flag=1;
                break;
            }
        }
    }
    
    if(flag==0){
        if(c==0) printf("0");
        else printf("1");
        return;
    }
    else printf("X");
    
    int midx=(sx+fx)/2;
    int midy=(sy+fy)/2;
 
    solution(sx,sy,midx,midy);
    solution(sx,midy,midx,fy);
    solution(midx,sy,fx,midy);
    solution(midx,midy,fx,fy);
}

int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    
    solution(0, 0, N, N);
    return 0;
}
