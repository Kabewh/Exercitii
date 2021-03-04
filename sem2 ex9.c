#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int latime = 0, lungime = 0, a = 0, b = 0;
	printf("Introdu lungimea: ");
	scanf("%d", &latime);
	printf("Introdu latimea: ");
	scanf("%d", &lungime);

	for (b = 0; b != latime; b++) {
		for (a = 0; a != lungime; a++) {
			if ((b == 0) || (b == latime - 1) || (a == lungime - 1) || (a == 0)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

   return 0;
}