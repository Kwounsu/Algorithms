#include <stdio.h>

char arr[100000];

int sticks();

int main() {
    scanf("%s", arr);
    printf("%d\n", sticks());
    return 0;
}

int sticks() {
    int stick_to_cut = 0, cutted_stick = 0, laser = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '(') {
            stick_to_cut++;
            laser = 1;
        } else if (arr[i] == ')' && laser == 1) {
            cutted_stick += --stick_to_cut;
            laser = 0;
        } else {
            cutted_stick++;
            stick_to_cut--;
        }
    }
    
    return cutted_stick;
}
