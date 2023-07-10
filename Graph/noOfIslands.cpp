void dfs(int** arr, int i, int j, int n, int m) {

    if(i<0||j<0||i>=n||j>=m||arr[i][j]!=1)return;

    arr[i][j] = 0;

    int delrow[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int delcol[] = {0, 1, 0, -1, 1, -1, -1, 1};
    for (int k=0; k<8; k++) {
        int nrow = delrow[k] + i;
        int ncol = delcol[k] + j;
        dfs(arr, nrow, ncol, n, m);
    }
}
// OR
void dfs(int** arr, int i, int j, int n, int m) {
    arr[i][j] = 0;

    int delrow[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int delcol[] = {0, 1, 0, -1, 1, -1, -1, 1};
    for (int k=0; k<8; k++) {
        int nrow = delrow[k] + i;
        int ncol = delcol[k] + j;

        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && arr[nrow][ncol]==1){
            dfs(arr, nrow, ncol, n, m);
        }
    }
}
int getTotalIslands(int** arr, int v, int e)
{
   int ans = 0;    
    for (int i = 0; i < v; i++) {
        for(int j=0;j<e;j++){
            if (arr[i][j]==1) {
                ans++;
                dfs(arr, i, j, v, e);
            }
        }
    }
    return ans;
}
