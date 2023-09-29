//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  void dfs(int row,int col,int delrow[],int delcol[], vector<vector<int>> &grid, vector<vector<int>> &vis){
      vis[row][col]=1;
      
      int n=grid.size();
      int m=grid[0].size();
      for(int i=0; i<4; i++){
          int drow = row + delrow[i];
          int dcol = col + delcol[i];
          if(drow>=0 && drow<n & dcol>=0 && dcol<m && !vis[drow][dcol] && grid[drow][dcol]){
              dfs(drow,dcol,delrow,delcol,grid,vis);
          }
      }
  }
  public:
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]) dfs(i,0,delrow,delcol,grid,vis);
            if(!vis[i][m-1] && grid[i][m-1]) dfs(i,m-1,delrow,delcol,grid,vis);
        }
        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]) dfs(0,j,delrow,delcol,grid,vis);
            if(!vis[n-1][j] && grid[n-1][j]) dfs(n-1,j,delrow,delcol,grid,vis);
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]) cnt++;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends