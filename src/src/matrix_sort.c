#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int N, int M);
void output(int **matrix, int N, int M);
int rowSum(int *N, int cols);
void swapRows(int **matrix, int row1, int row2);
void sortMatrix(int **matrix, int N, int M);
int allocatedOne(int N, int M);
int allocatedTwo(int N, int M);
int allocatedThree(int N, int M);
int chooseMod(int mod, int N, int M);

int main() {
    int mod = 0;
    int N, M;
    if (scanf("%d", &mod) == 1 && (mod > 0) && (mod < 4)) {
        if (scanf("%d %d", &N, &M) != 2 || (N < 1) || (M < 1))
            printf("n/a");
        else if (chooseMod(mod, N, M) != 1)
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int rowSum(int *N, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += N[i];
    }
    return sum;
}

void swapRows(int **matrix, int row1, int row2) {
    int *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void sortMatrix(int **matrix, int N, int M) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (rowSum(matrix[j], M) > rowSum(matrix[j + 1], M)) {
                swapRows(matrix, j, j + 1);
            }
        }
    }
}

int chooseMod(int mod, int N, int M) {
    int result = 1;
    switch (mod) {
        case 1:
            result = allocatedOne(N, M);
            break;
        case 2:
            result = allocatedTwo(N, M);
            break;
        case 3:
            result = allocatedThree(N, M);
            break;
    }
    return result;
}

int input(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
        if (getchar() != '\n') {
            return 0;
        }
    }
    return 1;
}

void output(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", matrix[i][j]);
            if (j < M - 1) printf(" ");
        }
        if (i < N - 1) printf("\n");
    }
}

int allocatedTwo(int N, int M) {
    int **matrix = malloc(N * sizeof(int *));
    if (matrix == NULL) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(M * sizeof(int));
        if (matrix[i] == NULL) {
            return 0;
        }
    }

    if (input(matrix, N, M) != 1) {
        return 0;
    }

    sortMatrix(matrix, N, M);

    output(matrix, N, M);

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 1;
}

int allocatedOne(int N, int M) {
    int **matrix = malloc(N * M * sizeof(int) + N * sizeof(int *));
    if (matrix == NULL) {
        return 0;
    }
    int *ptr = (int *)(matrix + N);
    for (int i = 0; i < N; i++) {
        matrix[i] = ptr + M * i;
    }

    if (input(matrix, N, M) != 1) {
        return 0;
    }

    sortMatrix(matrix, N, M);

    output(matrix, N, M);

    free(matrix);
    return 1;
}

int allocatedThree(int N, int M) {
    int **matrix = malloc(N * sizeof(int *));
    int *valuesArr = malloc(M * N * sizeof(int));
    if (matrix == NULL) {
        return 0;
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = valuesArr + M * i;
    }

    if (input(matrix, N, M) != 1) {
        return 0;
    }

    sortMatrix(matrix, N, M);

    output(matrix, N, M);

    free(matrix);
    free(valuesArr);
    return 1;
}