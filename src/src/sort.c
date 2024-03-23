#include <stdio.h>
#include <stdlib.h>

int input(int *data, int *n);
void bubbleSort(int *data, int *n);
void swap(int j, int *data);
void output(int *data, int *n);
int inputN(int *n);

int main() {
    int n;
    if (inputN(&n) == 1) {
        int *data = (int *)calloc(n, sizeof(int));
        if (data == NULL) {
            printf("n/a");
            return -1;
        }
        if (input(data, &n) == 1) {
            bubbleSort(data, &n);
            output(data, &n);
            printf("\b");
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int inputN(int *n) {
    int result = 1;
    if (scanf("%d", n) == 1) {
        if (*n <= 0) {
            result = 0;
        }
    } else {
        result = 0;
    }
    return result;
}

int input(int *data, int *n) {
    int result = 1;
    for (int *p = data; p - data < *n; p++) {
        if (scanf("%d", p) != 1) {
            result = 0;
        }
    }
    if (getchar() != '\n') {
        result = 0;
    }
    return result;
}

void swap(int j, int *data) {
    int swap = data[j];
    data[j] = data[j + 1];
    data[j + 1] = swap;
}

void bubbleSort(int *data, int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(j, data);
            }
        }
    }
}

void output(int *data, int *n) {
    for (int *p = data; p - data < *n; p++) {
        printf("%d ", *p);
    }
}