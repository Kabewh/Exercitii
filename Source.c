#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct persoana
{
	int greutate;
	float inaltime;
	int id;
	char nume[20];
}persoana;

void setpers(persoana* pers, char nume[], int id, float inaltime, int greutate)
{
	strcpy(pers->nume, nume);
	pers->id = id;
	pers->inaltime = inaltime;
	pers->greutate = greutate;
}

int adaugare_persoane()
{
	int i;
	int c;
	int cid = 0;
	int nruser = 0;
	float greutate;
	float inaltime;
	float bmi;
	int x = 0;
	char nume[20];
	persoana* persoane[20];
	printf("Meniu adaugare persoane\n\n");
	for (i = 0; i >= x; ++i)
	{
		nruser++;
		cid++;
		printf("Introdu o noua persoana: "); scanf("%s", nume);
		printf("\n");
		//printf("%d", sizeof(nume));
		printf("Id-ul tau este: %d\n", nruser);
		printf("Introdu greutatea in kg: "); scanf("%f", &greutate);
		printf("\n");
		printf("Introdu inaltimea in m: "); scanf("%f", &inaltime);
		printf("\n");
		printf("Persoana noua adaugata!\n");
		persoane[i] = malloc(sizeof(persoana));

		setpers(persoane[i], nume, nruser, greutate, inaltime);
		break;
	}


}

int main()
{
	int alegere;
	printf("MENIU PRINCIPAL\n");
	printf("Apasati pe tastele de la 1 la 5 pentru a accesa optiunile: \n");
	printf("1.Adaugare persoana noua.\n");
	printf("2.Calculeaza BMI-ul pentru toate persoanele.\n");
	printf("3.Afiseaza numele unei persoane dupa ID.\n");
	printf("4.Afiseaza valorile medii pentru toate persoanele (greutate, inaltime si BMI)\n");
	printf("5.Afiseaza integral toate datele persoanelor\n");
	printf("Introdu tasta: ");
	scanf("%d", &alegere);
	switch (alegere)
	{
	case 1:
	{
		adaugare_persoane();
		break;
	}
	case 2:
	{
		printf("Ai ales calculeaza BMI-ul pentru toate persoanele");
		break;
	}
	case 3:
	{
		printf("Ai ales afiseaza numele unei persoane dupa ID");
		break;
	}
	case 4:
	{
		printf("Ai ales afiseaza valorile medii pentru toate persoanele (greutate, inaltime si BMI)");
		break;
	}
	case 5:
	{
		printf("Ai ales afiseaza integral toate datele persoanelor");
		break;
	}
	}





	return 0;
}