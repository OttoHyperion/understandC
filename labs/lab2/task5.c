#include <stdio.h>
#include <stdlib.h>

struct Poduct {
	char name[100];
	int price;
};

void PrSort(struct Poduct prod[], int k) {
        for (int i = 0; i < k - 1; i++) {
                for (int j = k - 1; j > i; j--) {
                        if (prod[j - 1].price > prod[j].price) {
                                struct Poduct a = prod[j-1];
                                prod[j-1] = prod[j];
                                prod[j] = a;
                        }
                }
        }
}


int main() {
	FILE *indata, *outdata;
	indata = fopen("t5in.txt", "r");
	outdata = fopen("t5out.txt", "w");
	struct Poduct prod[100];
	int count = 0;

	while (fscanf(indata, "%s %d", prod[count].name, &prod[count].price) != EOF) {
		cnt++;
	}

	PrSort(prod, count);

	for (int i = 0; i < count; i++) {
		fprintf(outdata, "%s %d\n", prod[i].name, prod[i].price);
	}

	fclose(indata);
	fclose(outdata);
	return 0;
}
