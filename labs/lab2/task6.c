#include <stdio.h>
#include <stdlib.h>

struct Stak {
	int data[100];
	int top;
};

int full(struct Stak *stk){
   if(stk->top == 100)
      return 1;
   else
      return 0;
}

void error(struct Stak *stk, int k) {
	if (!full(stk)) {
		stk->data[stk->top] = k;
		stk->top++;
	} else {
		printf("Stak is full\n");
	}
}

int TopNumber(struct Stak *stk) {
	if (stk->top > 0) {
		return stk->data[stk->top-1];
	} else {
		printf("Stak is empty\n");
		return 0;
	}
}
int pop(struct Stak *stk) {
	int a;
	if (stk->top > 0) {
		stk->top--;
		a = stk->data[stk->top];
		return a;
	} else {
		printf("Stak is empty\n");
	}
}

void Print(struct Stak *stk) {
	int a;
	n = stk->top;
	while (a > 0) {
		a--;
		printf("%d\n", stk->data[a]);
	}
}


int main() {
	struct Stak *stk;
	int n = 5;
	int k;
	stk = (struct Stak*)malloc(sizeof(struct Stak));

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		push(stk, k);
	}
	pop(stk);
	Print(stk);
	return 0;
}
