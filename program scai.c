#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
float BMI(float weight, float height)
{
    return (weight / height * 2);
 }

int main()
{
    FILE* file;
    int i;
    char persoana[32];
    float greutate;
    float inaltime;
    int found = 0;
    char* x = "stop";


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
   
            printf("Introdu o noua persoana: "); scanf("%s", persoana);
            printf("\n");
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
   // file = fopen("persoane.txt", "rt");
   
    // Load and display data
    //i = 0;
   // while (!feof(file) && !found)
   // {
        //++i;
        //fscanf(file, "%s\n", persoana);
        //while ()
        //{
           // fprintf(file, "%d\n", id);
           // found = 1;
        //}
    //}
    // if (!found)
        // printf("Ai introdus o noua persoana cu succes.");

    // Close the file
    //fclose(file);






   
    return 0;
}