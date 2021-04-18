int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;      /* m,n 最小为1 */
    int n = matrixColSize[0];
    int *res = (int*)malloc(sizeof(int) * m * n);
    int i;
    int idx   = 0;
    int up    = 0;
    int down  = m - 1;
    int left  = 0;
    int right = n - 1;
    
    /* 按照顺时针遍历矩阵, 同时矩阵收缩 */
    while (up <= down && left <= right) {
        for (i = left; i <= right; i++) { /* 上 */
            res[idx++] = matrix[up][i];
        }
        up++;
        for (i = up; i <= down; i++) {    /* 右 */
            res[idx++] = matrix[i][right];
        }
        right--;
        for (i = right; i >= left && up <= down; i--) { /* 下, 注意此处需要有up<=down的判断 */
            res[idx++] = matrix[down][i];
        }
        down--;
        for (i = down; i >= up && left <= right; i--) { /* 左, 注意此处需要有left<=right的判断 */
            res[idx++] = matrix[i][left];
        }
        left++;
    }
    *returnSize = idx;
    return res;
}

作者：liu-xiang-3
链接：https://leetcode-cn.com/problems/spiral-matrix/solution/cyu-yan-shun-shi-zhen-bian-li-ju-zhen-to-x71q/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。