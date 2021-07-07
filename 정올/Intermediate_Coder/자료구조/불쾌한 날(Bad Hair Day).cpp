#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long answer = 0;
    int N, num;
    cin>>N;
    vector<int> s;
    
    while (N--) {
        cin>>num;
        while (!s.empty() && s.back() <= num) s.pop_back();
        answer += s.size();
        s.push_back(num);
    }
    
    cout<<answer;
    return 0;
}
