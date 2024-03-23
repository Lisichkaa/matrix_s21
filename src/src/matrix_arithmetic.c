#include <stdio.h>
#include <stdlib.h>

void change_mode();
int pointers_to_segment(int m, int n, int **a);
int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
         int **matrix_result, int *n_result, int *m_result);
void transpose(int **matrix, int n, int m);
void mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
         int **matrix_result, int *n_result, int *m_result);
void double_matrix_input(int a);
int **malloc_func(int m, int n);
void freelloc(int **a, int m);
void transpose_input();

int main() {
    change_mode();
    return 0;
}

void change_mode() {
    float a;
    int res = scanf("%f", &a);
    if (res == 1 && a == (int)a && (int)a > 0 && (int)a < 4) {
        switch ((int)a) {
            case 1:
                double_matrix_input(0);
                break;
            case 2:
                double_matrix_input(1);
                break;
            case 3:
                transpose_input();
                break;
        }
    } else
        printf("n/a");
}

void transpose_input() {
    float m_first_f, n_first_f;
    int res = scanf("%f %f", &n_first_f, &m_first_f);
    if (res == 2 && n_first_f == (int)n_first_f && m_first_f == (int)m_first_f) {
        int m_first = (int)m_first_f, n_first = (int)n_first_f;
        int **first_matrix = malloc_func(m_first, n_first);
        pointers_to_segment(m_first, n_first, first_matrix);
        transpose(first_matrix, n_first, m_first);
        freelloc(first_matrix, m_first);
    } else {
        printf("n/a");
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j != n - 1) printf(" ");
        }
        if (i != m - 1) printf("\n");
    }
}

void transpose(int **matrix, int n, int m) {
    int **buffer = malloc_func(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            buffer[i][j] = matrix[j][i];
        }
    }
    output(buffer, n, m);
    freelloc(buffer, m);
}

void freelloc(int **a, int m) {
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
}

int **malloc_func(int m, int n) {
    int **a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        a[i] = malloc(n * sizeof(int *));
    }
    return a;
}

int pointers_to_segment(int m, int n, int **a) {
    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            float x;
            int res = scanf("%f", &x);
            if (res >= 1 && x == (int)x) {
                a[i][j] = (int)x;
            } else {
                result = 1;
            }
        }
    }
    return result;
}

void sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
         int **matrix_result, int *n_result, int *m_result) {
    *n_result = n_second;
    *m_result = m_second;
    for (int i = 0; i < m_first; ++i) {
        for (int j = 0; j < n_first; ++j) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    for (int i = 0; i < m_first; ++i) {
        for (int j = 0; j < n_first; ++j) {
            printf("%d", matrix_result[i][j]);
            if (j != n_first - 1) printf(" ");
        }
        if (i != m_first - 1) printf("\n");
    }
}

void double_matrix_input(int a) {
    float m_first_f, n_first_f, m_second_f, n_second_f;
    int n_result, m_result;
    int res = scanf("%f %f", &m_first_f, &n_first_f);
    if (res == 2 && n_first_f == (int)n_first_f && m_first_f == (int)m_first_f) {
        int m_first = (int)m_first_f, n_first = (int)n_first_f;
        int **first_matrix = malloc_func(m_first, n_first);
        if (pointers_to_segment(m_first, n_first, first_matrix) == 0) {
            res = scanf("%f %f", &m_second_f, &n_second_f);
            if (res == 2 && n_second_f == (int)n_second_f && m_second_f == (int)m_second_f) {
                int m_second = (int)m_second_f, n_second = (int)n_second_f;
                int **second_matrix = malloc_func(m_second, n_second);
                int **matrix_result = malloc_func(m_second, n_second);
                int res_mat = pointers_to_segment(m_second, n_second, second_matrix);
                if (res_mat == 0 && a == 0 && m_second == m_first && n_second == n_first) {
                    sum(first_matrix, n_first, m_first, second_matrix, n_second, m_second, matrix_result,
                        &n_result, &m_result);
                } else if (res_mat == 0 && a == 1) {
                    mul(first_matrix, n_first, m_first, second_matrix, n_second, m_second, matrix_result,
                        &n_result, &m_result);
                } else {
                    printf("n/a");
                }
                freelloc(second_matrix, m_second);
                freelloc(matrix_result, m_result);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        freelloc(first_matrix, m_first);
    } else {
        printf("n/a");
    }
}

void mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
         int **matrix_result, int *n_result, int *m_result) {
    int mul = 0;
    *n_result = n_second;
    *m_result = m_first;
    if (m_second == n_first) {
        matrix_result = malloc_func(*m_result, *n_result);
        for (int i = 0; i < m_first; ++i) {
            for (int j = 0; j < n_second; ++j) {
                for (int s = 0; s < n_first; ++s) {
                    mul = mul + (matrix_first[i][s] * matrix_second[s][j]);
                }
                printf("%d", mul);
                if (j != n_second - 1) printf(" ");
                mul = 0;
            }
            if (i != m_first - 1) printf("\n");
        }
        freelloc(matrix_result, *m_result);
    } else {
        printf("n/a");
    }
}
