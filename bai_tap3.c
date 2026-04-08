#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double x) {
    stack[++top] = x;
}

double pop() {
    return stack[top--];
}

int is_number(char *s) {
    return isdigit(s[0]);
}

int main() {
    char input[200];

    printf("Nhap bieu thuc RPN: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");

    while (token != NULL) {

        // nếu là số
        if (is_number(token)) {
            push(atof(token));
        }
        else {
            double b = pop();
            double a = pop();

            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        token = strtok(NULL, " \n");
    }

    printf("Ket qua: %.2f\n", pop());

    return 0;
}