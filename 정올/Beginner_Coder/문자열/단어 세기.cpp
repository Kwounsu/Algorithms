#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
struct word {
    string s;
    char cnt;
} dic[105];
 
bool comp(struct word a, struct word b) {
    return a.s < b.s;
}
 
int main() {
    string in;
    while (1) {
        getline(cin, in);
        if (in == "END")
            break;
        string w = "";
        bool ch = 0;
        int wordc = 0;
        for (int i = 0; i < 100; i++) {
            dic[i].s = "";
            dic[i].cnt = -1;
        }
        for (int i = 0; i < in.length(); i++) {
            if (in[i] == ' ') {
                if (w != "") {
                    ch = 0;
                    for (int j = 0; dic[j].cnt > 0; j++) {
                        if (w == dic[j].s) {
                            dic[j].cnt++; w = ""; ch = 1; break;
                        }
                    }
                    if (ch == 0) {
                        dic[wordc].s = w; w = ""; dic[wordc].cnt = 1; wordc++;
                    }
                }
            }
            else
                w += in[i];
        }
 
        ch = 0;
        for (int i = 0; dic[i].cnt > 0; i++) {
            if (w == dic[i].s) {
                dic[i].cnt++; w = ""; ch = 1; break;
            }
        }
        if (ch == 0) {
            dic[wordc].s = w;  w = ""; dic[wordc].cnt = 1; 
            wordc++;
        }
 
        sort(dic, dic + wordc, comp);
        for (int i = 0; i < wordc; i++)
            cout << dic[i].s << " : " << int(dic[i].cnt) << "\n";
    }
    return 0;
}
