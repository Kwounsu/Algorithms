#include <stdio.h>
 
char op[7][4] = {"?", "~", "&", "|", "^", "<<", ">>"};
 
int main(){
    printf("%s\n",     op[2]);               /// (1)
    printf("%s%s\n",   op[1], op[2]);        /// (2)
    printf("%s\n",     op[5]);               /// (3)
    printf("%s%s%s\n", op[6], op[2], op[5]); /// (4)
    printf("%s%s%s\n", op[4], op[4], op[4]); /// (5)
    printf("%s%s\n",   op[6], op[2]);        /// (6)
    printf("%s%s%s\n", op[2], op[1], op[5]); /// (7)
    printf("%s%s\n",   op[4], op[5]);        /// (8)
    printf("%s\n",     op[2]);               /// (9)
    printf("%s%s\n",   op[4], op[2]);        /// (10)
    
    return 0;
}

/*
(1) a가 홀수인지 if문과 비트 연산자를 이용하여 판별하고자 한다. 
   if(a & 1){}   /// c, c++인 경우 
   if((a & 1) == 1 )) {} /// java의 경우

(2) a가 짝수인지 if문과 비트 연산자를 이용하여 판별하고자 한다.
   if(~a & 1) {} /// c, c++인 경우
   if((~a & 1) == 1 )) {} /// java의 경우

(3) a와 2의 k제곱을 곱한 결과(결과는 int 범위를 넘지 않는다.)를 구하고자 한다. 
   result = a << k;

(4) a를 2의 k제곱으로 나눈 몫 p와 나머지 r 을 구하고자 한다.
   p = a >> k, r = a & ((1 << k) - 1);

(5) 다음은 a와 b의 값을 서로 바꾸는 코드이다.
   a = a ^ b, b = a ^ b, a = a ^ b;

(6) a의 k번째(2의 k제곱 자리) 비트가 0인지 1인지 알아보고자 한다.
   result = (a >> k) & 1;
 
(7) a의 k번째(2의 k제곱 자리) 비트만 0으로 바꾸고자 한다.
   a = a & (~(1 << k));

(8) a의 k번째(2의 k제곱 자리) 비트만 0이면 1로, 1이면 0으로 바꾸고자 한다.
   a = a ^ (1 << k);

(9) a가 2의 제곱수인지 판별하고자 한다.
   result = a & (a - 1);
   if( a > 0 && result==0) printf("%d is the power of 2.\n", a);  

(10) a와 b의 같은 자리 비트를 비교한 결과 서로 다른 비트가 1개 이하인지 알아보고자 한다.
     bit = a ^ b; result = bit & (bit -1);
    if(result==0) printf("%d and %d differ by below 1bit.\n", a, b);
*/
