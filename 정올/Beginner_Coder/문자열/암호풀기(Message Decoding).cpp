#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
  
int main() {
    char key[27], str[85];
    scanf("%s\n", key);  // \n 없으면 str이 입력을 못받음.
    fgets(str, 85, stdin);
    char* s = strtok(str, "\n\r");
    
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == ' ') printf(" ");
        else if (s[i] < 'a') printf("%c", key[s[i] - 65] - 32);
        else printf("%c", key[s[i] - 97]);
    }
}
