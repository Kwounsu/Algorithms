void bit(int x){
    for(int i = 31; i >= 0; i--){
        if (x&(1<<i)) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
}

// 함수 이름 뒤에 ll이 붙으면 long long, 아니면 int
cout<<__builtin_clzll(n)<<'\n';       // 좌측 연속 0 개수
cout<<__builtin_ctzll(n)<<'\n';       // 우측 연속 0 개수
cout<<__builtin_popcountll(n)<<'\n';  // 1 개수
cout<<__builtin_parityll(n)<<'\n';    // 1개수에 대한 패리티(짝수 or 홀수)
