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
}persoana;
void setpers(persoana* pers, int id, float inaltime, int greutate, float bmi) 
{
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
    char* nume[32];
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
            printf("Id-ul tau este: %d\n", nruser); 
            printf("Introdu greutatea in kg: "); scanf("%f", &greutate);
            printf("\n");
            printf("Introdu inaltimea in m: "); scanf("%f", &inaltime);
            printf("\n");
            bmi = greutate / (inaltime * inaltime);
            printf("BMI-ul tau este: %f\n", bmi);
            setpers(persoane[i], nruser, greutate, inaltime);
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
    printf("%d", persoane[0]->id);
    fclose(file1);
    fclose(file3);

    // MENIU AFISARE PERSOANE DUPA ID:

    // ========================================== //
    // Codu de jos ar trebui ca in momentu in care eu introduc id-ul unei persoane, el sa imi afiseze numele persoanei care corespunde cu id-ul introdus.
    // Ideea e ca merge doar pentru ultima persoana introdusa, nu stiu cum sa fac sa stochez celelalte persoane introduse in meniul de adaugare persoane de mai sus
    char rasp1[5];
    printf("Doresti sa cauti o persoana dupa id?\n");
    scanf("%s", &rasp1);
    char* ps1;
    ps1 = strstr(rasp1, "da");
    if (rasp1 == ps1) 
    {
        while (rasp1 > 0)
        {
            printf("Introdu id-ul unei persoane: \n");
            scanf("%d", &nruser);
            if (nruser == cid)
            {
                printf("Id-ul %d apartine utilizatorului %s\n", nruser, nume);
            }
            else if (nruser != cid) 
            {
                printf("ceva nu-i bine");
            }
            break;
        }
    }
    if (rasp1 != ps1) 
    {
        printf("Ok.\nMeniu cautare persoane dupa id inchis.");
    }
        //fclose(file1);
   //Afisare date out
    /*file1 = fopen("persoane.txt", "r");
    file3 = fopen("dateout.txt", "w");
    for (i = 0; i < nruser ; ++i) 
    {
        if (bmi > 0.01) 
        {
            fprintf(file3, "ID: %d\tNume: %s\tBMI: %f\n", nruser, persoana, bmi);
        }
    }
    

    fclose(file3);
    fclose(file1);
    */
    return 0;
}