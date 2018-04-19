#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <immintrin.h> // AVX
#define SIZE 90000

int main(){

	float *imgIn = (float*)_mm_malloc (sizeof(float) * SIZE, 32);
  	float *imgOut = (float*)_mm_malloc (sizeof(float) * SIZE, 32);
  	float *mult = (float*)_mm_malloc (sizeof(float) * 8, 32);
  	mult[0] = 1;
  	mult[1] = 2;
  	mult[2] = 3;
  	int i = 0, j = 0, k = 0;

	for (i = 0; i < SIZE; i++) {
   		imgOut[i] = 0;
  	} 	
  	
  	__m256 vImgIn = _mm256_load_ps(imgIn);
  	__m256 vImgOut = _mm256_load_ps(imgOut);  	
	__m256 vmult = _mm256_load_ps(mult);
	
 	clock_t tic = clock();
 	
	for(k = 0;k<500;k++){	
	  	for(i=0;i<=SIZE-8;i+=8){
	  		for(j=0;j<3;j++){
	  			vImgOut += _mm256_mul_ps(vImgIn, vmult);
	  		}
	  	}
	}
	clock_t toc = clock();

  	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

}
