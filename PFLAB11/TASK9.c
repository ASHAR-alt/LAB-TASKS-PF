#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 30

struct Student {
    char studentName[50];
    int studentID;
};

struct Instructor {
    char instructorName[50];
    int instructorID;
};

struct Course {
    char courseName[50];
    char courseID[10];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int studentCount;
};

struct Department {
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

void addDepartment(struct Department departments[], int *deptCount) {
    if (*deptCount < MAX_DEPARTMENTS) {
        printf("Enter Department Name: ");
        scanf(" %[^\n]", departments[*deptCount].departmentName);
        departments[*deptCount].courseCount = 0;
        (*deptCount)++;
    }
}

void addCourse(struct Department *department) {
    if (department->courseCount < MAX_COURSES) {
        struct Course *course = &department->courses[department->courseCount];
        printf("Enter Course Name: ");
        scanf(" %[^\n]", course->courseName);
        printf("Enter Course ID: ");
        scanf(" %[^\n]", course->courseID);
        printf("Enter Instructor Name: ");
        scanf(" %[^\n]", course->instructor.instructorName);
        printf("Enter Instructor ID: ");
        scanf("%d", &course->instructor.instructorID);
        course->studentCount = 0;
        department->courseCount++;
    }
}

void addStudent(struct Course *course) {
    if (course->studentCount < MAX_STUDENTS) {
        struct Student *student = &course->students[course->studentCount];
        printf("Enter Student Name: ");
        scanf(" %[^\n]", student->studentName);
        printf("Enter Student ID: ");
        scanf("%d", &student->studentID);
        course->studentCount++;
    }
}

void displayDetails(struct Department departments[], int deptCount) {
    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i].departmentName);
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf("  Course: %s (ID: %s)\n", course->courseName, course->courseID);
            printf("    Instructor: %s (ID: %d)\n", course->instructor.instructorName, course->instructor.instructorID);
            printf("    Enrolled Students:\n");
            for (int k = 0; k < course->studentCount; k++) {
                printf("      %d. %s (ID: %d)\n", k + 1, course->students[k].studentName, course->students[k].studentID);
            }
        }
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int deptCount = 0, choice, deptIndex, courseIndex;
    
    while (1) {
        printf("\n1. Add Department\n2. Add Course\n3. Add Student\n4. Display All Details\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(departments, &deptCount);
                break;
            case 2:
                printf("Enter Department Index: ");
                scanf("%d", &deptIndex);
                if (deptIndex >= 0 && deptIndex < deptCount) {
                    addCourse(&departments[deptIndex]);
                }
                break;
            case 3:
                printf("Enter Department Index: ");
                scanf("%d", &deptIndex);
                if (deptIndex >= 0 && deptIndex < deptCount) {
                    printf("Enter Course Index: ");
                    scanf("%d", &courseIndex);
                    if (courseIndex >= 0 && courseIndex < departments[deptIndex].courseCount) {
                        addStudent(&departments[deptIndex].courses[courseIndex]);
                    }
                }
                break;
            case 4:
                displayDetails(departments, deptCount);
                break;
            case 5:
                return 0;
        }
    }
}

