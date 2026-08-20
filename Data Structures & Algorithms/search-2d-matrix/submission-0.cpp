class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l = 0;
        int n = matrix[0].size();
        int r = (matrix.size() * matrix[0].size()) - 1;
        int mid;

        while(l <= r){
            mid = (l+r)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            } else if (matrix[mid/n][mid % n] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};