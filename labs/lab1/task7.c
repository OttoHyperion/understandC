#include <stdio.h>
int main(int argc, char * argv[])
{
	char*filename1 = argv[1];
	char*filename2 = "test.txt";
	char buffer[256];
	FILE*f1 = fopen(filename1, "r");
	FILE*f2 = fopen(filename2, "w");
	if(!f1 || !f2)
	{
		printf("Error");
	}
	else
	{
		while ((fgets(buffer, 256, f1))!=NULL)
		{
			fputs(buffer,f2);	
		}
	}
	fputs("Hello World! \n", f2);
	fclose(f1);
	fclose(f2);
	return 0;
}
			 
