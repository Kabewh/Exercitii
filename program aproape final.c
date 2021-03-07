#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int main()
{
    FILE* file1;
    FILE* file2;
    FILE* file3;
    int i;
    int j;
    int c;
    int found = 0;
    int counter = 0;
    int cid = 0;
    int nruser = 0;
    float greutate;
    float inaltime;
    float bmi;
    char x = "stop";
    char* persoana[32];
    
    file1 = fopen("persoane.txt", "w"); //fisier input
    file3 = fopen("dateout.txt", "w");  //fisier output
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
            counter = 0;
            printf("Introdu o noua persoana: "); scanf("%s", persoana);
            printf("\n");
            printf("Id-ul tau este: %d\n", nruser); 
            printf("Introdu greutatea in kg: "); scanf("%f", &greutate);
            printf("\n");
            printf("Introdu inaltimea in m: "); scanf("%f", &inaltime);
            printf("\n");
                   
        
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
            // Salveaza toate datele intr-un fisier "persoane.txt"
            fprintf(file1, "%s\tID: %d\tGreutate: %f\tInaltime: %f\n", persoana, nruser, greutate, inaltime);
            fprintf(file3, "ID: %d\tNume: %s\tBMI: %f\n", nruser, persoana, bmi);
        }
        if (rasp != ps)
        {
            printf("Meniu adaugare persoane inchis.\n\n\nMeniu cautare dupa id.\n");
            break;
        }
    }
    fclose(file1);
    fclose(file3);
    //file1 = fopen("persoane.txt", "r");
    // MENIU AFISARE PERSOANE DUPA ID:
    char rasp1[5];
    printf("Doresti sa cauti o persoana dupa id?\n");
    scanf("%s", &rasp1);
    char* ps1;
    ps1 = strstr(rasp1, "da");
    if (rasp1 == ps1) {
        while (rasp1 > 0)
        {
            //fscanf(file1, "%s\t%d\t%d\n", persoana, nruser, cid);
            printf("Introdu id-ul unei persoane: \n");
            scanf("%d", &counter);
            if (counter == cid) {
                printf("Id-ul %d apartine utilizatorului %s\n", cid, persoana);
                found = 1;
            }
            else if (counter != cid) {
                printf("Id-ul %d apartine utilizatorului %s\n", cid, persoana);
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