#include <stdio.h>

unsigned power (unsigned x, unsigned y){
  //  printf("entered power\n");
  if(((y == 0)&&(x == 0)) ||(y == 0)) return 1;
  if(x == 0) return 0;
  
  if(y == 1) return x;
  else return x*power(x,y-1);
}
