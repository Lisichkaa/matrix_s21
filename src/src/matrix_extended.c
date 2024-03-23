#include <stdio.h>
#include <stdlib.h>

#define MAX_STATIC_ARR 10000

int change_mode(int mode, int m, int n);
int pointer_of_arrays(int m, int n);
int pointers_to_segment(int m, int n);
int pointer_one_buffer(int m, int n);
int default_matrix(int m, int n);
void extended_function(int **a, int m, int n);
void output(int *a, int n);

int main() {
    int n = 0, m = 0, mode = 0;
    if (scanf("%d", &mode) == 1 && (mode > 0 && mode < 5)) {  // записываем режим работы
        if (scanf("%d %d", &m, &n) == 2 && n > 0 && m > 0) {  // записываем размер массива
            if (change_mode(mode, m, n) != 0) {
                printf("n/a");
            }

        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int change_mode(int mode, int m, int n) {
    int bool = 0;
    switch (mode) {
        case 1:
            bool = pointer_of_arrays(m, n);
            break;
        case 2:
            bool = pointers_to_segment(m, n);
            break;
        case 3:
            bool = pointer_one_buffer(m, n);
            break;
        case 4:
            bool = default_matrix(m, n);
            break;
    }
    return bool;
}

int default_matrix(int m, int n) {
    int arr[m][n], result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float x;
            int res = scanf("%f", &x);
            if (res == 1 && x == (int)x) {
                arr[i][j] = (int)x;
            }
        }
        if (getchar() != '\n') {
            result = 1;
            return result;
        }
    }
    if (result == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        int max, min, max_arr[m], min_arr[n];
        for (int i = 0; i < m; i++) {
            max = arr[i][0];
            for (int j = 0; j < n; j++) {
                max = (max < arr[i][j]) ? arr[i][j] : max;
            }
            max_arr[i] = max;
        }
        output(max_arr, n);
        printf("\n");
        for (int i = 0; i < m; i++) {
            min = arr[0][i];
            for (int j = 0; j < n; j++) {
                min = (min > arr[j][i]) ? arr[j][i] : min;
            }
            min_arr[i] = min;
        }
        output(min_arr, m);

    } else {
        printf("n/a");
    }
    return result;
}

// Array of pointers to arrays
int pointer_of_arrays(int m, int n) {
    int **pointer_array = malloc(m * sizeof(int *));
    int result = 0;
    for (int i = 0; i < m; i++) {
        pointer_array[i] = malloc(n * sizeof(int *));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float x;
            int res = scanf("%f", &x);
            if (res == 1 && x == (int)x) {
                pointer_array[i][j] = (int)x;
            }
        }
        if (getchar() != '\n') {
            result = 1;
            return result;
        }
    }
    if (result == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", pointer_array[i][j]);
            }
            printf("\n");
        }
        extended_function(pointer_array, m, n);
    } else {
        printf("n/a");
    }

    for (int i = 0; i < m; i++) {
        free(pointer_array[i]);
    }
    free(pointer_array);
    return result;
}

// Array of pointers to segment of the second array
int pointers_to_segment(int m, int n) {
    int **pointer_array = malloc(m * sizeof(int *));
    int *values_array = malloc(m * n * sizeof(int));
    int result = 0;
    for (int i = 0; i < m; i++) {
        pointer_array[i] = values_array + n * i;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float x;
            int res = scanf("%f", &x);
            if (res == 1 && x == (int)x) {
                pointer_array[i][j] = (int)x;
            }
        }
        if (getchar() != '\n') {
            result = 1;
            return result;
        }
    }
    if (result == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", pointer_array[i][j]);
            }
            printf("\n");
        }
        extended_function(pointer_array, m, n);
    } else {
        printf("n/a");
    }
    free(values_array);
    free(pointer_array);
    return result;
}

// Array of pointers to array segments within one buffer
int pointer_one_buffer(int m, int n) {
    int **single_array_matrix = malloc(m * n * sizeof(int) + m * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + m);
    int result = 0;
    for (int i = 0; i < m; i++) {
        single_array_matrix[i] = ptr + n * i;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float x;
            int res = scanf("%f", &x);
            if (res == 1 && x == (int)x) {
                single_array_matrix[i][j] = (int)x;
            }
        }
        if (getchar() != '\n') {
            result = 1;
            return result;
        }
    }
    if (result == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", single_array_matrix[i][j]);
            }
            printf("\n");
        }
        extended_function(single_array_matrix, m, n);
    } else {
        printf("n/a");
    }
    free(single_array_matrix);
    return result;
}

void extended_function(int **a, int m, int n) {
    int max, min, max_arr[m], min_arr[n];
    for (int i = 0; i < m; i++) {
        max = a[i][0];
        for (int j = 0; j < n; j++) {
            max = (max < a[i][j]) ? a[i][j] : max;
        }
        max_arr[i] = max;
    }
    output(max_arr, n);
    printf("\n");
    for (int i = 0; i < m; i++) {
        min = a[0][i];
        for (int j = 0; j < n; j++) {
            min = (min > a[j][i]) ? a[j][i] : min;
        }

        min_arr[i] = min;
    }
    output(min_arr, m);
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\b");
}
