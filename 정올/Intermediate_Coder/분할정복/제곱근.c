#include <stdio.h>

long double square_root(long double);

int main() {
    long double n;
    scanf("%Lf", &n);
    printf("%Lf\n", square_root(n));
    return 0;
}

// 바빌로니아 법(The Babylonian Method)
long double square_root(long double n) {
    long double x = 1;
    for(int i = 0; i < 100; i++) 
        x = (x + (n / x)) / 2;
    return x;
}

// unsigned long square_root(unsigned long);
 
// int main() {
//     unsigned long n;
//     scanf("%lu", &n);
//     printf("%lu\n", square_root(n));
//     return 0;
// }
 
// // 바빌로니아 법(The Babylonian Method)
// unsigned long square_root(unsigned long n) {
//     unsigned long x = 1;
//     for(int i = 0; i < 100; i++) 
//         x = (x + (n / x)) / 2;
//     return x;
// }
