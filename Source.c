#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	
	/*branch 1*/
	char rasp[10];
	printf("Simtiti durere in zona toracelui?\n");
	scanf("%s", &rasp);
	char * pch;
	pch = strstr(rasp, "da");

	/*works*/
	while (rasp == pch) {
		char rasp1[10];
		printf("Tusiti?\n", rasp1);
		scanf("%s", &rasp1);
		char* pch1;
		pch1 = strstr(rasp1, "da");

		if (rasp1 == pch1) {
			char rasp2[10];
			printf("Ce fel de tuse aveti?\n", rasp2);
			scanf("%s", &rasp2);
			char* pch2;
			pch2 = strstr(rasp2, "uscata");
			if (rasp2 != pch2) {
				printf("Atunci este posibil sa aveti dispnee\nDaca este dispnee medie aveti pneumonie\nDaca starea este grava aveti un enfizem pulmonar\n");
			}
			if (rasp2 == pch2) {
				int rasp3;
				printf("Ce temperatura aveti?\n");
				scanf("%d", &rasp3);
				if (rasp3 <= 38) {
					printf("Aveti traheita");
					break;
				}
				if (rasp3 > 38) {
					printf("Aveti bronsita");
					break;
				}
			}
			break;
		}
		break;
	}
	while (rasp != pch) {
		char xrasp[10];
		printf("Va doare in gat?\n");
		scanf("%s", &xrasp);
		char* xpch;
		xpch = strstr(xrasp, "da");
		if (xrasp == xpch) {
			float xrasp1;
			printf("Ce temperatura aveti?\n");
			scanf("%f", &xrasp1);
			if (xrasp1 <= 38.5) {
				printf("Aveti rinita\n");

			}
			if (xrasp1 > 38.5) {
				printf("Aveti amigdalita\n");

			}
		}
		break;
	}
	
	




	return 0;
}