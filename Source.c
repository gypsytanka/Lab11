#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#define N 10
#define M 100
#define SIZE 100

// дз
int func(float* A, float sr) {
    int count = 0;
    for (int i = 0; i < N; i++) {  
        if (A[i] < sr) {
            count++;
        }
    }
    return count;
}

//классная работа
int task1() {
    setlocale(LC_CTYPE, "RUS");

    float temp;
    float A[N];
    float sum = 0;
    float sr;

    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    printf("|---------------------------------------------|\n");
    printf("| индекс | исходное значение | новое значение |\n");

    for (int i = 0; i < N; i++) {
        float new;
        if (A[i] == 0) {
            new = i + 1;
        }
        else {
            new = A[i];
        }

        printf("| %6d | %16f | %15f |\n", i + 1, A[i], new);
    }

    printf("|---------------------------------------------|\n");

    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    sr = sum / N;

    printf("Среднее арифметическое равно %2f\n", sr);

    printf("Кол-во элементов меньше среднего: %d \n", func(A, sr)); //дз
    return 0;  
}

double calc(double x) {
    return fabs(log10(x)) - pow(x - 2, 2);
}

int task2() {
    setlocale(LC_CTYPE, "RUS");
    float A[M];
    float start = 2;
    float end = 4.1;
    float step = (end - start) / (M - 1);

    float possum = 0.0;
    float negsum = 0.0;
    int poscount = 0;
    int negcount = 0;
    float sr = 0.0;

    for (int i = 0; i < M; i++) {
        float x = start + i * step;
        A[i] = calc(x);
        printf("%f\n", A[i]);

        if (A[i] > 0) {
            possum += A[i];
            poscount += 1;
        }
        else {
            negsum += A[i];
            negcount += 1;
        }
    }
    sr = possum / M;

    printf("A[M], сумма положительных - %f, сумма отрицательных - %f,\n", possum, negsum);
    printf("кол-во положительных - %d, кол - во отрицательных - %d, среднее - %f", poscount, negcount, sr);
    return 0;
}



int main() {
    task1();
    task2();
}