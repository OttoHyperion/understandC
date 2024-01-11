#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int a = 0;
	int b = 1;
	int n = atoi(argv[1]);
	float mas[n];

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		mas[i] = (float)rand() / RAND_MAX;
		printf("%.2f ", mas[i]);
	}
	return 0;
}
