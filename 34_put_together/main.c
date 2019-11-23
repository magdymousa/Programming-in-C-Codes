#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //  printf("file name = %s\n",filename);
  counts_t *file_counts = createCounts();
  kvarray_t *key_value =  readKVs(filename,1);

  for(int i = 0;i <key_value->length;i++){
    //    char * lookupValue(kvarray_t * pairs, const char * key);
    addCount(file_counts,lookupValue(kvPairs,key_value->kvpairs[i]->key));
  }
  //  printCounts(file_counts,stdout);
  freeKVs(key_value);
    //    void freeCounts(counts_t * c);
    return file_counts;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc < 3 ){
    fprintf(stderr,"not enough arguments\n");
    exit(EXIT_FAILURE);
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t *result =  readKVs(argv[1],0);
  counts_t *c;
    char * outname;
    //count from 2 to argc (call the number you count i)

    for(int i = 2;i < argc;i++){
      c =  countFile(argv[i],result);
      outname =  computeOutputFileName(argv[i]);
     FILE *f = fopen(outname,"w");
     printCounts(c,f);
     fclose(f);
     freeCounts(c);
     free(outname);
    }
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)


    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c
    //free(outname);
    //    freeCounts(c);
    freeKVs(result);

 //free the memory for kv

  return EXIT_SUCCESS;
}
