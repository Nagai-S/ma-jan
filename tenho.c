#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int F(int x,int y,int z);

int main(void){
  srand((unsigned) time(NULL));

  int i,a[34],hai[14],x,k,l=0,j,b,count=0,c,n,m,y;
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
  // for (c = 0; c < 10; c++) {
    for (;;) {
      count=count+1;
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
      for (i = 0; i < 14; i++) {
        // ソーズを11から19にする
        if (hai[i]<=18 && hai[i]>=10) {
          hai[i]=hai[i]+1;
        }
        // ピンズを21から29にする
        if (hai[i]<=27 && hai[i]>=19) {
          hai[i]=hai[i]+2;
        }
        // 字牌を31から37にする
        if (hai[i]<=34 && hai[i]>=28) {
          hai[i]=hai[i]+3;
          }
      }
      // 一番左にある対子探し
      for (i = 0; i < 14; i++) {
        l=i;
        if (hai[i]==hai[i+1]) {
          break;
        }
      }

      if (l==12) {
        if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
          break;
        }
      }

      if (l==9) {
        if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
          if (hai[10]==hai[11]) {
            if (hai[12]==hai[13]) {
              break;
            }
          }
          else{
            if (F(hai[11],hai[12],hai[13])==1) {
              break;
            }
          }
        }
      }

      if (l==6) {
        if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1) {
          if (hai[7]==hai[8]) {
            for (i = l+3; i < 14; i++) {
              l=i;
              if (hai[i]==hai[i+1]) {
                break;
              }
            }
            if (l==12) {
              if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                break;
              }
            }

            if (l==9) {
              if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                if (hai[10]==hai[11]) {
                  if (hai[12]==hai[13]) {
                    break;
                  }
                }
                else{
                  if (F(hai[11],hai[12],hai[13])==1) {
                    break;
                  }
                }
              }
            }
          }

          else{
            if (F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
              break;
            }
          }
        }
      }

      if (l==3) {
        if (F(hai[0],hai[1],hai[2])==1) {
          if (hai[4]==hai[5]) {
            for (i = l+3; i < 14; i++) {
              l=i;
              if (hai[i]==hai[i+1]) {
                break;
              }
            }
            if (l==12) {
              if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                break;
              }
            }

            if (l==9) {
              if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                if (hai[10]==hai[11]) {
                  if (hai[12]==hai[13]) {
                    break;
                  }
                }
                else{
                  if (F(hai[11],hai[12],hai[13])==1) {
                    break;
                  }
                }
              }
            }

            if (l==6) {
              if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1) {
                if (hai[7]==hai[8]) {
                  for (i = l+3; i < 14; i++) {
                    l=i;
                    if (hai[i]==hai[i+1]) {
                      break;
                    }
                  }
                  if (l==12) {
                    if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                      break;
                    }
                  }

                  if (l==9) {
                    if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                      if (hai[10]==hai[11]) {
                        if (hai[12]==hai[13]) {
                          break;
                        }
                      }
                      else{
                        if (F(hai[11],hai[12],hai[13])==1) {
                          break;
                        }
                      }
                    }
                  }
                }

                else{
                  if (F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
                    break;
                  }
                }
              }
            }
          }

          else{
            if (F(hai[5],hai[6],hai[7])==1&&F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
              break;
            }
          }
        }
      }

      if (l==0) {
        if (hai[1]==hai[2]) {
          for (i = l+3; i < 14; i++) {
            l=i;
            if (hai[i]==hai[i+1]) {
              break;
            }
          }
          if (l==12) {
            if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
              break;
            }
          }

          if (l==9) {
            if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
              if (hai[10]==hai[11]) {
                if (hai[12]==hai[13]) {
                  break;
                }
              }
              else{
                if (F(hai[11],hai[12],hai[13])==1) {
                  break;
                }
              }
            }
          }

          if (l==6) {
            if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1) {
              if (hai[7]==hai[8]) {
                for (i = l+3; i < 14; i++) {
                  l=i;
                  if (hai[i]==hai[i+1]) {
                    break;
                  }
                }
                if (l==12) {
                  if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                    break;
                  }
                }

                if (l==9) {
                  if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                    if (hai[10]==hai[11]) {
                      if (hai[12]==hai[13]) {
                        break;
                      }
                    }
                    else{
                      if (F(hai[11],hai[12],hai[13])==1) {
                        break;
                      }
                    }
                  }
                }
              }

              else{
                if (F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
                  break;
                }
              }
            }
          }

          if (l==3) {
            if (F(hai[0],hai[1],hai[2])==1) {
              if (hai[4]==hai[5]) {
                for (i = l+3; i < 14; i++) {
                  l=i;
                  if (hai[i]==hai[i+1]) {
                    break;
                  }
                }
                if (l==12) {
                  if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                    break;
                  }
                }

                if (l==9) {
                  if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                    if (hai[10]==hai[11]) {
                      if (hai[12]==hai[13]) {
                        break;
                      }
                    }
                    else{
                      if (F(hai[11],hai[12],hai[13])==1) {
                        break;
                      }
                    }
                  }
                }

                if (l==6) {
                  if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1) {
                    if (hai[7]==hai[8]) {
                      for (i = l+3; i < 14; i++) {
                        l=i;
                        if (hai[i]==hai[i+1]) {
                          break;
                        }
                      }
                      if (l==12) {
                        if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1&&F(hai[9],hai[10],hai[11])==1) {
                          break;
                        }
                      }

                      if (l==9) {
                        if (F(hai[0],hai[1],hai[2])==1&&F(hai[3],hai[4],hai[5])==1&&F(hai[6],hai[7],hai[8])==1) {
                          if (hai[10]==hai[11]) {
                            if (hai[12]==hai[13]) {
                              break;
                            }
                          }
                          else{
                            if (F(hai[11],hai[12],hai[13])==1) {
                              break;
                            }
                          }
                        }
                      }
                    }

                    else{
                      if (F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
                        break;
                      }
                    }
                  }
                }
              }

              else{
                if (F(hai[5],hai[6],hai[7])==1&&F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
                  break;
                }
              }
            }
          }
        }
        else{
          if (F(hai[2],hai[3],hai[4])==1&&F(hai[5],hai[6],hai[7])==1&&F(hai[8],hai[9],hai[10])==1&&F(hai[11],hai[12],hai[13])==1) {
            break;
          }
        }
      }
    }
  // }

  // printf("%e\n",(double)count/10);

  // 色分けと漢字当て
  for (i = 0; i < 14; i++) {
    if (hai[i]<=9 && hai[i]>=1) {
      printf("\x1b[31m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=19 && hai[i]>=11) {
      hai[i]=hai[i]-10;
      printf("\x1b[32m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=29 && hai[i]>=21) {
      hai[i]=hai[i]-20;
      printf("\x1b[33m");
      printf("%d ",hai[i]);
    }

    if (hai[i]<=37 && hai[i]>=31) {
      hai[i]=hai[i]-30;
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
  printf("%d\n",count);

  return 0;
}

// 面子ができてるか調べる関数
int F(int x,int y, int z){
  int t;
  if (z>=30) {
    if (x==y&&y==z) {
      t=1;
    }
    else{t=0;}
  }
  else{
    if ((y-x)==1&&(z-y)==1) {
      t=1;
    }
    else if (x==y&&y==z) {
      t=1;
    }
    else{t=0;}
  }
  return t;
}
