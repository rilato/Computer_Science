#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "backend-bst.h"

#define DATA_SIZE 50
#define REPEAT 10000
char rdChar();
void rdName(char*);

int main()
{
  srand((unsigned)time(NULL));
  init_pool();

  char name[3];
  char number[4]={0};
  int N;
  int i=0,sum=0,sqSum=0;

  for(i=0; i<REPEAT; i++){
    N = DATA_SIZE;
    while (N--) {
      rdName(name);
      add(name,number);
    }
    sum+=height_val();
    sqSum+=height_val()*height_val();
    free_data();
  }
  double mean,sqMean,var,dev;
  mean = (double)sum/REPEAT;
  sqMean = (double)sqSum/REPEAT;
  var = sqMean-pow(mean,2);
  dev = sqrt(var);

  printf("DATA SIZE : %d, REPEAT : %d\n",DATA_SIZE,REPEAT,mean);
  printf("Mean of height: %f, Variance : %f, Standard deviation : %f\n",mean,var,dev);
}

char rdChar(){
  return rand()%25+97;
}

void rdName(char* name){
  name[0]=rdChar();
  name[1]=rdChar();
  name[2]=rdChar();
}
