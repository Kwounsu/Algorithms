#include <iostream>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    char alpha[26];
     
    for (int i = 0; i < 26; i++)
        alpha[i] = i + 65;
         
    for (char a:alpha)
        cout<<a << " ";
}
