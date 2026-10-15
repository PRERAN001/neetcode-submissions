class Solution {
public:
    int area=0;
    int max_area=INT_MIN;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!=1){
            return;
        }
        area++;
        vis[i][j]=true;
        dfs(i+1,j,n,m,grid,vis);
        dfs(i-1,j,n,m,grid,vis);
        dfs(i,j+1,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i,j,n,m,grid,vis);
                    max_area=max(max_area,area);
                    area=0;
                }
            }
        }
        return max_area;
    }
};
