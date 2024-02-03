#include <time.h>
#include <stdio.h>

int main(void)
{
	clock_t start, end;
	long i = 48000000;
	i *= 100;
	start = clock();
	while (i--)
		;
	end = clock();
	printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	return (0);
}


