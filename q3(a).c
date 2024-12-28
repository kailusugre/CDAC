/*Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members of each element
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    int *arr;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

   
    arr = (int*) malloc(rows * cols * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements for the 2D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", (arr + i * cols + j));
        }
    }

    
    printf("2D Array (contiguous memory):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }

  
    free(arr);

    return 0;
}









































