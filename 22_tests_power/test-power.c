#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

unsigned power (unsigned x, unsigned y);

unsigned long long pows(unsigned base,unsigned exponent){
  unsigned long long result = 1;
  while (exponent != 0)
    {
      result *= base;
      --exponent;
    }
  printf("%lld \n",result);
  return result;
}

int main(void){
  // printf("value of unsigned = %x \n",(unsigned)-128);
  // printf("value of power = %lld \n",pows(2,(unsigned)100));
  //  printf("%ud \n",power(2,0x80000000));
  if(power(0,0) != 1){
    printf("EXIT_FAIL1\n");
    return EXIT_FAILURE;
  }
  else if(power(2,2) != 4){ 
    printf("EXIT_FAIL2\n");
    return EXIT_FAILURE;
  }
  else if(power(0,4) != 0){
    printf("EXIT_FAIL3\n");
    return EXIT_FAILURE;
  }
  else if(power(2,0) != 1){
    printf("EXIT_FAIL4\n");
    return EXIT_FAILURE;
  }
  else if(power(-1,1) !=(unsigned) -1){
    printf("EXIT_FAIL5\n");
    return EXIT_FAILURE;
  } 
  else if(power(2,32) != 0){
    printf("EXIT_FAIL6\n");
    return EXIT_FAILURE;
    }
  else{ 
    printf("EXIT_SUCCESS\n");
    return EXIT_SUCCESS;
  }
  return EXIT_SUCCESS;  
}

