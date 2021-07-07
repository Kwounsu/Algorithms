#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int N, L, i, j, ele;
     
    cin>>N;
    // make 2d vector of size N
    vector<vector<int>> v(N);
     
    for (i = 0; i < N; i++) {
        cin>>L;
        for (j = 0; j < L; j++) {
            cin>>ele;
            v[i].push_back(ele);
        }
    }
     
    // Get order to print
    vector<int> order;
    for (i = 0; i < N; i++){
        cin>>ele;
        order.push_back(ele);
    }
     
    // print by order
    for (int i : order){
        for (j = 0; j < v[i].size(); j++) 
            cout<< v[i][j] << " ";
        cout<<endl;
    }
}
