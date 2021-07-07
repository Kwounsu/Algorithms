#include <iostream>
#include <vector>
#include <algorithm>
  
using namespace std;
  
int main() {
    vector<pair<int, int>> a;
    vector<pair<int, int>> s;
    int N, num;
    scanf("%d",&N);
    vector<int> answer(N, 0);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        a.push_back({i + 1, num});
    }
    
    for (int i = 0; i < N; i++) {
        pair<int, int> item = a.back();
        a.pop_back();
        while (!s.empty() && s.back().second < item.second) {
            answer[s.back().first - 1] = item.first;
            s.pop_back();
        }
        s.push_back({item.first, item.second});
    }
    
    for (int i:answer)
        printf("%d ", i);
}
