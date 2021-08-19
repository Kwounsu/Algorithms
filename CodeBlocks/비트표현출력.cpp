void bit(ll x){
    if(x != 1) bit(x/2);
    cout<<x % 2;
}

// 함수 이름 뒤에 ll이 붙으면 long long, 아니면 int
cout<<__builtin_clzll(n)<<'\n';       // 좌측 연속 0 개수
cout<<__builtin_ctzll(n)<<'\n';       // 우측 연속 0 개수
cout<<__builtin_popcountll(n)<<'\n';  // 1 개수
cout<<__builtin_parityll(n)<<'\n';    // 1개수에 대한 패리티(짝수 or 홀수)


// 비트를 1로 만드는 방법
number |= << x;     // x번째 비트를 1로 세팅합니다.

// 비트를 0으로 만드는 방법
number &= ~(1<<x);  // x번째 비트를 0으로 세팅합니다

// 비트가 0이면 1, 1이면 0으로 만드는 방법
 number ^= 1 << x;  // x번째 비트가 1이면 0, 0이면 1으로 바꿔줍니다
 
// x번째 비트를 알아내는 방법
(number >> x ) & 1; // x번째 비트가 1이면 1을, 0면 0을 리턴합니다.
