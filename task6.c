#include <stdio.h>
int main(void)
{
	char*filename1 = "test.txt";
	char*filename2 = "test2.txt";
	char buffer[256];
	FILE*f1 = fopen(filename1, "r");
	FILE*f2 = fopen(filename2, "w");
	if(!f1 || !f2)
	{
		printf("Error");
	}
	else
	{
		for(int i = 0; i < 3; i++)
		{
			if(fgets(buffer, sizeof(buffer), f1)!=NULL)
			{
				fputs(buffer,f2);
			}
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
			 
