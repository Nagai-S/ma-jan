#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
  srand((unsigned) time(NULL));

  int i,a[34],hai[14],x,k,l=0,j,b,y,m,n;
  char str1[]="東";
  char str2[]="南";
  char str3[]="西";
  char str4[]="北";
  char str5[]="白";
  char str6[]="発";
  char str7[]="中";
  // 牌の種類を与える
  for (i = 0; i < 34; i++) {
    a[i]=i+1;
  }
  // 牌を14枚選ぶ
  for (i = 0; i < 14; i++) {
    hai[i]=rand()%(136-i)+1;

    for (m = 0; m < i; m++) {
      for (n = m+1; n < i; n++) {
        if (hai[m]>hai[n]) {
          y=hai[m];
          hai[m]=hai[n];
          hai[n]=y;
        }
      }
    }

    for (j = 0; j < i; j++) {
      if (hai[i]>=hai[j]) {
        hai[i]=hai[i]+1;
      }
    }
  }
  // 選んだ14枚を34種類に分ける
  for (i = 0; i < 14; i++) {
    if (hai[i]>=1 && hai[i]<=34) {
      hai[i]=a[hai[i]-1];
    }

    if (hai[i]>=35 && hai[i]<=68) {
      hai[i]=a[hai[i]-1-34];
    }

    if (hai[i]>=69 && hai[i]<=102) {
      hai[i]=a[hai[i]-1-68];
    }

    if (hai[i]>=103 && hai[i]<=136) {
      hai[i]=a[hai[i]-1-102];
    }
  }

  // 理牌
  for (i = 0; i < 14; i++) {
    for (j = i+1; j < 14; j++) {
      if (hai[i]>hai[j]) {
        x=hai[i];
        hai[i]=hai[j];
        hai[j]=x;
      }
    }
  }
  
  // 色分けと漢字当て
  for (i = 0; i < 14; i++) {
    if (hai[i]<=9 && hai[i]>=1) {
      printf("\x1b[31m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=18 && hai[i]>=10) {
      hai[i]=hai[i]-9;
      printf("\x1b[32m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=27 && hai[i]>=19) {
      hai[i]=hai[i]-18;
      printf("\x1b[33m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=34 && hai[i]>=28) {
      hai[i]=hai[i]-27;
      if (hai[i]==1) {
        printf("\x1b[34m");
        printf("%s ",str1);
      }

      if (hai[i]==2) {
        printf("\x1b[34m");
        printf("%s ",str2);
      }

      if (hai[i]==3) {
        printf("\x1b[34m");
        printf("%s ",str3);
      }

      if (hai[i]==4) {
        printf("\x1b[34m");
        printf("%s ",str4);
      }

      if (hai[i]==5) {
        printf("\x1b[34m");
        printf("%s ",str5);
      }

      if (hai[i]==6) {
        printf("\x1b[34m");
        printf("%s ",str6);
      }

      if (hai[i]==7) {
        printf("\x1b[34m");
        printf("%s ",str7);
      }
    }
  }

  printf("\x1b[37m");
  printf("\n");

  return 0;
}
