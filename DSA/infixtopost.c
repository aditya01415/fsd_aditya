//wap to convert infix expression to postfix expression
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char token;

    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;  

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
