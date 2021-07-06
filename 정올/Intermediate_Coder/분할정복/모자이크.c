#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// support function to sort 2d array column wise
bool cmp(pair<int, int> A, pair<int, int> B){
    return A.second < B.second;
}

int main() {
    int row, col, target, wrong, i, r, c, start_point, max_height = 0;
    scanf("%d%d%d%d", &row, &col, &target, &wrong);
    
    vector<pair<int, int>> to_fix;
    for (i = 0; i < wrong; i++){
        scanf("%d%d", &r, &c);
        to_fix.push_back(make_pair(r, c));
        max_height = max_height > r ? max_height : r;
    }
    
    // sort 2d array column wise
    sort(to_fix.begin(), to_fix.end(), cmp);
    
    // small optimization
    if(wrong <= 1){
        printf("%d\n", wrong);
        return 0;
    }
    
    // binary search
    int s = max_height, m, e = 1000000, paper;
    while (s <= e) {
        m = (s + e) / 2;
        
        paper = 1;
        start_point = to_fix[0].second;
        for (i = 1; i < wrong; i++) {
            if (to_fix[i].second >= start_point + m) {
                paper++;
                start_point = to_fix[i].second;
            }
        }
        
        if (paper > target) s = m + 1;
        else e = m - 1;
    }
    
    printf("%d\n", s);
    
    return 0;
}
