#include<stdio.h>
#include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int line_start = 0;
    int col_start  = 0;
    int n = *matrixColSize;
    int m = matrixSize;
    int col_end = n;
    int line_end = m;
    int *k = (int*)malloc(sizeof(int)*m*n);
    int poi = 0;
    //col_start = 1 line_start = 1
    while(line_end>=1 && col_end >=1){
        //col_start = 1 col_end = 1
        //col_end = 1 1
        //printf("%d %d\n",line_end,col_end);
        for(int i=col_start;i<col_start + col_end-1;i++){
           
           k[poi++] = matrix[line_start][i]; 

        }
        for(int i=line_start;i<line_start + line_end-1;i++){
            
            k[poi++] = matrix[i][col_start+col_end-1];
        }

        for(int i=col_start + col_end -1;i>col_start;i--){
  
            k[poi++] = matrix[line_start+line_end-1][i];
        }
        for(int i=line_start + line_end-1;i>line_start;i--){
           
            
            k[poi++] = matrix[i][col_start];
        }
        //if(line_end==1 && col_end ==1) k[poi] = matrix[line_start][col_start];
        line_start += 1;
        col_start  += 1;
        line_end -= 2;
        col_end -= 2;
    }
    //if(line_end==1 && col_end ==1) k[poi] = matrix[line_start][col_start]
    *returnSize = poi;
    return k;
}
int *traverse(int** data,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    
    int line_start = 0;
    int col_start  = 0;
    int col_end = n;
    int line_end = m;
    int *k = (int*)malloc(sizeof(int)*m*n);
    int poi = 0;
    while(line_end>=1 && col_end >=1){
        //col_start = 1 col_end = 1
        //printf("%d %d\n",line_end,col_end);

        for(int i=col_start;i<col_start + col_end-1;i++){
           
           k[poi++] = data[line_start][i]; 

        }
        for(int i=line_start;i<line_start + line_end-1;i++){
            
            k[poi++] = data[i][col_start+col_end-1];
        }

        for(int i=col_start + col_end -1;i>col_start;i--){
  
            k[poi++] = data[line_start+line_end-1][i];
        }
        for(int i=line_start + line_end-1;i>line_start;i--){
           
            
            k[poi++] = data[i][col_start];
        }

        line_start += 1;
        col_start  += 1;
        line_end -= 2;
        col_end -= 2;
    }
    //poi = poi -1;
    //printf("%d\n",poi);
    
    for(int i=0;i<poi;i++){
        printf("%d ",k[i]);
    }
}
int main(){
    int data[1][3]={{7,8,9}};
    //int *tmp[] = &data;
    int *input[] ={ data[0],data[1],data[2]};
    //printf("%d\n",input[0][1]);

    traverse((int**)input,1,3);
    //
}