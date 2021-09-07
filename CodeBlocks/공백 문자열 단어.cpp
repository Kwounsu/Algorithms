int main() {
    char str[100];
    
    // 공백포함 단어입력
    scanf("%[^\n]s", str);
    
    // 단어 자르기
    char *p = strtok(str, " ");
    while(p != NULL) printf("%s\n", p), p = strtok(NULL, " ");
}
