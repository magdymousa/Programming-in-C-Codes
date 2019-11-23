#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * return_name = malloc((strlen(inputName) + 8)*sizeof(*return_name));
  strcpy(return_name,inputName);
  strcat(return_name,".counts");
  return return_name;
}
