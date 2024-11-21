#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char gender;
    int phone;
    int dept_id;
};

int readEmployeeData(FILE *file, struct Employee *employees);
void getEmployeeData(char *line, struct Employee *emp);
void displayEmployeeData(struct Employee *employees, int count);

int main() {
    FILE *file = NULL;
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;

    file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    employee_count = readEmployeeData(file, employees);
    fclose(file);

    displayEmployeeData(employees, employee_count);

    return 0;
}

int readEmployeeData(FILE *file, struct Employee *employees) {
    char line[256];
    int employee_count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        getEmployeeData(line, &employees[employee_count]);
        employee_count++;

        if (employee_count >= MAX_EMPLOYEES) {
            break;
        }
    }

    return employee_count;
}

void getEmployeeData(char *line, struct Employee *emp) {
    sscanf(line, "%d|%99[^|]|%c|%d|%d", 
           &emp->id,
           emp->name,
           &emp->gender,
           &emp->phone,
           &emp->dept_id);
}

void displayEmployeeData(struct Employee *employees, int count) {
    printf("Employee Data:\n");
    printf("ID\tName\t\tGender\tPhone\tDepartment ID\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%c\t%d\t%d\n", 
               employees[i].id, 
               employees[i].name, 
               employees[i].gender, 
               employees[i].phone, 
               employees[i].dept_id);
    }
}

