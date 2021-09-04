#include <bits/stdc++.h>
using namespace std;
 
struct d{int col,cnt;};
int n, j, sum, ans, k, color;
string input;
vector<d> v;  // white:0, red:1, blue:2
 
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
 
    cin>>n>>input;
 
    for (int i=0; i<n; i=j) {
        while (j < n && input[i] == input[j]) j++;
        if (input[i] == 'r')
            v.push_back({1, j-i});
        else if (input[i] == 'b')
            v.push_back({2, j-i});
        else
            v.push_back({0, j-i});
    }
 
    k = v.size();
    for (int i=0; i<k; i++) {
        j = i, sum = 0;
        while (sum < n && v[j].col == 0) {
            sum += v[j].cnt;
            j = (j + 1) % k;
        }
        color = v[j].col;
        while (sum < n && (v[j].col == color || v[j].col == 0)) {
            sum += v[j].cnt;
            j = (j + 1) % k;
        }
        while (sum < n && v[j].col != color) {
            sum += v[j].cnt;
            j = (j + 1) % k;
        }
        ans = max(ans, sum);
    }
 
    cout<<ans<<'\n';
 
    return 0;
}
