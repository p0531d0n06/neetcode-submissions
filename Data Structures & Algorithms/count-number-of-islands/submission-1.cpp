class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        
        for(int m = 0; m < grid.size(); m++){
            for(int n = 0; n < grid[0].size(); n++){
                if(grid[m][n] == '0'){
                    continue;
                }

                updateField(grid, m, n);
                numIslands++;
            }
        }

        return numIslands;
    }

    void updateField(vector<vector<char>>& grid, int currentM, int currentN){
        grid[currentM][currentN] = '0';
        int visit[4][2] = {
            {currentM-1, currentN},
            {currentM, currentN-1},
            {currentM, currentN+1},
            {currentM+1, currentN}
        };

        for(int i = 0; i < 4; i++){
            if(visit[i][0] < 0 ||
               visit[i][1] < 0 ||
               visit[i][0] >= grid.size() ||
               visit[i][1] >= grid[0].size() ||
               grid[visit[i][0]][visit[i][1]] == '0'
            ){
                continue;
            }
            updateField(grid, visit[i][0], visit[i][1]);
        }
    }
};
