#include <stdio.h>
#include <string.h>
#define HASH_PRIME 11117                          // 취향차이겠지만 HASH_PRIME에 값을 바꿔가면서 작성하는 것보다, 한번에 결과 값을 볼 수 있게 했으면 어땠을지

int hash_record[HASH_PRIME];

void init_record()
{
  int i;
  for (i=0; i<HASH_PRIME; i++)
    hash_record[i] = 0;
}

int hash(char key[5])
{
  int i;
  long long x;
  x=0;
  for (i=0; i<4; i++) 
  {
    x=x+key[i];
    x=x<<8;
  }
  x=x+key[4];
  return x%HASH_PRIME;
}

int sum_col(int n)
{
  int i;
  int col=0;
  for (i=0; i<n; i++)
  {
    if (hash_record[i] != 0)
      col += hash_record[i]-1;                  // 제 코드에 비해 효율적으로 짜신 것 같음
  }
  return col;
}

int key_comparisons()
{
  int i;
  int sum = 0;
  for (i=0; i<HASH_PRIME; i++)
    sum += hash_record[i]*(hash_record[i]+1)/2; // 취향 차이일 수도 있지만, 가독성을 위해 보통 연산자는 띄어쓰기를 함
  return sum;
}


int main()
{
  int i;
  int cnt=0;
  char word[100];
  init_record();
  FILE *f;
  f=fopen("words.dat","r");
                                                  // 파일이 열리지 않았을 경우 exit(-1)코드
  for (i=0; i<5757; i++)                          // 여기서 5757로 하면 문제 발생, dat 맨 앞이 *로 시작하는 것은 알아서 제외가 안됨. printf(fgets(word,sizeof(word), f)); 찍어보기
  {                                               // 결국에는 5757개의 문자열이 hash값에 맞게 들어가서 더해지기 때문에 결과는 동일할 수 있겠지만, 과정 상 논리적으로는 다를 수 있다고 
    fgets(word,sizeof(word), f);
    hash_record[hash(word)] += 1;
  }
  fclose(f);

  //printf("Hash Prime:%d / Number of collisions:%d\n",HASH_PRIME, sum_col(HASH_PRIME));
  printf("Hash Prime:%d / Total number of key comparions:%d\n",HASH_PRIME, key_comparisons());
}

  
  
