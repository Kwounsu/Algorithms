#include <iostream>
#include <vector>
#include <algorithm>
  
using namespace std;
  
int main() {
    vector<pair<int, int>> stack;
    int N, num;
    scanf("%d",&N);
      
    vector<int> answer(N, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d",&num);
        while (!stack.empty() && stack.back().second < num) {
            answer[stack.back().first] = i + 1;
            stack.pop_back();
        }
        stack.push_back({i,num});
    }
      
    for (int i:answer)
        printf("%d\n" , i);
}
