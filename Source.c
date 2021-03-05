#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
float BMI(float weight, float height)
{
    float result = weight / height * 2;
    return result;
}

int main()
{
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int result_len;


    float bmi_result;
    float results_bmi[50];
    float greutate_totata = 0;
    float inaltime_totata = 0;
    float bmi_totata = 0;

    char* results_id[50][3];
    char* results_name[50][50];

    char* singleLine_arr[4];
    char* singleLine[50];
    char* str_token;

    FILE* fPointer;
    fPointer = fopen("test.txt", "r");

    while (!feof(fPointer))
    {
        fgets(singleLine, 50, fPointer);
        str_token = strtok(singleLine, ",");

        counter = 0;
        while (str_token != NULL)
        {
            ////remove \n
            str_token[strcspn(str_token, "\n")] = 0;
            //// add the value to the array
            singleLine_arr[counter++] = str_token;
            str_token = strtok(NULL, ",");
        }

        bmi_result = BMI(atof(singleLine_arr[2]), atof(singleLine_arr[3]));
        greutate_totata = greutate_totata + atof(singleLine_arr[3]);
        inaltime_totata = inaltime_totata + atof(singleLine_arr[2]);

        strcpy(results_id[counter2], singleLine_arr[0]);
        strcpy(results_name[counter2], singleLine_arr[1]);
        results_bmi[counter2] = bmi_result;
        counter2++;

    }

    fclose(fPointer);

    FILE* fPointer2;
    fPointer2 = fopen("result1.txt", "w+");
    result_len = sizeof(results_bmi) / sizeof(results_bmi[0]);

    for (int j = 0; j < result_len; j++)
    {
        if (results_bmi[j] > 0.01)
        {

            bmi_totata = results_bmi[0] + results_bmi[1] + results_bmi[2] + results_bmi[3] + results_bmi[4] + results_bmi[5];

            fprintf(fPointer2, "Id este: %s, Name este: %s, BMI este: %f\n", results_id[j], results_name[j], results_bmi[j]);

        }

    }
    fprintf(fPointer2, "%s\n", "----------------");
    fprintf(fPointer2, "Medii greutate este: %f\n", greutate_totata / counter2);
    fprintf(fPointer2, "Medii inaltime este: %f\n", inaltime_totata / counter2);
    fprintf(fPointer2, "Medii BMI este: %f\n", bmi_totata / counter2);

    fclose(fPointer2);
    return 0;

}