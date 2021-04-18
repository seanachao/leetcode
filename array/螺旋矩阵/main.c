/*
m 行 n列
(line_start,col_start)            -> (line_start,col_start+n-1)
列不变，行加一                       -> 列不变，行递增
(line_start+1,col_start+n-1)      -> (line_start+m-1,col_start+n-1)
行不变，列递减
(line_start+m-1,col_start+n-2)    -> (line_start+m-1, col_start) 
行递减，列不变
(line_start+m-2,col_start)        -> (line_start+1,col_start)
m = m - 2
n = n - 2
col_start = colo_start  + 1
line_start = line_start + 1
*/
#include<stdio.h>
#include<stdlib.h>

void spiralOrder_example(){
     //int data[3][4] =  {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
     int data[2][3] =  {{2,5,8},{4,0,-1}};
    int line_start = 0;
    int col_start = 0;
    int m=2 ,n =3;
    while(m>=1 && n >=1){
        for(int i= col_start ;i<=col_start+n-1;i++){
            //printf("the col is %d line is %d ",line_start,i);
            printf("%d ",data[line_start][i]);
        }

        printf(" line1 \n");
  
        for(int i= line_start+1;i<=line_start+m-1;i++){
            printf("%d ",data[i][col_start+n-1]);

        }

        printf(" line2 \n");
        if(m>1 && n >1){
        for(int i=col_start+n-2;i>=col_start;i--){
            printf("%d ",data[line_start+m-1][i]);

        }
        //printf("test3\n");
        printf(" line3 \n");
        for(int i=line_start+m-2;i>=line_start+1;i--){
            printf("%d ",data[i][col_start]);

        }
        }

        printf(" line4 \n");
        col_start += 1;
        line_start += 1;
        n = n - 2;
        m = m - 2;


    }
}
void spiralOrder_test(int** matrix){

    // int (*input)[4] = (int (*)[4])matrix;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         printf("%d ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d ",matrix[0][0]);

    //for(int i=0;i++;i<4)
}
int* spiralOrderCopy(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    int n = *matrixColSize;
    int total_n = *matrixColSize;
    int* res = (int*)malloc(sizeof(int)*m*n);
    int line_start = 0;
    int col_start = 0;
    int (*input)[total_n] = (int (*)[total_n])matrix;
    int data = 0;
    int k = 0;
    //data[m][n] = ((int*)data+m*col)+n)
    while(m>=1 && n >=1){
        for(int i= col_start ;i<=col_start+n-1;i++){

            data = input[line_start][i];
            res[k++] = data;
            //printf("%d ",data);
        }


        for(int i= line_start+1;i<=line_start+m-1;i++){
            data = input[i][col_start+n-1];
            res[k++] = data;
            //printf("%d ",data);
        }


        
        for(int i=col_start+n-2;i>=col_start;i--){
            //data = *((int*)matrix+(line_start+m-1)*total_n+i);
            data = input[line_start+m-1][i];
            //printf("%d ",matrix[line_start+m-1][i]);
            res[k++] = data;
            //printf("%d ",data);
        }


        for(int i=line_start+m-2;i>=line_start+1;i--){
            //data = *((int*)matrix+i*total_n+col_start);
            //printf("%d ",matrix[i][col_start]);
            data = input[i][col_start];
            res[k++] = data;
            //printf("%d ",data);

        }
        


        col_start += 1;
        line_start += 1;
        n = n - 2;
        m = m - 2;

       // printf("hello\n");

    }
    *returnSize = k;
    return res;
    
}
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    int n = *matrixColSize;
    int total_n = n;
    int* res = (int*)malloc(sizeof(int)*m*n);
    int line_start = 0;
    int col_start = 0;
    int data = 0;
    //data[m][n] = ((int*)data+m*col)+n)
    while(m>=0 && n >=0){
        for(int i= col_start ;i<=col_start+n-1;i++){

            data = *((int*)(matrix+line_start*total_n)+i);
            printf("the col is %d line is %d ",line_start,i);
            printf("%d \n",data);
        }
        printf("line1\n");
        for(int i= line_start+1;i<=line_start+m-1;i++){
            data = *((int*)matrix+i*total_n+col_start+n-1);
            //printf("%d ",matrix[i][col_start+n-1]);
            printf("%d ",data);
        }
    printf("line2\n");
        if(m>1 && n >1){
        for(int i=col_start+n-2;i>=col_start;i--){
            data = *((int*)matrix+(line_start+m-1)*total_n+i);
            //printf("%d ",matrix[line_start+m-1][i]);
            printf("%d ",data);
        }
    printf("line3\n");
        for(int i=line_start+m-2;i>=line_start+1;i--){
            data = *((int*)matrix+i*total_n+col_start);
            //printf("%d ",matrix[i][col_start]);
            printf("%d ",data);

        }
        }
        printf("line4\n");
        col_start += 1;
        line_start += 1;
        n = n - 2;
        m = m - 2;


    }
  
}
int main(){
    ///[1,2,3,4,8,12,11,10,9,5,6,7]
  int data[3][3] =  {{1,2,3},{4,5,6},{7,8,9}};
  //int **p = NULL;
  //*p = data[0];
  //printf("%d ",**p);
  int n = 3;
  int* ptr_n = NULL;
  ptr_n = &n;
  int res_size = 0;
  int* ptr_k = NULL;
  ptr_k = &res_size;
  spiralOrder_test((int**)data);
  //spiralOrder((int**)data,3,ptr_n,ptr_n);
  ///printf("\n");
//   spiralOrder_example();
//   //printf("\n");
//   //int *re = NULL;
//   int* re = spiralOrderCopy((int**)data,3,ptr_n,ptr_k);
//   for(int i=0;i<*ptr_k;i++){
//       printf("%d ",re[i]);
//   }
}

