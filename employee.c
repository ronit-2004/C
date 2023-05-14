#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int id;
    double salary;
    char job_title[50];
};

struct Employee employees[MAX_EMPLOYEES];
int num_employees = 0;

void add_employee() {
    if (num_employees == MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee employee;
    printf("Enter employee name: ");
    scanf("%s", employee.name);
    printf("Enter employee ID: ");
    scanf("%d", &employee.id);
    printf("Enter employee salary: ");
    scanf("%lf", &employee.salary);
    printf("Enter employee job title: ");
    scanf("%s", employee.job_title);

    employees[num_employees] = employee;
    num_employees++;
    printf("Employee added successfully.\n");
}

void delete_employee() {
    int id;
    printf("Enter employee ID: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            break;
        }
    }

    if (i == num_employees) {
        printf("Employee not found.\n");
        return;
    }

    for (; i < num_employees - 1; i++) {
        employees[i] = employees[i+1];
    }

    num_employees--;
    printf("Employee deleted successfully.\n");
}

void search_employee() {
    int id;
    printf("Enter employee ID: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            printf("Employee found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("ID: %d\n", employees[i].id);
            printf("Salary: %.2lf\n", employees[i].salary);
            printf("Job title: %s\n", employees[i].job_title);
            return;
        }
    }

    printf("Employee not found.\n");
}

void modify_employee() {
    int id;
    printf("Enter employee ID: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            printf("Enter new employee name (leave blank to keep current value): ");
            char new_name[50];
            scanf("%s", new_name);
            if (strlen(new_name) > 0) {
                strcpy(employees[i].name, new_name);
            }

            printf("Enter new employee ID (leave blank to keep current value): ");
            char new_id_str[50];
            scanf("%s", new_id_str);
            if (strlen(new_id_str) > 0) {
                int new_id = atoi(new_id_str);
                employees[i].id = new_id;
            }

            printf("Enter new employee salary (leave blank to keep current value): ");
            char new_salary_str[50];
            scanf("%d", new_salary_str);
            if (strlen(new_salary_str) > 0) {
                double new_salary = atof(new_salary_str);
                employees[i].salary = new_salary;
            }

            printf("Enter new employee job title (leave blank to keep current value): ");
            char new_job_title[50];
            scanf("%s", new_job_title);
            if (strlen(new_job_title) > 0) {
                strcpy(employees[i].job_title, new_job_title);
            }

            printf("Employee modified successfully.\n");
            return;
        }
    }

    printf("Employee not found.\n");
}

void print_menu() {
    printf("Employee Management System\n");
    printf("--------------------------\n");
    printf("1. Add employee\n");
    printf("2. Delete employee\n");
    printf("3. Search employee\n");
    printf("4. Modify employee\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                delete_employee();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                modify_employee();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}