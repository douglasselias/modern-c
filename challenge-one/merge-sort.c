#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void divide(int* array) {
  size_t size = sizeof(array) / sizeof(array[0]);

  if(size == 1)
    return 0;

  int half = size >> 1;

}

void* mergeSort(int* array) {
  size_t size = sizeof(array) / sizeof(array[0]);

  if(size == 1)
    return array;

  int half = size >> 1;

  // int leftHalf = malloc(half * sizeof(int));

  // while(true) {

  // }

  // for(int i = 0; i < size; i++)
  //   printf("Valor: %d", array[i]);
}

int main() {
  int array[7] = { 70, 30, 10, 20, 40, 50, 60 };

  mergeSort(array);

  return EXIT_SUCCESS;
}