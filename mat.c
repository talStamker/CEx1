#include<stdio.h>
#include<math.h>
#include "my_mat.h"
#define N 10




int min(int num1 , int num2,int num3){
if((num1==0||num2==0)&&num3==0){
return 0;
}else{ if(num1==0||num2==0){
    return num3;
}else{ if(num3==0){
    return num1+num2; 
}else {
    if(num1+num2>num3){
        return num3;
    }
    else{
        return num1+num2;
    }
}
}
}
}
void A(FILE *fb,int graph[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char ptr=fgetc(fb);
            if(ptr==' '){
             ptr=fgetc(fb);
            }
            int temp=ptr-48;
            while ((ptr=fgetc(fb))!=' ')
            {
                int temp2=ptr-48;
                temp=temp*10+temp2;
            }
            
            graph[i][j]=temp;
        }
        
    }

    
}
int matrix(int i,int j, int graph[N][N]){
    if(i==j)
    return 0;
    else{
        int matrix[N][N]={0};
        for(int k=0;k<N;k++){
            for (int s = 0; s < N; s++)
            {
                matrix[k][s]=graph[k][s];
            }
        }
        for(int k=0;k<N;k++){
            for (int s = 0; s < N; s++)
            {
                for (int t = 0; t < N; t++)
                {
                    if ((s==k)||(t==k))
                    {
                        continue;
                    }
                    if (s==t)
                    {
                        matrix[s][s]=0;
                    }
                    else{
                        matrix[s][t]=min(matrix[s][k],matrix[k][t],matrix[s][t]);
                    }
                    
                    
                }
                
                
            }
        }
        return matrix[i][j];
     }
    }
    int B(int i,int j, int graph[N][N]){
        if(matrix(i,j,graph)>0){
            printf("True");
            return 1;
        }
        else{
            printf("False");
            return 0;
        }

    }
    int C(int i,int j, int graph[N][N]){
        int temp=matrix(i,j,graph);
        if (temp>0)
        {
            return temp;
        }
        else{
        
           return -1;
        }

    }
    // int *temp=graph +i*N +j;

    // if (temp>0)
    // {
    //     return 1;
    // }

    // return 0;
