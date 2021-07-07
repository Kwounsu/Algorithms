#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, num;
    cin>>N;
    
    vector<int> answer(N, 0);
    vector<pair<int, int>> stack;
    for (int i = 0; i < N; i++) {
        cin>>num;
        while (!stack.empty() && stack.back().second < num) {
            answer[stack.back().first] = i + 1;
            stack.pop_back();
        }
        stack.push_back(make_pair(i,num));
    }
    
    for (int i:answer)
        cout<<i<<endl;
}
