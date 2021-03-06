#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
float BMI(float greutate, float inaltime)
{
    return (greutate / inaltime * 2);
 }

int main()
{
    FILE* file;
    int i;
    int c;
    char* persoana[32];
    float greutate;
    float inaltime;
    int found = 0;
    char x = "stop";
    int cid = 0;
    int nruser = 0;


    // Open the file for writing
    file = fopen("persoane.txt", "w+");
    printf("Meniu adaugare persoane. \n\n\n");
    // Read and save data
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

            // Save data
            fprintf(file, "%s\t%d\t%f\t%f\n", persoana, nruser, greutate, inaltime);

        }
        if (rasp != ps)
        {
            printf("Meniu adaugare persoane inchis.\n\n\nMeniu cautare dupa id.\n");
            break;
        }
    }
    fclose(file);

    file = fopen("persoaneid.txt", "w");
    // AFISAREA UNEI PERSOANE DUPA ID:
    // PRINTEAZA UN SINGUR UTILIZATOR, DUPA CARE ISI DA OVERWRITE
    char rasp1[5];
    printf("Doresti sa cauti o persoana dupa id?\n");
    scanf("%s", &rasp1);
    char* ps1;
    ps1 = strstr(rasp1, "da");
    if (rasp1 == ps1)
    i = 0;
    while (!feof(file) && !found)
    {
        ++i;
        fscanf(file, "%s\t%d\t%d\n", persoana, nruser, cid);
        printf("Introdu id-ul unei persoane: \n");
        scanf("%d", &cid);
        if (nruser == cid)
        {
            fprintf(file, "Id-ul %d apartine utilizatorului %s\n", cid, persoana);
            found = 1;
            break;
          
        }
        if (nruser != cid) {
            printf("Id-ul introdus nu este valid");
            break;
        }
        break;
    }
        
        fclose(file);

    
    return 0;
}