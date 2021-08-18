#include <bits/stdc++.h>
using namespace std;

int arr[25], chk[25];
 
int h3(int k){
    return(1<<k)-1;
}
 
int h4(int k){
    if(chk[k] == 0){
        if(k == 1){
            arr[k] = 1;
            return 1;
        }
        
        int min_cnt = 99999;
        for(int i=1;i<k;i++){
            int cnt = h4(i)*2 + h3(k-i);
            if(cnt < min_cnt){
                min_cnt = cnt;
                arr[k] = k-i;
            }
        }
     
        chk[k] = min_cnt;
    }
 
    return chk[k];
}
 
void hanoi3(int n, int s, int o, int e, int k){
    if(n <= 0) return;
    hanoi3(n-1, s, e, o, k-1);
    printf("%d : %c->%c\n", k, s+'A', e+'A');
    hanoi3(n-1, o, s, e, k-1);
}

void hanoi4(int n, int s, int o1, int o2, int e){
    if(n <= 0) return;
    hanoi4(n-arr[n], s, o1, e, o2);
    hanoi3(arr[n], s, o1, e, n);
    hanoi4(n-arr[n], o2, s, o1, e);
}
 
int main(){
    int N;
    scanf("%d", &N);
 
    printf("%d\n", h4(N));
    hanoi4(N, 1, 2, 3, 4);
 
    return 0;
}
