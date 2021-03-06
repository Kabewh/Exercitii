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
            // Read data

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
            fprintf(file, "%s\t%f\t%f\n", persoana, greutate, inaltime);

        }
        if (rasp != ps)
        {
            printf("Menu closed");
            break;
        }
    }

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("persoaneid.txt", "a");
   
    // Load and display data
    i = 0;
    while (!feof(file) && !found)
    {
        ++i;
        fscanf(file, "%s\t%d\t%d\n", persoana, nruser, cid);
        while (nruser == cid)
        {
            fprintf(file, "Utilizatorul %s are id-ul %d\n", persoana, cid);
            found = 1;
            if (nruser != cid) {
                break;
            }
            break;
        }
        //}
        // if (!found)
            // printf("Ai introdus o noua persoana cu succes.");

        // Close the file
        //fclose(file);






    }
    return 0;
}