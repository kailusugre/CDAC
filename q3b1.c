//(b) Allocating 2D array dynamically
//(1) contiguous rows with fixed no.of cols,

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j;
    int **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    
    arr = (int**) malloc(rows * sizeof(int*));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < rows; i++) 
    {
        int cols;
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &cols);
        arr[i] = (int*) malloc(cols * sizeof(int));

      
        printf("Enter elements for row %d:\n", i + 1);
        for (j = 0; j < cols; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }

    
     printf("2D Array (non-contiguous memory):\n");
     for (i = 0; i < rows; i++)
     {
        int cols;
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &cols);

        for (j = 0; j < cols; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

   
      for (i = 0; i < rows; i++) 
    {
        free(arr[i]); 
    }
       free(arr); 

    return 0;
}

