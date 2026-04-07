#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {

        if (isdigit(argv[i][0])) {
            push(atof(argv[i]));
        }
        else {
            double b = pop();
            double a = pop();

            switch (argv[i][0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result: %.2f\n", pop());

    return 0;
}