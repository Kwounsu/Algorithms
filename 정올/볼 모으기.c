#include<stdio.h>

int main(void) {
    // input
    int i, n;
    scanf("%d", &n);
    
    int r=0, b=0;
    char arr[n];
    for (i = 0; i < n; i++){
        scanf(" %c", &arr[i]);
        if (arr[i] == 'R') r++;
        else b++;
    }
    
    // count edge balls
    char start = arr[0], end = arr[n - 1];
    int startCntR = 0, endCntR = 0;
    int startCntB = 0, endCntB = 0;
    for (i = 1; i < n; i++) {
        if (start == 'R') startCntR++;
        else startCntB++;
        if (arr[i] != start)
            break;
    }
    for (i = n - 2; i >= 0; i--) {
        if (end == 'R') endCntR++;
        else endCntB++;
        if (arr[i] != end)
            break;
    }
    
    // count ball moves
    int blue, red;
    blue = startCntB > endCntB ? b - startCntB : b - endCntB;
    red = startCntR > endCntR ? r - startCntR : r - endCntR;
    
    // print
    int result = blue < red ? blue : red;
    printf("%d\n", result >= 0 ? result : 0);
    
    return 0;
}
