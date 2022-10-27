#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

char *Usage = "print-rand-matrix -r rows -c cols -t thread_count\n";
#define ARGS "a:b:t:"

double CTimer()
{
    struct timeval tm;

    gettimeofday(&tm, NULL);
    return ((double)tm.tv_sec + (double)(tm.tv_usec / 1000000.0));
}

float **readMatrix(int *n, int *m, char *filename)
{
    FILE *pf;
    int i, j;
    printf("Reading the matrix file %s\n", filename);

    char *gar = (char *)malloc(50 * sizeof(char));
    pf = fopen(filename, "rt");

    fscanf(pf, "%d %d", n, m);

    float **a = (float **)malloc((*n) * sizeof(float *));
    for (int i = 0; i < *n; i++)
    {
        a[i] = (float *)malloc((*m) * sizeof(float));
    }

    for (i = 0; i < (*n); i++)
    {
        fscanf(pf, "%s\n", gar);
        fscanf(pf, "%s\n", gar);
        fscanf(pf, "%s\n", gar);

        for (j = 0; j < (*m); j++)
        {
            fscanf(pf, "%s", gar);
            a[i][j] = atof(gar);
            printf("%f,", a[i][j]);
        }
        printf("\n");
    }
    fclose(pf);
    free(gar);
    return a;
}

// Each thread computes rows in the resultant matrix
void *mult2(void *arg)
{
    float *data = (float *)arg;
    // float* k = 0.0;
    // int i = 0;
    int i, j, p;
    float temp1 = data[0];
    float temp2 = data[1];
    float temp3 = data[2];
    int rows_no = (int)temp1;
    int col1 = (int)temp2; // equal to rows of second
    int col2 = (int)temp3;
    float *res = (float *)malloc((rows_no * col2) * sizeof(float));
    for (i = 0; i < rows_no; i++)
    {
        for (j = 0; j < col2; j++)
        {
            for (p = 0; p < col1; p++)
            {
                res[(i * col2) + j] += data[i * col1 + 3 + p] * data[rows_no * col1 + 3 + p + j * col1];
            }
        }
    }

    // Used to terminate a thread and the return value is passed as a pointer
    pthread_exit(res);
}

int main(int argc, char **argv)
{
    int c, i, j, k, p, thread_count;
    double start, finish;
    struct timeval tm;
    char *matrix1 = (char *)malloc(50 * sizeof(char));
    char *matrix2 = (char *)malloc(50 * sizeof(char));

    start = CTimer();
    while ((c = getopt(argc, argv, ARGS)) != EOF)
    {
        switch (c)
        {
        case 'a':
            matrix1 = optarg;
            break;
        case 'b':
            matrix2 = optarg;
            break;
        case 't':
            thread_count = atoi(optarg);
            break;
        default:
            fprintf(stderr, "unrecognized command %c\n",
                    (char)c);
            fprintf(stderr, "usage: %s", Usage);
            exit(1);
        }
    }

    if (matrix1 && !matrix1[0])
    {
        fprintf(stderr, "must enter file 1\n");
        fprintf(stderr, "usage: %s", Usage);
        exit(1);
    }

    if (matrix2 && !matrix2[0])
    {
        fprintf(stderr, "must enter file 2\n");
        fprintf(stderr, "usage: %s", Usage);
        exit(1);
    }

    if (thread_count <= 0)
    {
        fprintf(stderr, "must enter thread count\n");
        fprintf(stderr, "usage: %s", Usage);
        exit(1);
    }

    int *n1 = (int *)malloc(sizeof(int));
    int *m1 = (int *)malloc(sizeof(int));
    float **mat1;
    printf("Matrix 1\n");
    mat1 = readMatrix(n1, m1, matrix1);

    int *n2 = (int *)malloc(sizeof(int));
    int *m2 = (int *)malloc(sizeof(int));
    float **mat2;
    printf("Matrix 2\n");
    mat2 = readMatrix(n2, m2, matrix2);

    printf("\n Thread count = %d\n", thread_count);
    int rows_taken = (*n1) / thread_count;
    int rows_remaining = 0;
    if ((*n1) % thread_count != 0)
    {
        rows_remaining = (*n1) % thread_count;
    }

    int *rows_to_give = (int *)malloc(thread_count * sizeof(int));
    if (*n1 >= thread_count)
    {
        for (int i = 0; i < thread_count; i++)
        {
            rows_to_give[i] = rows_taken;
        }

        while (rows_remaining > 0)
        {
            rows_to_give[i] += rows_remaining;
            rows_remaining--;
        }
    }
    else
    {
        free(rows_to_give);
        int *rows_to_give = (int *)malloc(thread_count * sizeof(int));
        for (int i = 0; i < *n1; i++)
        {
            rows_to_give[i] = 1;
        }

        thread_count = *n1;
    }
    for (int i = 0; i < thread_count; i++)
    {
        printf("%d", rows_to_give[i]);
    }

    printf("\n\nStarting Threads and Multiplication\n");
    int max = (*n1) * (*m2);
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // declaring array of threads of size thread_count
    pthread_t *threads;
    threads = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
    float *data = NULL;
    int row = 0;
    int col = 0;
    int count;
    int count_threads = 0;

    for (i = 0; i < thread_count; i++)
    {
        int size = (2 * rows_to_give[i] * (*m1) * (*m2) + 3);
        data = (float *)malloc(size * sizeof(float));
        data[0] = rows_to_give[i] * 1.0;
        data[1] = (*m1) * 1.0;
        data[2] = (*m2) * 1.0;
        for (j = 0; j < rows_to_give[i]; j++)
        {
            for (k = 0; k < *m1; k++)
            {
                data[k + j * (*m1) + 3] = mat1[row][k];
            }
            row++;
        }
        count = 0;
        for (p = 0; p < *m2; p++)
        {
            for (k = 0; k < *n2; k++)
            {
                data[count + (rows_to_give[i] * (*m1)) + 3] = mat2[k][p];
                count++;
            }
        }

        // creating threads
        pthread_create(&threads[count_threads++], NULL,
                       mult2, (void *)(data));
    }

    for (i = 0; i < thread_count; i++)
    {
        void *result;

        // Joining all threads and collecting return value
        pthread_join(threads[i], &result);

        float *temp = (float *)result;
        int tcount = 0;
        for (j = 0; j < rows_to_give[i]; j++)
        {
            for (k = 0; k < *m2; k++)
            {
                printf("%f ", temp[tcount]);
                tcount++;
            }
            printf("\n");
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken = %f\n", cpu_time_used);

    finish = CTimer();

    printf("\nFinished in %lf seconds\n", (finish - start));

    // matrix multiplication with 1 thread
    printf("\n\nStarting Single Thread Multiplication\n");
    start = clock();
    float **mat3;
    mat3 = (float **)malloc((*n1) * sizeof(float *));
    for (i = 0; i < *n1; i++)
    {
        mat3[i] = (float *)malloc((*m2) * sizeof(float));
    }
    for (i = 0; i < *n1; i++)
    {
        for (j = 0; j < *m2; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < *m1; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (i = 0; i < *n1; i++)
    {
        for (j = 0; j < *m2; j++)
        {
            printf("%f ", mat3[i][j]);
        }
        printf("\n");
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken = %f\n", cpu_time_used);

    return 1;
}
