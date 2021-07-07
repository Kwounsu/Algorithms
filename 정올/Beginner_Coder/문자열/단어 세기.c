#include <stdio.h>
#include <string.h>

char str[210], word[100][210], wcnt, wlen, len;
  
void tokenize() {
    wcnt = wlen = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            word[wcnt++][wlen] = '\0';
            wlen = 0;
        } else{
            word[wcnt][wlen++] = str[i];
        }
    }
    word[wcnt++][wlen] = '\0';
}

void _sort() {
    char tmp[210];
    for(int i=0; i<wcnt; i++){
        for(int j=0; j<wcnt-1-i; j++){
            if(strcmp(word[j], word[j+1]) > 0){
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j+1]);
                strcpy(word[j+1], tmp);
            }
        }
    }
}

void output() {
    int cnt = 1;
    for (int i = 0; i < wcnt; i++) {
        if (strcmp(word[i], word[i + 1]) == 0)
            cnt++;
        else {
            printf("%s : %d\n", word[i], cnt);
            cnt = 1;
        }
    }
}

int main() {
    while (1) {
        fgets(str, 210, stdin);
        
        if (strcmp(str, "END") == 0) break;
        
        // int len = strlen(str);
        // while (str[len - 1] == '\n' || str[len - 1] == '\r')
        //     str[--len] = '\0';
        char* s = strtok(str, "\n\r");
        
        tokenize();
        _sort();
        output();
    }
    return 0;
}
