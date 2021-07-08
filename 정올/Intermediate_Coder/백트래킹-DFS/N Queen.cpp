#include <iostream>
using namespace std;

int n;
int _col[15] = {0}, _d1[30] = {0}, _d2[30] = {0};

int nqueen(int row) {
    if (row == n) return 1;
    int count = 0;
    int d1, d2;
    
    for (int i = 0; i < n; i++) {
        d1 = row + i;
        d2 = n + row - i - 1;
        if (_col[i] == 0 && _d1[d1] == 0 && _d2[d2] == 0) {
            _col[i] = 1; _d1[d1] = 1; _d2[d2] = 1;
            count += nqueen(row + 1);
            _col[i] = 0; _d1[d1] = 0; _d2[d2] = 0;
        }
    }
    
    return count;
}
    
int main() {
    scanf("%d", &n);
    printf("%d\n", nqueen(0));
}
