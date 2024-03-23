#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int row, int col);
void output(int **matrix, int row, int col);
int allocatedOne(int row, int col);
int allocatedTwo(int row, int col);
int allocatedThree(int row, int col);
int staticAllocated(int row, int col);
int chooseMod(int mod, int row, int col);

int main() {
    int mod = 0;
    int row, col;
    if (scanf("%d", &mod) == 1 && (mod > 0) && (mod < 5)) {
        if (scanf("%d %d", &row, &col) != 2 || row < 1 || col < 1)
            printf("n/a");
        else if (mod == 1 && (row > 100 || col > 100))
            printf("n/a");
        else if (chooseMod(mod, row, col) != 1)
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

int chooseMod(int mod, int row, int col) {
    int result = 1;
    switch (mod) {
        case 1:
            result = staticAllocated(row, col);
            break;
        case 2:
            result = allocatedOne(row, col);
            break;
        case 3:
            result = allocatedTwo(row, col);
            break;
        case 4:
            result = allocatedThree(row, col);
            break;
    }
    return result;
}

int staticAllocated(int row, int col) {
    int max = 100;
    int matrix[row][col];
    if (row > max || col > max) {
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
        if (getchar() != '\n') {
            return 0;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j < col - 1) printf(" ");
        }
        if (i < row - 1) printf("\n");
    }

    return 1;
}

int input(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
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

void output(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j < col - 1) printf(" ");
        }
        if (i < row - 1) printf("\n");
    }
}

int allocatedTwo(int row, int col) {
    int **matrix = malloc(row * sizeof(int *));
    if (matrix == NULL) {
        return 0;
    }

    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof(int));
        if (matrix[i] == NULL) {
            return 0;
        }
    }

    if (input(matrix, row, col) != 1) {
        return 0;
    }

    output(matrix, row, col);

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 1;
}

int allocatedOne(int row, int col) {
    int **matrix = malloc(row * col * sizeof(int) + row * sizeof(int *));
    if (matrix == NULL) {
        return 0;
    }
    int *ptr = (int *)(matrix + row);
    for (int i = 0; i < row; i++) {
        matrix[i] = ptr + col * i;
    }

    if (input(matrix, row, col) != 1) {
        return 0;
    }

    output(matrix, row, col);

    free(matrix);
    return 1;
}

int allocatedThree(int row, int col) {
    int **matrix = malloc(row * sizeof(int *));
    int *valuesArr = malloc(col * row * sizeof(int));
    if (matrix == NULL) {
        return 0;
    }
    for (int i = 0; i < row; i++) {
        matrix[i] = valuesArr + col * i;
    }

    if (input(matrix, row, col) != 1) {
        return 0;
    }

    output(matrix, row, col);

    free(matrix);
    free(valuesArr);
    return 1;
}