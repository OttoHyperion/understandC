#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sort(float *mas, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int k = n - 1; k > i; k--) {
			if (mas[k - 1] > mas[k]) {
				float b = mas[k-1];
				mas[k-1] = mas[k];
				mas[k] = b;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	float arg1 = atof(argv[2]);
	float arg2 = atof(argv[3]);
	float mas[n];
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		mas[i] = (float)rand() / RAND_MAX * (arg2 - arg1) + arg1;
		printf("%.1f ", mas[i]);
	}
	FILE *file = fopen("t4out", "w");
	ArraySort(mas, n);
	for (int i = 0; i < n; i++) {
		fprintf(file, "%.1f ", mas[i]);
	}
	printf("\n");
	return 0;
}
