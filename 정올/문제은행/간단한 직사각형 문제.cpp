#include <iostream>
using namespace std;
 
int main() {
    int row, col;
    char a[110][110] = {0};
    scanf("%d%d", &row, &col);
     
    int i, j;
    for (i = 1; i <= row; i++)
        for (j = 1; j <= col; j++)
            scanf(" %c", &a[i][j]);
     
    int ans = 0;
    for (i = 1; i <= row; i++) 
        for (j = 1; j <= col; j++) 
            if (a[i][j] == '*' && a[i][j - 1] != '*' && a[i - 1][j] != '*')
                ans++;
     
    printf("%d\n", ans);
}
