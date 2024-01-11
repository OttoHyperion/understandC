#include <stdio.h>
#include <stdlib.h>

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

int main() {
        struct Stak *stk;
        stk = (struct Stak*)malloc(sizeof(struct Stak));
        FILE *file = fopen("t7.txt", "r");
        char c;

        while ((c = fgetc(file)) != EOF) {
                if (c >= '0' && c <= '9') {
                        error(stk, c - '0');
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                        int b = pop(stk);
                        int a = pop(stk);
                        int res;

                        switch(c) {
                                case '+':
                                        res = a + b;
                                        break;
                                case '-':
                                        res = a - b;
                                        break;
                                case '*':
                                        res = a * b;
                                        break;        
                                case '/':
                                        res = a / b;
                                        break;
                        }
                        error(stk, res);
                }
        }
        printf("%d\n", pop(stk));
        fclose(file);
        free(stk);
}
