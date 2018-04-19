#include<stdlib.h>
#include<stdio.h>
#include <immintrin.h> // AVX

void add_intel_intrinsics(float *imgIn, float *imgOut, __m256 intensidade)
{
  __m256 vImgIn = _mm256_load_ps (imgIn);
  __m256 vImgOut = _mm256_add_ps (vImgIn, intensidade);
  _mm256_store_ps(imgOut, vImgOut);

  /* Equivalente Assembly 
  ** mov eax, a
  ** mov edx, b 
  ** mov ecx, c
  ** movaps xmm0, XMMWORD PTR [eax]
  ** addps xmm0, XMMWORD PTR [edx]
  ** movaps XMMWORD PTR [ecx], xmm0
  */
}

int main (int argc, char *argv[])
{
  __m256 intensidade = _mm256_set1_ps(50);
  float *imgIn = (float*)_mm_malloc (sizeof(float) *96, 32); //aloca um vetor de 32 bytes (256 bits) alinhado em endereços múltiplos de 16 bytes.
  float *imgOut = (float*)_mm_malloc (sizeof(float) *96, 32);

  
  int i = 0;
  
  for (i = 0; i < 96; ++i) {
    imgIn[i] = i;
  }

  for(i=0;i<=96-8;i+=8){
  	add_intel_intrinsics(&imgIn[i], &imgOut[i],intensidade);
  }

  for(i=0;i<96;++i){
  	printf("%f\n", imgOut[i]);
  }

}