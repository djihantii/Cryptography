#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXVAL 8


int inTable(int value, int* table, int taille){
  for(int i =0; i< taille; i++){
    if(table[i] == value)
      return 1;
  }
  return 0;
}

int * IP_function(int * table , int * permutation, int taille){
  int * result = malloc(taille * sizeof(int));
  for (int i = 0; i < taille; i++) {
    result[i] = table[permutation[i]];

  }
  return result;
}
int* permute_left(int * table, int taille){
  int *result = malloc(taille*sizeof(int));
  result[taille-1] =table[0];
  for(int i=0; i<taille-1; i++){
    result[i] = table[i+1];
  }
  return result;
}

int* permute_right(int * table, int taille){
  int *result = malloc(taille*sizeof(int));
  result[0] =table[taille-1];
  for(int i=1; i<taille; i++){
    result[i] = table[i-1];
  }
  return result;
}

int * exclusive(int* a, int*b, int taille){
  int * result = malloc(taille*sizeof(int));
  for(int i =0; i< taille; i++){
    printf("a = %d , b=%d et ex = %d \n",a[i], b[i], a[i]!=b[i] );
    result[i] = (a[i]!=b[i]);
  }
  return result;
}

int ** splitTable(int * table, int taille){
  int subSize = taille/2;
  int **result = malloc(2*sizeof(int *));
  result[0] = malloc(subSize*sizeof(int));
  result[1] = malloc(subSize*sizeof(int));
  for (int i = 0; i < subSize; i++) {
    result[0][i] = table[i];
    result[1][i+subSize] = table[i+subSize];
  }

  return result;
}

int* fusion(int *a, int size_a, int * b , int size_b){
  int * result = malloc((size_a+size_b)*sizeof(int));
  for (int i = 0; i < size_a; i++) {
    result[i]=a[i];
  }
  for(int j=0; j< size_b; j++){
    result[size_a+j] = b[j];
  }

  return result;
}

int ** subkeyGenerator(int * permutation, int * table, int taille){
  int **splitted = splitTable(table, taille);

}
int F_function(){}

int Fk_funciton(){}

// int *IP_inverse_function(int * table , int taille){
//   int * result = malloc(taille*sizeof(int));
//   for(int i = 0; i< taille; i++){
//     result[table[i]] = i;
//     printf("%d en position %d \n ", i, result[table[i]]);
//   }
//   return result;
// }

int SW_function(){}



int main(int argc, char const *argv[]) {
  int table[8]={0,1,2,3,4,5,6,7};
  int permutation[8] = { 1,5,2,0,3,7,4,6};
  int inverse[8]={3,0,2,4,6,1,7,5};
  // int * result = IP_inverse_function(table, 8);
  int * result = IP_function(table,  permutation, 8);
  for (int i = 0; i < 8; i++) {
    printf("%d \t", result[i]);
  }
  // int *original = IP_inverse_function(result, 8);
  int * original = IP_function(IP_function(table,  permutation, 8), inverse, 8);
  for(int j=0; j<8; j++){
    printf("%d \t", original[j]);
  }
  int *perLeft = permute_right(table, 8);
  for(int k = 0; k< 8; k++){
    printf("%d \t ", perLeft[k]);
  }
  printf("\n then \n");


  return 0;
}
