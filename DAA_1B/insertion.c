#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void insertionsort(int arr[], int size)
{
    int index;
    for (int i = 0; i < size; i++)
    {
        for (int j = i - 1; j >= 0 && j < size; j--)
        {
            if (arr[j + 1] < arr[j])
            {
                index = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = index;
            }
        }
    }
}
int main()
{

    FILE *fptr, *sPtr;
    int index = 99;
    int arr[100000];
    clock_t t;
    fptr = fopen("DAA_1b.txt", "r");
    sPtr = fopen("ins.txt", "w");
    for (int i = 0; i <= 999; i++)
    {
        for (int j = 0; j <= index; j++)
        {
            fscanf(fptr, "%d", &arr[j]);
        }
        t = clock();
        insertionsort(arr, index + 1);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;
        fprintf(sPtr, "%lf\n", time_taken);
        printf("%d\t%lf\n", (i + 1), time_taken); /*i+1 : number of blocks ,
        every block numbers sorted are +100*/
        index = index + 100;
        fseek(fptr, 0, SEEK_SET);
    }
    fclose(sPtr);
    fclose(fptr);

    return 0;
}
