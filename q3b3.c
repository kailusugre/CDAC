//(c) Allocate memory for array of structure variables dynamically and
//access members of each element


#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empid;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    struct Employee *employees;

    printf("Enter the number of employees: ");
    scanf("%d", &n);


    employees = (struct Employee*) malloc(n * sizeof(struct Employee));

    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].empid);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

   
    printf("\nEmployee Details:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d\n", i + 1);
        printf("ID: %d\n", employees[i].empid);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }

  
    free(employees);

    return 0;
}

