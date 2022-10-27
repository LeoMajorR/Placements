// perform matrix multiplication using custom bo of threads and calculate time

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX_THREADS 4

// global variables
int n, m, p, q, c, d, k, sum = 0;
int first[MAX_THREADS][MAX_THREADS], second[MAX_THREADS][MAX_THREADS], multiply[MAX_THREADS][MAX_THREADS];
int thread_count;

// function to calculate time
double CTimer()
{
    struct timeval tm;
    gettimeofday(&tm, NULL);
    return ((double)tm.tv_sec + (double)(tm.tv_usec / 1000000.0));
}

// function to perform matrix multiplication
void *mult(void *arg)
{
    int i, j, k;
    int *data = (int *)arg;
    int thread_id = *data;
    int start = (thread_id * n) / thread_count;
    int end = ((thread_id + 1) * n) / thread_count;
    for (i = start; i < end; i++)
    {
        for (j = 0; j < q; j++)
        {
            for (k = 0; k < m; k++)
            {
                sum = sum + first[i][k] * second[k][j];
            }
            multiply[i][j] = sum;
            sum = 0;
        }
    }
}

// main function
int main(int argc, char *argv[])
{
    // variables
    int i, j;
    double start, end;
    pthread_t *thread_handles;

    // read the number of rows and columns of first matrix
    printf("Enter the number of rows and columns of first matrix");
    scanf("%d%d", &n, &m);

    // read the number of rows and columns of second matrix
    printf("Enter the number of rows and columns of second matrix");
    scanf("%d%d", &p, &q);

    // check if the number of columns of first matrix is equal to the number of rows of second matrix
    if (m != p)
    {
        printf("The matrices can't be multiplied with each other.");
    }
    else
    {
        // read the elements of first matrix
        printf("Enter the elements of first matrix");
        for (c = 0; c < n; c++)
        {
            for (d = 0; d < m; d++)
            {
                scanf("%d", &first[c][d]);
            }
        }

        // read the elements of second matrix
        printf("Enter the elements of second matrix");
        for (c = 0; c < p; c++)
        {
            for (d = 0; d < q; d++)
            {
                scanf("%d", &second[c][d]);
            }
        }

        // print the first matrix
        printf("First Matrix: ");
        for (c = 0; c < n; c++)
        {
            for (d = 0; d < m; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf(" \n");
        }

        // print the second matrix
        printf("Second Matrix: ");
        for (c = 0; c < p; c++)
        {
            for (d = 0; d < q; d++)
            {
                printf("%d\t", second[c][d]);
            }
            printf(" \n");
        }

        // start the timer
        start = CTimer();

        // create threads
        thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
        for (i = 0; i < thread_count; i++)
        {
            pthread_create(&thread_handles[i], NULL, mult, (void *)&i);
        }

        // join threads
        for (i = 0; i < thread_count; i++)
        {
            pthread_join(thread_handles[i], NULL);
        }

        // stop the timer
        end = CTimer();

        // print the result
        printf("Product of entered matrices: ");
        for (c = 0; c < n; c++)
        {
            for (d = 0; d < q; d++)
            {
                printf("%d\t", multiply[c][d]);
            }
            printf(" \n");
        }

        // print the time taken
        printf("Time taken: %f", end - start);
    }
    return 0;
}
