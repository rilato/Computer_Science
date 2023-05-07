#include <stdio.h>
#include <stdlib.h>
#define M1 7000
#define M2 6997
#define M3 12000
#define M4 11117
#define M5 22000
#define M6 22307

int hash(char key[5],int hashPrime){
    int i;
    long long x;

    x=0;
    for(i=0; i<4; i++){
        x=x+key[i];
        x=x<<8;
    }
    x=x+key[4];
    return x%hashPrime;
}

int main(){
    char key[5];
    int m1[M1]={0}, m2[M2]={0}, m3[M3]={0}, m4[M4]={0}, m5[M5]={0}, m6[M6]={0};
    FILE *fp=NULL;
    
    fp = fopen("words.dat","r");
    for (int i = 0; i < 4; i++)
    {
        fgets(key,100,fp);
    }
    for (int i = 0; i < 5757; i++)
    {
        fgets(key,6,fp);
        ++m1[hash(key,M1)];
        ++m2[hash(key,M2)];
        ++m3[hash(key,M3)];
        ++m4[hash(key,M4)];
        ++m5[hash(key,M5)];
        ++m6[hash(key,M6)];
        fgets(key,100,fp);
    }
    fclose(fp);

    int collision[6]={0};
    for (int i = 0; i < M1; i++)
    {   
        if(m1[i]>1)
            collision[0]+=m1[i]-1;
    }
    for (int i = 0; i < M2; i++)
    {
        if(m2[i]>1)
            collision[1]+=m2[i]-1;
    }
    for (int i = 0; i < M3; i++)
    {
        if(m3[i]>1)
            collision[2]+=m3[i]-1;
    }
    for (int i = 0; i < M4; i++)
    {
        if(m4[i]>1)
            collision[3]+=m4[i]-1;
    }
    for (int i = 0; i < M5; i++)
    {
        if(m5[i]>1)
            collision[4]+=m5[i]-1;
    }
    for (int i = 0; i < M6; i++)
    {
        if(m6[i]>1)
            collision[5]+=m6[i]-1;
    }
    
    for (int i = 0; i < 6; i++)
    {
        printf("M%ds collision : %d\n",i+1,collision[i]);
    }
    
    int comparison=0;
    for (int j = 0; j < M4; j++)
    {
        if(m4[j]>0)
            comparison+=m4[j]*(m4[j]+1)/2;
    }
    printf("\n%d\n",comparison);
    return 0;
}