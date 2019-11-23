#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

#define N 1
kvarray_t *readPAS(const char * fname){
  FILE *f = fopen(fname,"r");
  if(f == NULL) exit(EXIT_FAILURE);
  kvarray_t *kv_array = malloc(sizeof(*kv_array));
  kv_array->kvpairs = NULL;
  //kv_array->kvpairs = malloc(8*sizeof(*kv_array->kvpairs));
  /*for(int i = 0;i < 6;i++){
    kv_array->kvpairs[i] = malloc(sizeof(**kv_array->kvpairs));
    }*/
  kv_array->length = 0;
  char *line = NULL;
  size_t allocated_N = 0,i = 0,j = 0;
  while(getline(&line,&allocated_N,f) >= 0){
    kv_array->kvpairs = realloc(kv_array->kvpairs,(j+1)*sizeof(*kv_array->kvpairs));
    kv_array->kvpairs[j] = malloc(sizeof(**kv_array->kvpairs));
    // kv_array->kvpairs[j] = malloc(sizeof(char *));
    kv_array->kvpairs[j]->key = line;
    while(line[i] != '\n'){
      i++;
    }
    line[i] = '\0';
    i = 0;
    kv_array->length = j+1;
    line = NULL;
    //printf("allocate -> %ld\n",j);
    j++;
  }
  free(line);
  if(fclose(f) != 0){
    fprintf(stderr,"can not close file");
    exit(EXIT_FAILURE);
  }
  // printf("length = %d \n",kv_array->length);
  return kv_array;
}
kvarray_t * readKVs(const char * fname,int dis) {
  if(dis) return readPAS(fname);
  FILE *f = fopen(fname,"r");
  if(f == NULL) exit(EXIT_FAILURE);
  kvarray_t *kv_array = malloc(sizeof(*kv_array));
  kv_array->kvpairs = NULL;
  //kv_array->kvpairs = malloc(8*sizeof(*kv_array->kvpairs));
  /*for(int i = 0;i < 6;i++){
    kv_array->kvpairs[i] = malloc(sizeof(**kv_array->kvpairs));
    }*/
  kv_array->length = 0;
  char *line = NULL;
  size_t allocated_N = 0,i = 0,j = 0;
  // printf("file name = %s\n",fname);                                            
  while(getline(&line,&allocated_N,f) >= 0){
    //printf("ALL_N = %ld\n",allocated_N);
    i = 0;
    //char * curr = line;
    while(line[i] != '='){
      i++;
    }
    line[i++] = '\0';
    kv_array->kvpairs = realloc(kv_array->kvpairs,(j+1)*sizeof(*kv_array->kvpairs));
    kv_array->kvpairs[j] = malloc(sizeof(**kv_array->kvpairs));
    // kv_array->kvpairs[j] = malloc(sizeof(char *));
    kv_array->kvpairs[j]->key = line;
    kv_array->kvpairs[j]->value = &line[i];
    while(line[i] != '\n'){
      i++;
    }
    line[i] = '\0';
    kv_array->length = j+1;
    line = NULL;
    //printf("allocate -> %ld\n",j);  
    j++;
  }
  free(line);
  if(fclose(f) != 0){
    fprintf(stderr,"can not close file");
    exit(EXIT_FAILURE);
  }
  // printf("length = %d \n",kv_array->length);
  return kv_array;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i = 0;i < pairs->length;i++){
    free(pairs->kvpairs[i]->key);
    free(pairs->kvpairs[i]);
    //    free(pairs->kvpairs[i]->value);
    //printf("free -> %d\n",i);
  }
  free(pairs->kvpairs);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i = 0;i <pairs->length;i++){
    printf("key = '%s' value = '%s'\n",pairs->kvpairs[i]->key,pairs->kvpairs[i]->value);
  }
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

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  // char *rt_value = NULL;
  int i = 0;
  for(i = 0;i <pairs->length;i++){
    if( strcmpare(pairs->kvpairs[i]->key,key) == 1){
      //rt_value = pairs->kvpairs[i]->value;
      return pairs->kvpairs[i]->value;
    }
  }
  return NULL;
}
