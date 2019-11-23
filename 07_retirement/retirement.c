#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double balance;
void compute(int start,double init,retire_info strct){
  int Age = start;
  balance = init;
  while(Age < start + strct.months){
    printf("Age %3d month %2d you have $%.2lf\n",Age/12,Age%12,balance);    
    balance = balance + balance*strct.rate_of_return + strct.contribution;
    //printf("Age %3d month %2d you have $%.2lf\n",Age/12,Age%12,balance);
    Age++;
  }
}
void retirement (int startAge, double initial, retire_info working,retire_info retired){
  
  compute(startAge,initial,working);
  compute(startAge+working.months,balance,retired);

}

int main(void){
  retire_info working,retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(327, 21345.00, working, retired);
  return 0;
}
