#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; // push
        } else {
            if (top == -1) return false; // stack empty

            char open = stack[top--]; // pop
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '['))
                return false;
        }
    }

    return top == -1; // stack should be empty
}
