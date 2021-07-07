#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void vector_func(vector<int> v){
    int a, tmp;
    char com;
    while (1) {
        cin>>com;
        switch (com) {
            // i a: 현재 시점 벡터의 맨 뒤에 원소 a를 삽입하여 벡터의 크기를 하나 늘린다. (insert)
            case 'i':
                cin>>a;
                v.push_back(a);
                break;
                 
        // r: 현재 시점 벡터의 맨 뒤에 있는 원소를 삭제하고, 벡터의 크기를 하나 줄인다. (remove)이때, 벡터의 크기가 0이면 아무 일도 하지 않는다.
            case 'r':
                if (!v.empty())
                    v.pop_back();
                break;
 
        // s: 현재 시점 벡터를 오름차순으로 정렬한다. (sort)
            case 's':
                sort(v.begin(), v.end());
                break;
 
        // t: 현재 시점 벡터의 맨 앞에 있는 원소와 맨 뒤에 있는 원소를 맞바꾼다.(trade) 이때 벡터의 크기가 0이면 아무 일도 하지 않는다.
            case 't':
                if (!v.empty()){
                    tmp = v.front();
                    v.front() = v.back();
                    v.back() = tmp;
                }
                break;
 
        // e: 현재 시점 벡터를 앞에서부터 출력하고, 프로그램을 종료한다.(end)
            case 'e':
                for (int i:v)
                    cout<<i<<" ";
                return;
        }
    }
}
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int n, x;
     
    // 초기 크기가 n인 정수형 벡터를 하나 만들고, 각 n개의 원소들의 초기값을 x로 초기화한다.
    cin>>n>>x;
    vector<int> v(n, x);
     
    vector_func(v);
}
