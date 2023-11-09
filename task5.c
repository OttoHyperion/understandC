#include <stdio.h>
int main(int argc, char * argv[])

{	
	int i;

	char*file = argv[1];
	char buffer[256];
	FILE *fin = fopen(file, "r");
	if(fin)
	{
		while((fgets(buffer, 256, fin))!=NULL)
		{
			printf("%s", buffer);
		}
		fclose(fin);
	}
}