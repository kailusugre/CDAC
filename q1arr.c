#include <stdio.h>

#define MAX 100

void insertElement(int arr[], int *size, int index, int element);
void deleteElement(int arr[], int *size, int index);
int findMin(int arr[], int size);
int findMax(int arr[], int size);
void displayArray(int arr[], int size);
void reverseDisplayArray(int arr[], int size);
int searchElement(int arr[], int size, int value);
int countElements(int size);
float calculateAverage(int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    int arr[MAX], N, choice, index, element, value;
    
     
    printf("Enter the size of the array (between 1 and %d): ", MAX);       // Taking input from user 
    scanf("%d", &N);
    
    
    if (N < 1 || N > MAX) {              
        printf("!!!!!!!!!!!!!!INVALID NUMBER GIVEN!!!!!!!!\n");          // Check if input sis valid or not
        return 0;
    }

    
    for (int i = 0; i < N; i++) {   // Initialize the array with values from 1 to N          
        arr[i] = i + 1;
    }

    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at index\n");
        printf("2. Delete element at index\n");
        printf("3. Find min value\n");
        printf("4. Find max value\n");
        printf("5. Display array elements\n");
        printf("6. Reverse display array elements\n");
        printf("7. Search element in array\n");
        printf("8. Count array elements\n");
        printf("9. Calculate average of elements\n");
        printf("10. Reverse array elements\n");
        printf("11. Exit\n");

        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index and element to insert: ");   
                scanf("%d %d", &index, &element);
                insertElement(arr, &N, index, element);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteElement(arr, &N, index);
                break;
            case 3:
                printf("Min value: %d\n", findMin(arr, N));
                break;
            case 4:
                printf("Max value: %d\n", findMax(arr, N));
                break;
            case 5:
                displayArray(arr, N);              // Display the array
                break;     
            case 6:
                reverseDisplayArray(arr, N);       // Reverse display the array
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                int pos = searchElement(arr, N, value);
                if (pos != -1) {                                     
                    printf("Element found at index %d\n", pos);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                printf("Number of elements: %d\n", countElements(N));
                break;
            case 9:
                printf("Average of elements: %.2f\n", calculateAverage(arr, N));
                break;
            case 10:
                reverseArray(arr, N);
                printf("Array reversed\n");
                break;
            case 11:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void insertElement(int arr[], int *size, int index, int element) {  
    if (index < 0 || index > *size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int index) {  
    if (index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int findMin(int arr[], int size) {              
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int size) {               
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void displayArray(int arr[], int size) {          
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseDisplayArray(int arr[], int size) {     
    printf("Array elements in reverse: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchElement(int arr[], int size, int value) {   
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int countElements(int size) {                  
    return size;
}

float calculateAverage(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void reverseArray(int arr[], int size) {            
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

