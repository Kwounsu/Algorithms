#include <stdio.h>
#include <stdlib.h>
 
int stack[13], top = 0;
 
void push(int);
int pop();
 
int main() {
    int M;
    scanf("%d", &M);
 
    int i;
    for (i = 0; i < M; i++){
        char ch[15];
        scanf("%s", ch);
        char op = ch[0];
        int tmp, num1, num2;
        switch (op) {
            case '-':
                num1 = pop();
                num2 = pop();
                tmp = num2 - num1;
                push(tmp);
                break;
            case '+':
                num1 = pop();
                num2 = pop();
                tmp = num2 + num1;
                push(tmp);
                break;
            case '/':
                num1 = pop();
                num2 = pop();
                tmp = num2 / num1;
                push(tmp);
                break;
            case '*':
                num1 = pop();
                num2 = pop();
                tmp = num2 * num1;
                push(tmp);
                break;
            default:
                tmp = atoi(ch);
                push(tmp);
                break;
        }
    }
 
    int result = pop();
    printf("%d", result);
}

void push(int n){
    stack[top++] = n;
}
 
int pop(){
    int n = stack[top-1];
    stack[top-1] = NULL;
    top--;
    return n;
}
