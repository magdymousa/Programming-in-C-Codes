#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_max(int *arr,int len){
  int max_ind = 0, i = 0,max_val = arr[0];
  for(i = 1;i < len-1;i++){
    if(arr[i] > max_val){
      max_ind = i;
      max_val = arr[i];
    }
  }
  return max_ind;
}

int de_crypt(FILE * f) {
  int y, c, array[26] = {0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      array[c]++;
    }
  }
  y = find_max(array,26);
  if(y >= 4)
  return y - 4;
  else
    return 22+y;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  int key = -1;
  key = de_crypt(f);
  if(key >= 0 && key < 26){
    fprintf(stdout,"%d\n",key);
  }
  else {
    fprintf(stderr,"Failed to decrypt!");
    return EXIT_FAILURE;
  }
  if (fclose(f) != 0) {
    perror("Failed to close the input file!\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

