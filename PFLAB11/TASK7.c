#include <stdio.h>
#include <string.h>

struct Course {
    char courseID[10];
    char courseName[50];
    char instructorName[50];
    int credits;
};

struct Department {
    char departmentName[50];
    int courseCount;
    struct Course courses[10];
};

void addDepartment(struct Department departments[], int *deptCount) {
    if (*deptCount >= 5) {
        printf("Maximum number of departments reached.\n");
        return;
    }
    printf("Enter Department Name: ");
    scanf(" %[^\n]", departments[*deptCount].departmentName);
    departments[*deptCount].courseCount = 0;
    (*deptCount)++;
    printf("Department added successfully.\n");
}

void addCourse(struct Department *department) {
    if (department->courseCount >= 10) {
        printf("Maximum number of courses reached for this department.\n");
        return;
    }
    struct Course *course = &department->courses[department->courseCount];
    printf("Enter Course ID: ");
    scanf("%s", course->courseID);
    printf("Enter Course Name: ");
    scanf(" %[^\n]", course->courseName);
    printf("Enter Instructor Name: ");
    scanf(" %[^\n]", course->instructorName);
    printf("Enter Credits: ");
    scanf("%d", &course->credits);
    department->courseCount++;
    printf("Course added successfully.\n");
}

void displayDetails(struct Department departments[], int deptCount) {
    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i].departmentName);
        printf("Courses:\n");
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf("  Course ID: %s\n", course->courseID);
            printf("  Course Name: %s\n", course->courseName);
            printf("  Instructor: %s\n", course->instructorName);
            printf("  Credits: %d\n", course->credits);
        }
    }
}

void calculateTotalCredits(struct Department *department) {
    int totalCredits = 0;
    for (int i = 0; i < department->courseCount; i++) {
        totalCredits += department->courses[i].credits;
    }
    printf("Total Credits for Department %s: %d\n", department->departmentName, totalCredits);
}

int main() {
    struct Department departments[5];
    int deptCount = 0;
    int choice, deptIndex;

    while (1) {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to a Department\n");
        printf("3. Display All Details\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(departments, &deptCount);
                break;
            case 2:
                printf("Enter Department Index (0 to %d): ", deptCount - 1);
                scanf("%d", &deptIndex);
                if (deptIndex >= 0 && deptIndex < deptCount) {
                    addCourse(&departments[deptIndex]);
                } else {
                    printf("Invalid Department Index.\n");
                }
                break;
            case 3:
                displayDetails(departments, deptCount);
                break;
            case 4:
                printf("Enter Department Index (0 to %d): ", deptCount - 1);
                scanf("%d", &deptIndex);
                if (deptIndex >= 0 && deptIndex < deptCount) {
                    calculateTotalCredits(&departments[deptIndex]);
                } else {
                    printf("Invalid Department Index.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

