
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100000
int main()
{
    int arr[n];
    /*random numbers generate*/
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    /*numbers written in the text file */
    FILE *f1 = fopen("DAA_1b.txt", "w");
    if (f1 == NULL)
    {
        fprintf(f1, "error opening the file");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(f1, "%d\n", arr[i]);
    }
    fclose(f1);

    /*numbers read from the text file*/
    f1 = fopen("DAA_1b.txt", "r");
    if (f1 == NULL)
    {
        fprintf(f1, "error opening the file");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(f1, "%d", &arr[i]);
    }
    fclose(f1);
}