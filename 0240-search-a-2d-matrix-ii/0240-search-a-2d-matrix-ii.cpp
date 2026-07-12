class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // cols
        for (int i=0; i<m; i++) {
            int low = 0, high = n-1;
            int mid;
            while (low <= high) {
                mid = (low + high) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};