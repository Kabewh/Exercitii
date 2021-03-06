#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int main()
{
    FILE* file;
    int i;
    int c;
    int found = 0;
    int cid = 0;
    int nruser = 0;
    float greutate;
    float inaltime;
    float bmi;
    char x = "stop";
    char* persoana[32];

    file = fopen("persoane.txt", "w+");
    printf("Meniu adaugare persoane. \n\n\n");
    // AFISEAZA TOATE DATELE PERSOANELOR
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
            printf("Introdu o noua persoana: "); scanf("%s", persoana);
            printf("\n");
            printf("Id-ul tau este: %d\n", nruser); 
            printf("Introdu greutatea in kg: "); scanf("%f", &greutate);
            printf("\n");
            printf("Introdu inaltimea in m: "); scanf("%f", &inaltime);
            printf("\n");
                   
            // alt fisier |
            //            V
            bmi = greutate / (inaltime * inaltime);
            printf("BMI-ul tau este: %f\n", bmi);
            if (bmi < 18.5) {
                printf("Risc ridicat; greutate prea mica.\n");
            }
            else if (bmi >= 18.5 && bmi < 25) {
                printf("Minim; Risc scazut\n");
            }
            else if (bmi >= 25 && bmi < 30) {
                printf("Scazut; Risc mediu\n");
            }
            else if (bmi >= 30 && bmi < 35) {
                printf("Mediu; Risc ridicat\n");
            }
            else if (bmi > 35){
                printf("Risc ridicat; Greutate prea mare\n");
            }
            // Salveaza toate datele intr-un fisier "data.txt"
            fprintf(file, "Nume: %s\tID: %d\tGreutate: %f\tInaltime: %f\tBMI: %f\n", persoana, nruser, greutate, inaltime, bmi);

        }
        if (rasp != ps)
        {
            printf("Meniu adaugare persoane inchis.\n\n\nMeniu cautare dupa id.\n");
            break;
        }
    }
    fclose(file);

    file = fopen("persoaneid.txt", "w+");
    // AFISAREA UNEI PERSOANE DUPA ID:
    char rasp1[5];
    printf("Doresti sa cauti o persoana dupa id?\n");
    scanf("%s", &rasp1);
    char* ps1;
    ps1 = strstr(rasp1, "da");
    if (rasp1 == ps1) {
        i = 0;
        while (!feof(file) && !found)
        {
            ++i;
            fscanf(file, "%s\t%d\t%d\n", persoana, nruser, cid);
            printf("Introdu id-ul unei persoane: \n");
            scanf("%d", &cid);
            if (cid == nruser) {
                fprintf(file, "Id-ul %d apartine utilizatorului %s\n", cid, persoana);
                found = 1;
                break;

            }
            break;
        }
    }
    if (rasp1 != ps1) 
    {
        printf("Ok.\nMeniu cautare persoane dupa id inchis.");
    }
        fclose(file);

    
    return 0;
}