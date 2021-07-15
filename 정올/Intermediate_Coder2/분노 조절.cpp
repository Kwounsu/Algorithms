#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n, k, x, tmp = 0;
    vector<long long> arr={0}, sum={0};
    
    //input
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>x;
        arr.push_back(x);
    }
    
    // sort
    sort(arr.begin(), arr.end());
    
    // get sums
    for (int i = 1; i < arr.size(); i++)
        sum.push_back(sum[i - 1] + arr[i]);
    
    // get tmp
    for (int i = 1; i <= k; i++)
        tmp += (i-1) * arr[i] - sum[i - 1];
    
    // get min
    long long _min = tmp;
    for (int i = k+1; i <= n; i++){
        tmp -= 2 * sum[i-1];
        tmp += 2 * sum[i-k];
        tmp += (k-1)*(arr[i] + arr[i-k]);
        _min = min(_min, tmp);
    }
    
    // output
    cout<<_min;
    
    return 0;
}
