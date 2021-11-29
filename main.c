#include<stdio.h>
#include "my_mat.h"
#define N 10


int main(){
   int  graph[N][N]={0};
    FILE *fb= fopen("input3.txt","r");
    char single;
     while((single=fgetc(fb))!=EOF){
         if(single==' '){
             single=fgetc(fb);
         }
       if(single=='A'){
           A(fb,graph);
        }else{ if(single=='B'){
             single=fgetc(fb);
              if(single==' '){
                 single=fgetc(fb);
              }
             int i=single-48;
             single=fgetc(fb);
              if(single==' '){
                 single=fgetc(fb);
              }
             int j=single-48;
             B(i,j,graph);
             printf("\n");
        }else{if(single=='C'){

          single=fgetc(fb);
              if(single==' '){
                 single=fgetc(fb);
              }
             int i=single-48;
             single=fgetc(fb);
              if(single==' '){
                 single=fgetc(fb);
              }
             int j=single-48;
             int temp=C(i,j,graph);
            printf("%d",temp);
            printf("\n");
            }else{
                if (single=='D')
                {
                    break;
                }                
             }
           }
        }
     }
    fclose(fb);
    return 0;
}
