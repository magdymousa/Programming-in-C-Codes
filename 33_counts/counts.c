#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

//#define UNKNOWN "nothing"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *ptr = malloc(sizeof(*ptr));
  ptr->length = 1;
  ptr->names = malloc(sizeof(*ptr->names));
  ptr->names[0] = malloc(sizeof(**ptr->names));
  /* ptr->names[0]->name = malloc(8*sizeof(char *));
  char * name = "nothing";
  int i = 0;
  //ptr->names[0]->name = NULL;
  while(name[i] != '\0'){
    // printf("i = %d\n",i);
    ptr->names[0]->name[i] = name[i];
    i++;
  }
  ptr->names[0]->name = '\0';*/
  ptr->names[0]->count = 0;
  // free(name);
  return ptr;
}

static int strcmpare(const char *str1,const char *str2){
  int i = 0, return_value = 1;
  while(str1[i] != '\0' || str2[i] != '\0'){
    if(str1[i] != str2[i]){
      return_value = 0;
      break;
    }
    i++;
  }
  return return_value;
}
/*
void strcopy(char *str1,const char *str2){
  int i = 0;
  str1 = NULL;
  while(str2[i] != '\0'){
    str1 = realloc(str1,(i+1)*sizeof(*str1));
    printf("str2 = %c,i = %d\n",str2[i],i);
    str1[i] = str2[i];
    i++;
  }
}
*/
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  //  printf("length = %d\n",c->length);
  if(name == NULL){
    c->names[0]->count++;
  }
  else{
    //char *dummy = NULL ;
    //strcopy(dummy,name);
    // printf("not null\n");
    int flag = 0;
    for(int i = 1;i < c->length;i++){
      // printf("searching -> %d\n",i);
      if(strcmpare(c->names[i]->name,name)){
	c->names[i]->count++;
	flag = 1;
	//	free(dummy);
      }
      else{}
    }
    if(!flag){
      // printf("alocating ---> %d\n",c->length+1);
      c->names = realloc(c->names,(c->length+1)*sizeof(*c->names));
      c->names[c->length] = malloc(sizeof(**c->names));
      int i = 0;
      c->names[c->length]->name = NULL;
      while(name[i] != '\0'){
	c->names[c->length]->name = realloc(c->names[c->length]->name,(i+2)*sizeof(*c->names[c->length]->name));
	//printf("str2 = %c,i = %d\n",name[i],i);
	c->names[c->length]->name[i] = name[i];
	i++;
      }
      c->names[c->length]->name[i] = '\0';
      c->names[c->length]->count = 1;
      // printf("alocating ---> %s\n",c->names[c->length]->name);
      c->length++;}
  }
  // printCounts(c,stdout);
  // printf("\n----------------------\n");     
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i = 1;i < c->length;i++){
    fprintf(outFile,"%s: %d\n",c->names[i]->name,c->names[i]->count);
  }
  fprintf(outFile,"<unknown> : %d\n",c->names[0]->count);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  free(c->names[0]);
  for(int i = 1;i < c->length;i++){
    // printf("freeing ---> %d\n",i);
    free(c->names[i]->name);
    free(c->names[i]);
  }
  free(c->names);
  free(c);
}
