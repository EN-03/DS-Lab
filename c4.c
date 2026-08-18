#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

/* Function prototypes */
void inputStudents(struct Student s[], int n);
void displayStudents(struct Student s[], int n);
void linearSearch(struct Student s[], int n);
void binarySearch(struct Student s[], int n);
void insertionSort(struct Student s[], int n);
void selectionSort(struct Student s[], int n);
void shellSort(struct Student s[], int n);
void swap(struct Student *a, struct Student *b);

int main() {
    struct Student s[MAX];
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(s, n);

    do {
        printf("\n========== STUDENT DATABASE ==========\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Shell Sort\n");
        printf("6. Display Students\n");
        printf("7. Exit\n");
        printf("======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                linearSearch(s, n);
                break;

            case 2:
                binarySearch(s, n);
                break;

            case 3:
                insertionSort(s, n);
                printf("\nStudents sorted using Insertion Sort.\n");
                displayStudents(s, n);
                break;

            case 4:
                selectionSort(s, n);
                printf("\nStudents sorted using Selection Sort.\n");
                displayStudents(s, n);
                break;

            case 5:
                shellSort(s, n);
                printf("\nStudents sorted using Shell Sort.\n");
                displayStudents(s, n);
                break;

            case 6:
                displayStudents(s, n);
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

/* Input student details */
void inputStudents(struct Student s[], int n) {
    int i;

    printf("\nEnter student details:\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

/* Display student details */
void displayStudents(struct Student s[], int n) {
    int i;

    printf("\n-------------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %-10.2f\n",
               s[i].rollNo, s[i].name, s[i].marks);
    }

    printf("-------------------------------------------------\n");
}

/* Linear Search */
void linearSearch(struct Student s[], int n) {
    int key, i, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (s[i].rollNo == key) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s[i].rollNo);
            printf("Name        : %s\n", s[i].name);
            printf("Marks       : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", key);
    }
}

/* Binary Search */
void binarySearch(struct Student s[], int n) {
    int key, low = 0, high = n - 1, mid;
    int found = 0;

    /* Sort by roll number before binary search */
    insertionSort(s, n);

    printf("\nStudents have been sorted by Roll Number for Binary Search.\n");

    printf("Enter Roll Number to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;

        if (s[mid].rollNo == key) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s[mid].rollNo);
            printf("Name        : %s\n", s[mid].name);
            printf("Marks       : %.2f\n", s[mid].marks);
            found = 1;
            break;
        }
        else if (key < s[mid].rollNo) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", key);
    }
}

/* Insertion Sort */
void insertionSort(struct Student s[], int n) {
    int i, j;
    struct Student key;

    for (i = 1; i < n; i++) {
        key = s[i];
        j = i - 1;

        while (j >= 0 && s[j].rollNo > key.rollNo) {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }
}

/* Selection Sort */
void selectionSort(struct Student s[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (s[j].rollNo < s[minIndex].rollNo) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(&s[i], &s[minIndex]);
        }
    }
}

/* Shell Sort */
void shellSort(struct Student s[], int n) {
    int gap, i, j;
    struct Student temp;

    for (gap = n / 2; gap > 0; gap /= 2) {

        for (i = gap; i < n; i++) {
            temp = s[i];

            for (j = i; j >= gap &&
                 s[j - gap].rollNo > temp.rollNo;
                 j -= gap) {

                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }
}

/* Swap two student structures */
void swap(struct Student *a, struct Student *b) {
    struct Student temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
