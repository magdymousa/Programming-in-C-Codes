#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count){
  qsort(data, count, sizeof(char *), stringOrder);
}

void processFile(char *arg);
void get_stdin(int ,char *);
void print_data(char **str,int count);

int main(int argc, char ** argv) {
  //char *str[] = {"zmagd","sdanan","abobobo","emanificent"};
  // size_t dan = 0;
  int i = 0;
 
  // read input
  if(argc == 1){
    // printf("one arg\n");
    get_stdin(0,"done");
  }
  else if(argc > 1){
    for(i = 1;i < argc;i++){
      get_stdin(1,argv[i]);      
   }
  }
  return EXIT_SUCCESS;
}

/*
void processFile(char *arg){
  char * str[50] = {NULL};
  int i = 0;
  size_t sz = 0;
  FILE *f = fopen(arg,"r");
  while(getline(&str[i],&sz,f) != EOF){
    i++;
  }
  sortData(str,i);
  print_data(str,i);
  while(i >= 0){
   free(str[i]);
   i--;
  }
}*/

void print_data(char **str,int count){
  for(int i = 0;i < count;i++){                                                       
    printf("%s",str[i]); 
    free(str[i]);
  }
}

void get_stdin(int x,char *arg){
  char ** str = NULL;
  char *curr = NULL;
  int i = 0;
  size_t sz = 0;
  FILE * used_stream = NULL;
  if(x == 0) used_stream = stdin;
  else{
    used_stream = fopen(arg,"r");
    if(used_stream == NULL) {
      fprintf(stderr,"can not open file");
      exit(EXIT_FAILURE);
    }
  }
  while(getline(&curr,&sz,used_stream) >= 0){
    str = realloc(str,(i+1)*sizeof(*str));
    str[i] = curr;
    curr = NULL;
    i++;
  }
  if(x != 0){
    if(fclose(used_stream) != 0){
      fprintf(stderr,"can not close file");
      exit(EXIT_FAILURE);
    }
  }
  free(curr);
  //  getline(&str[i],&sz,stdin); 
  // free(str);
  sortData(str,i);
  print_data(str,i);
  free(str);
  /* while(i >= 0){
    free(str[i]);
    i--;
    }*/
}
