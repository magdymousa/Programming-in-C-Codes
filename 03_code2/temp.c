#include <stdio.h>
#include <stdlib.h>

int printTriangle(int size) {
  //start with starCount being 0
  int j = 0, i = 0, starcount = 0;
  //count from 0 (inclusive) to size (exclusive), for each number i that you count
  for(i = 0 ; i <size;i++){
    
     //count from 0 (inclusive) to i (inclusive), for each number j that you count
    for(j = 0 ; j <= i;i++){
      printf("*");
      starcount++;
    }
    printf("\n");
  }
  return starcount;
        //print a "*"

        //increment starCount

     //when you finish counting on j, 

     //print a newline ("\n")

  //when you finish counting on i, 

  //your answer is starCount

}


int main(void) {
  int numStars;
  printf("Here is a triangle with height 4\n");
  numStars = printTriangle(1);
  printf("That triangle had %d total stars\n", numStars);
  //now print "Here is a triangle with height 7\n"

  //then call printTriangle, passing in 7, and assign the result to numStars

  //finally, print "That triangle had %d total stars\n", such that the %d 
  //prints the value of numStars
  //  printf("Here is a triangle with height 7\n");
  // numStars = printTriangle(7);
  // printf("That triangle had %d total stars\n", numStars);

  return 0;
}



