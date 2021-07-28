#include <bits/stdc++.h>
using namespace std;

char bit[8], tmp[8];

// 이진수 -> 십진수
int dec(char *str) {
    int i, b, ans = 0;
    for(i=7, b=1; i >= 0; i--, b*=2)
        ans += (str[i] - '0') * b;
    return ans;
}

// 십진수 -> 이진수
char* bin(int n, char *str) {
    for(int i=7; i>=0; i--) {
        str[i] = n % 2 + '0';
        n /= 2;
    }
    return str;
}

// 보수전환
char* rev(char *str) {
    for(int i=0; i<=7; i++)
        str[i] = 'a' - str[i];
    return str;
}

int main() {
    scanf("%s", bit);
    if (bit[0]=='0')
        printf("%d", dec(bit));
    else
        printf("-%d", dec(rev(bin(dec(bit)-1, tmp))));
}
