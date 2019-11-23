#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



size_t maxSeq(int * array, size_t n){
  int current_max_seq = 1;
  int max_seq = 1;
  int i = 0;
  /* 
  for(i = 0;i < n;i++){  
    printf("%d ",array[i]);
  }
  */
  // printf("\nnum of elements = %d \n",(int)n);
  if((int)n == 0 || array == NULL){
    //printf("return NULL \n");
    return 0;  
  }
  
  if((int)n == 1){
    return 1;
  }
 
  for(i = 0;i < n-1;i++){   
    // printf("max seq = %d \n",max_seq);
    // printf("current_max_seq = %d\n",current_max_seq);
    
    if(array[i] < array[i+1]){
      // printf("  %d < %d\t",array[i],array[i+1]);
      current_max_seq ++;
    }
    else{ 
      // printf("  %d > %d\t",array[i],array[i+1]);
      if(current_max_seq > max_seq){
	max_seq = current_max_seq;
      }
      current_max_seq = 1;
    }
  }
  if(current_max_seq > max_seq){ 
    max_seq = current_max_seq;
  }
  // printf("\nmax seq = %d \n",max_seq);
  return max_seq;  
}
