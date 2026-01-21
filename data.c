#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
    long sapID;
    char rollNo[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
    float cgpa;
};

struct Student students[100];
int totalStudents = 0;

void addStudent();
void searchStudent();
void calculateCGPA(int index);
void calculateAllCGPA();
void averageCGPAByYear();
void displayAllStudents();
void deleteStudent();
void sortBySAPID();
void sortByName();
void displaySingleStudent(int index);
void initializeSampleData();

int main() {
    int choice;
    
    initializeSampleData();
    
    while (1) {
        printf("\n");
        printf("========================================\n");
        printf("   UNIVERSITY STUDENT RECORD SYSTEM    \n");
        printf("========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Search Student Record\n");
        printf("3. Calculate CGPA of a Student\n");
        printf("4. Average CGPA by Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student Record\n");
        printf("7. Display Students Sorted by SAP ID\n");
        printf("8. Display Students Sorted by Name\n");
        printf("9. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                calculateAllCGPA();
                break;
            case 4:
                averageCGPAByYear();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                sortBySAPID();
                break;
            case 8:
                sortByName();
                break;
            case 9:
                printf("\nThank you for using the system!\n");
                printf("Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter 1-9.\n");
        }
    }
    
    return 0;
}

void initializeSampleData() {
    students[0].sapID = 500012001;
    strcpy(students[0].rollNo, "R001");
    strcpy(students[0].name, "Rahul Sharma");
    strcpy(students[0].phone, "9876543210");
    strcpy(students[0].email, "rahul@university.edu");
    students[0].year = 1;
    students[0].semester = 2;
    students[0].sgpa[0] = 8.5;
    students[0].sgpa[1] = 8.7;
    students[0].sgpa[2] = 0;
    students[0].sgpa[3] = 0;
    students[0].sgpa[4] = 0;
    students[0].sgpa[5] = 0;
    students[0].sgpa[6] = 0;
    students[0].sgpa[7] = 0;
    students[0].cgpa = 8.6;
    
    students[1].sapID = 500012005;
    strcpy(students[1].rollNo, "R002");
    strcpy(students[1].name, "Priya Singh");
    strcpy(students[1].phone, "9876543211");
    strcpy(students[1].email, "priya@university.edu");
    students[1].year = 2;
    students[1].semester = 4;
    students[1].sgpa[0] = 9.0;
    students[1].sgpa[1] = 9.2;
    students[1].sgpa[2] = 8.8;
    students[1].sgpa[3] = 9.1;
    students[1].sgpa[4] = 0;
    students[1].sgpa[5] = 0;
    students[1].sgpa[6] = 0;
    students[1].sgpa[7] = 0;
    students[1].cgpa = 9.025;
    
    students[2].sapID = 500012003;
    strcpy(students[2].rollNo, "R003");
    strcpy(students[2].name, "Amit Kumar");
    strcpy(students[2].phone, "9876543212");
    strcpy(students[2].email, "amit@university.edu");
    students[2].year = 3;
    students[2].semester = 6;
    students[2].sgpa[0] = 7.5;
    students[2].sgpa[1] = 7.8;
    students[2].sgpa[2] = 8.0;
    students[2].sgpa[3] = 8.2;
    students[2].sgpa[4] = 8.5;
    students[2].sgpa[5] = 8.3;
    students[2].sgpa[6] = 0;
    students[2].sgpa[7] = 0;
    students[2].cgpa = 8.05;
    
    students[3].sapID = 500012002;
    strcpy(students[3].rollNo, "R004");
    strcpy(students[3].name, "Neha Gupta");
    strcpy(students[3].phone, "9876543213");
    strcpy(students[3].email, "neha@university.edu");
    students[3].year = 4;
    students[3].semester = 8;
    students[3].sgpa[0] = 8.0;
    students[3].sgpa[1] = 8.2;
    students[3].sgpa[2] = 8.4;
    students[3].sgpa[3] = 8.6;
    students[3].sgpa[4] = 8.8;
    students[3].sgpa[5] = 9.0;
    students[3].sgpa[6] = 9.2;
    students[3].sgpa[7] = 9.4;
    students[3].cgpa = 8.7;
    
    students[4].sapID = 500012004;
    strcpy(students[4].rollNo, "R005");
    strcpy(students[4].name, "Vikram Patel");
    strcpy(students[4].phone, "9876543214");
    strcpy(students[4].email, "vikram@university.edu");
    students[4].year = 1;
    students[4].semester = 2;
    students[4].sgpa[0] = 7.0;
    students[4].sgpa[1] = 7.5;
    students[4].sgpa[2] = 0;
    students[4].sgpa[3] = 0;
    students[4].sgpa[4] = 0;
    students[4].sgpa[5] = 0;
    students[4].sgpa[6] = 0;
    students[4].sgpa[7] = 0;
    students[4].cgpa = 7.25;
    
    totalStudents = 5;
    printf("System initialized with 5 sample student records.\n");
}

void addStudent() {
    int i;
    
    if (totalStudents >= 100) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }
    
    printf("\n--- ADD NEW STUDENT ---\n");
    
    printf("Enter SAP ID: ");
    scanf("%ld", &students[totalStudents].sapID);
    
    printf("Enter Roll No: ");
    scanf("%s", students[totalStudents].rollNo);
    
    getchar();
    printf("Enter Full Name: ");
    fgets(students[totalStudents].name, 50, stdin);
    students[totalStudents].name[strcspn(students[totalStudents].name, "\n")] = 0;
    
    printf("Enter Phone No: ");
    scanf("%s", students[totalStudents].phone);
    
    printf("Enter Email ID: ");
    scanf("%s", students[totalStudents].email);
    
    printf("Enter Year (1/2/3/4): ");
    scanf("%d", &students[totalStudents].year);
    
    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[totalStudents].semester);
    
    for (i = 0; i < 8; i++) {
        students[totalStudents].sgpa[i] = 0.0;
    }
    
    printf("\nEnter SGPA for completed semesters:\n");
    for (i = 0; i < students[totalStudents].semester; i++) {
        printf("SGPA for Semester %d: ", i + 1);
        scanf("%f", &students[totalStudents].sgpa[i]);
    }
    
    calculateCGPA(totalStudents);
    
    totalStudents++;
    printf("\nStudent record added successfully!\n");
}

void searchStudent() {
    long searchID;
    int i;
    int found = 0;
    
    printf("\n--- SEARCH STUDENT ---\n");
    printf("Enter SAP ID to search: ");
    scanf("%ld", &searchID);
    
    for (i = 0; i < totalStudents; i++) {
        if (students[i].sapID == searchID) {
            printf("\n--- STUDENT FOUND ---\n");
            displaySingleStudent(i);
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        printf("\nStudent with SAP ID %ld not found!\n", searchID);
    }
}

void calculateCGPA(int index) {
    float sum = 0;
    int count = 0;
    int i;
    
    for (i = 0; i < 8; i++) {
        if (students[index].sgpa[i] > 0) {
            sum = sum + students[index].sgpa[i];
            count++;
        }
    }
    
    if (count > 0) {
        students[index].cgpa = sum / count;
    } else {
        students[index].cgpa = 0;
    }
}

void calculateAllCGPA() {
    int i;
    
    printf("\n--- CGPA CALCULATION ---\n");
    
    if (totalStudents == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    for (i = 0; i < totalStudents; i++) {
        calculateCGPA(i);
    }
    
    printf("\n%-15s %-25s %-10s\n", "SAP ID", "Name", "CGPA");
    printf("--------------------------------------------------\n");
    
    for (i = 0; i < totalStudents; i++) {
        printf("%-15ld %-25s %-10.2f\n", 
               students[i].sapID, 
               students[i].name, 
               students[i].cgpa);
    }
    
    printf("\nCGPA calculated for all students!\n");
}

void averageCGPAByYear() {
    float sumYear1 = 0, sumYear2 = 0, sumYear3 = 0, sumYear4 = 0;
    int countYear1 = 0, countYear2 = 0, countYear3 = 0, countYear4 = 0;
    int i;
    
    printf("\n--- AVERAGE CGPA BY YEAR ---\n");
    
    if (totalStudents == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    for (i = 0; i < totalStudents; i++) {
        if (students[i].year == 1) {
            sumYear1 = sumYear1 + students[i].cgpa;
            countYear1++;
        } else if (students[i].year == 2) {
            sumYear2 = sumYear2 + students[i].cgpa;
            countYear2++;
        } else if (students[i].year == 3) {
            sumYear3 = sumYear3 + students[i].cgpa;
            countYear3++;
        } else if (students[i].year == 4) {
            sumYear4 = sumYear4 + students[i].cgpa;
            countYear4++;
        }
    }
    
    printf("\n----------------------------------\n");
    printf("Year    Students    Average CGPA\n");
    printf("----------------------------------\n");
    
    if (countYear1 > 0) {
        printf("1st     %-11d %.2f\n", countYear1, sumYear1 / countYear1);
    } else {
        printf("1st     0           No Data\n");
    }
    
    if (countYear2 > 0) {
        printf("2nd     %-11d %.2f\n", countYear2, sumYear2 / countYear2);
    } else {
        printf("2nd     0           No Data\n");
    }
    
    if (countYear3 > 0) {
        printf("3rd     %-11d %.2f\n", countYear3, sumYear3 / countYear3);
    } else {
        printf("3rd     0           No Data\n");
    }
    
    if (countYear4 > 0) {
        printf("4th     %-11d %.2f\n", countYear4, sumYear4 / countYear4);
    } else {
        printf("4th     0           No Data\n");
    }
    
    printf("----------------------------------\n");
}

void displayAllStudents() {
    int i, j;
    
    printf("\n--- ALL STUDENT RECORDS ---\n");
    
    if (totalStudents == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    printf("Total Students: %d\n\n", totalStudents);
    
    for (i = 0; i < totalStudents; i++) {
        printf("----------------------------------------\n");
        displaySingleStudent(i);
    }
    printf("----------------------------------------\n");
}

void displaySingleStudent(int index) {
    int j;
    
    printf("SAP ID    : %ld\n", students[index].sapID);
    printf("Roll No   : %s\n", students[index].rollNo);
    printf("Name      : %s\n", students[index].name);
    printf("Phone     : %s\n", students[index].phone);
    printf("Email     : %s\n", students[index].email);
    printf("Year      : %d\n", students[index].year);
    printf("Semester  : %d\n", students[index].semester);
    printf("SGPA      : ");
    for (j = 0; j < 8; j++) {
        if (students[index].sgpa[j] > 0) {
            printf("Sem%d:%.2f ", j + 1, students[index].sgpa[j]);
        }
    }
    printf("\n");
    printf("CGPA      : %.2f\n", students[index].cgpa);
}

void deleteStudent() {
    long deleteID;
    int i, j;
    int found = 0;
    int position = -1;
    
    printf("\n--- DELETE STUDENT ---\n");
    printf("Enter SAP ID to delete: ");
    scanf("%ld", &deleteID);
    
    for (i = 0; i < totalStudents; i++) {
        if (students[i].sapID == deleteID) {
            found = 1;
            position = i;
            break;
        }
    }
    
    if (found == 1) {
        printf("\nStudent Found: %s\n", students[position].name);
        printf("Deleting record...\n");
        
        for (j = position; j < totalStudents - 1; j++) {
            students[j] = students[j + 1];
        }
        
        totalStudents--;
        printf("Student record deleted successfully!\n");
    } else {
        printf("\nStudent with SAP ID %ld not found!\n", deleteID);
    }
}

void sortBySAPID() {
    struct Student temp;
    int i, j;
    
    printf("\n--- STUDENTS SORTED BY SAP ID ---\n");
    
    if (totalStudents == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    for (i = 0; i < totalStudents - 1; i++) {
        for (j = 0; j < totalStudents - i - 1; j++) {
            if (students[j].sapID > students[j + 1].sapID) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\n%-15s %-25s %-10s %-6s\n", "SAP ID", "Name", "Roll No", "Year");
    printf("--------------------------------------------------------\n");
    
    for (i = 0; i < totalStudents; i++) {
        printf("%-15ld %-25s %-10s %-6d\n", 
               students[i].sapID, 
               students[i].name, 
               students[i].rollNo, 
               students[i].year);
    }
    
    printf("\nRecords sorted by SAP ID in increasing order.\n");
}

void sortByName() {
    struct Student temp;
    int i, j;
    
    printf("\n--- STUDENTS SORTED BY NAME ---\n");
    
    if (totalStudents == 0) {
        printf("No students in the database!\n");
        return;
    }
    
    for (i = 0; i < totalStudents - 1; i++) {
        for (j = 0; j < totalStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\n%-25s %-15s %-10s %-6s\n", "Name", "SAP ID", "Roll No", "Year");
    printf("--------------------------------------------------------\n");
    
    for (i = 0; i < totalStudents; i++) {
        printf("%-25s %-15ld %-10s %-6d\n", 
               students[i].name, 
               students[i].sapID, 
               students[i].rollNo, 
               students[i].year);
    }
    
    printf("\nRecords sorted by Name in alphabetical order.\n");
}