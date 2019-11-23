void swapp(char *ptr1,char *ptr2){
  char temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}
void rotate(char matrix[10][10]){
  int i =0 , j = 0,k = 0;
  int len = 10,z = 10;
  
  for(i = 0, z = 9;i<len/2;i++,z--){
    for(j = i,k = z ;j<len-i-1;j++,k--){
      swapp(&matrix[i][j],&matrix[j][z]);
      swapp(&matrix[i][j],&matrix[k][i]);
      swapp(&matrix[k][i],&matrix[z][k]);
    }
  }
  
}
