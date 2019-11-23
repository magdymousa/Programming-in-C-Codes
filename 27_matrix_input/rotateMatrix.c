#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_matrix(char array[10][10]);

void rotate(char matrix[10][10]){
  //char new_matrix[10][10] = {0};
  char temp;
  int i = 0, j = 0;
  for(i = 0;i < 5;i++){
    for(j = i;j < 10-1-i;j++){
      //new_matrix[i][j] = matrix[9-j][i];
      temp  = matrix[i][j];
      matrix[i][j] = matrix[9-j][i];
      matrix[9-j][i] = matrix[9-i][9-j];
      matrix[9-i][9-j] = matrix[j][9-i];
      matrix[j][9-i] = temp;
    }
  }
}

int read_arr(char matrix[10][10],FILE * f) {
  int c,i = 0,j = 0;
  while ((c = fgetc(f)) != EOF) {
    if(c != '\n'){
      if(j > 9){
	fprintf(stderr,"long line\n");
	return  0;
      }
      else if( i > 9){
	fprintf(stderr,"too many lines\n");
	return  0;
      }
      matrix[i][j] = c;
      j++;
    }
    else{
      if(j != 10){
	fprintf(stderr,"short line\n");
	return  0;
      }
      else if(i > 9){
	fprintf(stderr,"too many lines\n");
	return  0;
      }
      i++;
      j = 0;
    }
  }
  if(i < 10){
    fprintf(stderr,"few lines\n");
    return  0;
  }
  return 1;
}

void print_matrix(char matrix[10][10]){
  int i,j;
  for(i = 0;i < 10;i++){
    for(j = 0;j < 10;j++){
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  }
}


int main(int argc, char ** argv) {
  char  matrix[10][10] = {0};
  //char * matrix = & m_arr;
  if (argc != 2) {
    fprintf(stderr,"invalid arguments\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if (f == NULL) {
    fprintf(stderr,"Could not open file\n");
    return EXIT_FAILURE;
  }

  if(!read_arr(matrix,f)) return EXIT_FAILURE;
  // printf("\noriginal matrix ->>>\n");
  // print_matrix(matrix);
  rotate(matrix);
  // printf("\nrotated matrix ->>>\n");
  print_matrix(matrix);

  if (fclose(f) != 0) {
    perror("Failed to close the input file!\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

