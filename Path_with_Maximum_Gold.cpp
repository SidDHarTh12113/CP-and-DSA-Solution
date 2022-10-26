class Solution {
public:
    int getMaximumGoldHelper(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis) {
        
        // Base Case
        if(i >= grid.size() or i < 0 or j < 0 or j >= grid[0].size()) {
            return 0;
        }
        if(grid[i][j] == 0) {
            return 0;
        }
        if(vis[i][j] == true) {
            return 0;
        }
        
        // Recursive Case
        vis[i][j] = true;
        int ans = grid[i][j] + max({getMaximumGoldHelper(grid, i + 1, j, vis), getMaximumGoldHelper(grid, i, j + 1, vis), getMaximumGoldHelper(grid, i - 1, j, vis), getMaximumGoldHelper(grid, i, j - 1, vis)});
        vis[i][j] = false;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size() , vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, getMaximumGoldHelper(grid, i, j, vis));
            }
        }
        return ans;
    }
};