#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <immintrin.h> // AVX
#define SIZE 90000

void produtoEscalar(int imgIn[], int mult[], int result[], int n)
{
   	int  i, j;
    for (i = 0; i < n; i++){
    	for(j=0;j<3;j++){
   	    	result[i] += imgIn[i]*mult[j];
   		}
    }
}


int main()
{
	int i = 0;
	srand(time(NULL));
	int imgIn[SIZE]; 
  	int result[SIZE];
  	int mult[3] = {1,2,3};

  	for(i=0;i<SIZE;i++){
		result[i] = 0;	
	}

	for(i=0;i<SIZE;i++){
		imgIn[i] = rand() % 10;	
	}


	clock_t tic = clock();

	for(i=0;i<500;i++){

		produtoEscalar(imgIn, mult, result, SIZE);   

	}

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}