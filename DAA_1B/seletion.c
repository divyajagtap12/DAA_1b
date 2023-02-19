#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void selectionsort(int arr[], int size)
{
    int select = 0, min;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[select] > arr[j])
            {
                select = j;
            }
        }
        min = arr[select];
        arr[select] = arr[i];
        arr[i] = min;
    }
}
int main()
{

    FILE *fptr, *sPtr;
    int index = 99;
    int arr[100000];
    clock_t t;
    fptr = fopen("selection.txt", "r");
    sPtr = fopen("selection.txt", "w");
    for (int i = 0; i <= 999; i++)
    {
        for (int j = 0; j <= index; j++)
        {
            fscanf(fptr, "%d", &arr[j]);
        }
        t = clock();
        selectionsort(arr, index + 1);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;
        fprintf(sPtr, "%lf\n", time_taken);
        printf("%d\t%lf\n", (i + 1), time_taken);
        index = index + 100;
        fseek(fptr, 0, SEEK_SET);
    }
    fclose(sPtr);
    fclose(fptr);

    return 0;
}