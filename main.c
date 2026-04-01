#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	srand(time(NULL));
	int r1 = rand() % 100;

	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	int r2 = ts.tv_nsec % 100;

	int stack_var;
	int r3 = ((intptr_t)&stack_var) % 100;

	int r4 = getpid() % 100;

	printf("Metoda 1: %d\n", r1);
	printf("Metoda 2: %d\n", r2);
	printf("Metoda 3: %d\n", r3);
	printf("Metoda 4: %d\n", r4);

	return 0;
}
