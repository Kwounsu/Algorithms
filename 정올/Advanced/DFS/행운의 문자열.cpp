#include <bits/stdc++.h>
using namespace std;

string  str;
vector<char> arr;
int len, ans;
int alpha_count[26];
bool visit[15];

int factorial(int n){
    if(n<=1) return 1;
    else return n * factorial(n-1);
}

bool is_lucky(){
    int arr_len = arr.size();
    for (int i = 1; i < arr_len; i++){
        if (arr[i-1] == arr[i]) return false;
    }
    return true;
}

void dfs(int n){
    if (n==len) {
        if (is_lucky()) ans++;
        return;
    }

    for (int i = 0; i < len; i++){
        if (!visit[i]) {
            visit[i] = true;
            arr.push_back(str[i]);
            dfs(n+1);
            visit[i] = false;
            arr.pop_back();
        }
    }
}

void input(){
    cin>>str;
    len = str.length();
    for (int i = 0; i < len; i++)
        alpha_count[str[i] - 'a']++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    dfs(0);
    // aba와 같은 중복처리
    for (int i = 0; i < 26; i++)
        if (alpha_count[i] > 1)
            ans = ans / factorial(alpha_count[i]);
    cout<<ans;
    return 0;
}
