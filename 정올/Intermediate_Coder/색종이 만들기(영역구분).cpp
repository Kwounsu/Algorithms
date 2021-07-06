#include<cstdio>
#include<iostream>
using namespace std;
  
int arr[128][128];
int w=0, b=0;
  
void solution(int r, int c, int n) {
    int color = arr[r][c];
    bool isMatch = true;
     
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[i][j] != color){
                isMatch = false;
                break;
            }
        }
        if (!isMatch) break;
    }
     
    if (!isMatch) {
        solution(r, c, n / 2);
        solution(r, c + n / 2, n / 2);
        solution(r + n / 2, c, n / 2);
        solution(r + n / 2, c + n / 2, n / 2);
    } else {
        if (color == 1) b++;
        else w++;
    }
}
 
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
  
    solution(0, 0, N);
     
    printf("%d\n%d\n",w,b);
  
    return 0;
}
