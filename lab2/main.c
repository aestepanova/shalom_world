#include <stdlib.h>
#include <stdio.h>
#include <minmax.h>
#include <time.h>

/// Создать вектор b. i-тый элемент вектора равен сумме тех элементов i-той строки матрицы,
/// которые превышают соответсвующий элемент предыдущей строки (i-1)-той.
/// Для первой строки использовать последнюю в качестве предыдущей.

typedef struct line {
    int n;
    int *arr;
} line;

typedef struct matrix {
    int m;
    line *matr;
} matrix;

int getNaturalInt(int *a);
void input(int *m, struct matrix *matrix);
void printV(int *vec, int size);
int fun1(int* line1, int* line0, int n1, int n0);
void print(matrix *rm);
void erase(matrix *a);

int main() {
    int m;
    struct matrix matrix={0, NULL};
    input(&m, &matrix); // ввод матрицы
    printf("It's your matrix: \n");
    print(&matrix); // вывод матрицы
    int m1=m-1;
    int* vector=(int *)malloc(m*sizeof(vector));
    //отдельно для первой строки
    *(vector)=fun1(matrix.matr[0].arr, matrix.matr[m1].arr, matrix.matr[0].n, matrix.matr[m1].n);
    // заполнение вектора для остальных строк
    for (int k = 1; k <m; k++) {
        *(vector+k)=fun1(matrix.matr[k].arr, matrix.matr[(k-1)].arr, matrix.matr[k].n, matrix.matr[(k-1)].n);
    }
    printV(vector, m); // вывод вектора
    free(vector); // чистим память
    erase(&matrix); // чистим память
    return 0;
}

int fun1(int* line1, int* line0, int n1, int n0){

    int sum=0;
    //int n=n1-n0;
    //int *line=line1;
    for (int j=0; j<min(n1,n0); j++, line0++, line1++){
        if (*(line1) > *(line0)){
            sum=sum+*(line1);
        }
    }

   /* if (n>0) {
        for (int t = n0; t< n1; t++, line++) {
            sum = sum + *(line+t);
        }
    } */
    return sum;
}

void input(int *m, struct matrix *matrix) {
    int n;
    srand(time(NULL));
    printf("Input quantity of rows: \n");
    getNaturalInt(m);
    (*matrix).m = (*m);
    (*matrix).matr = (line *) calloc((*m), sizeof(line));

    for (int i = 0; i < (*m); ++i) {
        printf("Input quantity of elements in %d row: \n", i + 1);
        getNaturalInt(&n);
        matrix->matr[i].n = n;
        matrix->matr[i].arr = (int *) calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix->matr[i].arr[j]=0 + rand() % (50 - 0);
        }
    }
}

int getNaturalInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0 || *a <= 0 ) {
            printf("%s\n", "Error! Please, repeat your input: ");
            scanf("%*[^\n]", 0);
        }
    } while (n == 0 || *a <= 0 );
    return 1;
}

void erase(matrix *a) {
    int i;
    for (i = 0; i < a->m; ++i)
        free(a->matr[i].arr);
    free(a->matr);
    a->m = 0;
    a->matr = NULL;
}

void printV(int *vec, int size){
    int *ptr=vec;
    printf("\nIt's vector: \n");
    for (int i = 0; i < size; i++) {
        printf("b[%d]=%d ", i, *(ptr++));
    }
    printf("\n");
}

void print(matrix *rm) {
    int i, j;

    line* m_ptr=rm->matr;
    int* ptr;
    for (i = 0; i < rm->m; i++) {
        ptr=m_ptr->arr;
        for (j = 0; j < m_ptr->n; j++) {
            printf("%d ", *(ptr++));
        }
        m_ptr++;
        printf("\n");
    }
    printf("\n");
}