#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stak {
        int data[10];
        int top;
};
int full(struct Stak *stk) {
        if (stk -> top == 10) {
                return 1;
        } else {
                return 0;
        }
}

int empty(struct Stak *stk) {
        if (stk -> top == -1) {
                return 1;
        } else {
                return 0;
        }
}

char error(struct Stak *stk, int k) {
        if (!full(stk)) {
                stk -> top += 1;
                stk -> data[stk -> top] = k;
        } else {
                printf("Stak is full\n");
        }
}

char pop(struct Stack *stk) {
        int a;
        if (!empty(stk)) {
                a = stk -> data[stk -> top];
                stk -> top -= 1;
                return a;
        } else {
                printf("Stak is empty\n");
        }
}

int Operator(char oper) {
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
                return 1;
        } else {
                return 0;
        }
}

int Priority(char oper) {
        if (oper == '*' || oper == '/') {
                return 2;
        } else if (oper == '+' || oper == '-') {
                return 1;
        } else {
                return 0;
        }
}

void InfixToPostfix(char infix[], char postfix[]) {
        struct Stak *stk;
        stk = (struct Stak*)malloc(sizeof(struct Stak));
        int i, j;
        char symbol, item;
        error(stk, '(');
        strcat(infix,")");
        i = 0;
        j = 0;
        symbol = infix[i];

        while (symbol != '\0') {
                if (symbol == '(') {
                        error(stk, symbol);

                } else if (symbol >= '0' && symbol <= '9' || symbol == '.') {
                        postfix[j++] = symbol;

                } else if (Operator(symbol)) {
                        item = pop(stk);
                        while (Operator(item) && Priority(item) >= Priority(symbol)) {
                                postfix[j++] = item;
                                item = pop(stk);
                        }
                        error(stk, item);
                        error(stk, symbol);

                } else if (symbol == ')') {
                        item = pop(stk);
                        while (item != '(') {
                                postfix[j++] = item;
                                item = pop(stk);
                        }
                }
                i++;
                symbol = infix[i];
        }
        postfix[j] = '\0';
}

int main() {
        char infix[10],postfix[10];
        fgets(infix, sizeof(infix), stdin);
        InfixToPostfix(infix, postfix);
        printf("%s\n", postfix);
        return 0;
}
