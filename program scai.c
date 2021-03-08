#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct persoana
{
    int greutate;
    float inaltime;
    int id;
    float bmi;
    char nume[20];
}persoana;

void setpers(persoana* pers,char nume[], int id, float inaltime, int greutate, float bmi) 
{
    strcpy(pers->nume, nume);
    pers->id = id;
    pers->inaltime = inaltime;
    pers->greutate = greutate;
    pers->bmi = bmi;
}

int main()
{
    FILE* file1;
    FILE* file2;
    FILE* file3;
    int i;
    int c;
    int cid = 0;
    int nruser = 0;
    float greutate;
    float inaltime;
    float bmi;
    char x = "stop";
    char nume[20];
    persoana* persoane[20];
    file1 = fopen("persoane.txt", "w"); 
    file3 = fopen("dateout.txt", "w");  
    printf("Meniu adaugare persoane. \n\n\n");
    for (i = 0; i != x; ++i)
    {
        char rasp[5];
        printf("Doresti sa adaugi o persoana?\n");
        scanf("%s", &rasp);
        char* ps;
        ps = strstr(rasp, "da");
        if (rasp == ps)
        {
            // MENIU ADAUGARE PERSOANE
            nruser++;
            cid++;
            
            printf("Introdu o noua persoana: "); scanf("%s", nume);
            printf("\n");
            printf("%d", sizeof(nume));
            printf("Id-ul tau este: %d\n", nruser); 
            printf("Introdu greutatea in kg: "); scanf("%f", &greutate);
            printf("\n");
            printf("Introdu inaltimea in m: "); scanf("%f", &inaltime);
            printf("\n");
            bmi = greutate / (inaltime * inaltime);
            printf("BMI-ul tau este: %f\n", bmi);
            persoane[i] = malloc(sizeof(persoana));

            setpers(persoane[i], nume, nruser, greutate, inaltime, bmi);
            if (bmi < 18.5) 
            {
                printf("Risc ridicat; greutate prea mica.\n");
            }
            else if (bmi >= 18.5 && bmi < 25) 
            {
                printf("Minim; Risc scazut\n");
            }
            else if (bmi >= 25 && bmi < 30) 
            {
                printf("Scazut; Risc mediu\n");
            }
            else if (bmi >= 30 && bmi < 35) 
            {
                printf("Mediu; Risc ridicat\n");
            }
            else if (bmi > 35)
            {
                printf("Risc ridicat; Greutate prea mare\n");
            }
            // Salveaza datele intr-un fisier "persoane.txt" (input data)
            fprintf(file1, "%s\tID: %d\tGreutate: %f\tInaltime: %f\n", nume, nruser, greutate, inaltime);
            // Salveaza  datele intr-un fisier "dateout.txt" (output data)
            fprintf(file3, "ID: %d\tNume: %s\tBMI: %f\n", nruser, nume, bmi);
        }
        if (rasp != ps)
        {
            printf("Meniu adaugare persoane inchis.\n\n\nMeniu cautare dupa id.\n");
            break;
        }
    }
    fclose(file1);
    fclose(file3);

    // MENIU AFISARE PERSOANE DUPA ID:

    char rasp1[5];
    printf("Doresti sa cauti o persoana dupa id?\n");
    scanf("%s", &rasp1);
    char* ps1;
    ps1 = strstr(rasp1, "da");
    if (rasp1 == ps1) 
    {
        printf("Introduceti id-ul: ");
        scanf("%d", &nruser);
            for (int j = 0; j < i; j++)
            {
                
                if (nruser == persoane[j]->id) 
                {
                    printf("Id-ul introdus apartine persoanei: %s", persoane[j]->nume);
                }
            }
   
    }
    if (rasp1 != ps1) 
    {
        printf("Ok.\nMeniu cautare persoane dupa id inchis.");
    }
  
    return 0;
}