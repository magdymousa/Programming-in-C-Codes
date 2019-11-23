#include <stdio.h>

#include <stdlib.h>



size_t maxSeq(int * array, size_t n);



int main(void){
  
  int p[3][8] = {{1,2,3,4,5,6,7,8},{1,0,2,4,6,9,1,4},{1,1,1,1,1,1,1,1}};
  
  int z[3][4] = {{2,1,0,-1},{5,10,-10,-5},{1,-1,-5,-9}};
  
  //  int z[3][4] = {{1,5,6,8},{1,2,10,20},{90,4,3,1}};
  
  // unsigned int z[3][4] = {{-10,-5,-2,0},{-1,2,10,20},{1,-1,-5,-9}};
  

  
  if(maxSeq(p[0],8) != 8){
    
    printf("EXIT_FAIL1\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(p[1],8) != 5){
    
    printf("EXIT_FAIL2\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(p[2],8) != 1){
    
    printf("EXIT_FAIL3\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(z[0],4) != 1){
    
    printf("EXIT_FAIL4\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(z[1],4) != 2){
    
    printf("EXIT_FAIl5\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(NULL,0) != 0){
    
    printf("EXIT_FAIl6\n");
    
    return EXIT_FAILURE;
    
  }
  
  else if(maxSeq(p[2],0) != 0){
    
    printf("EXIT_FAIL7\n");
    
    return EXIT_FAILURE;
    
  }
  
  else{
    
    printf("EXIT_SUCCESS\n");
    
    return EXIT_SUCCESS;
    
  }
  
  return EXIT_SUCCESS;
  
}



