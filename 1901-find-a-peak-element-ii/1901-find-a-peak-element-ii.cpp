class Solution {
public:
    int findMaxInd(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int m = mat[0].size();
        int maxVal = -1;
        int index = -1;
        for (int i=0; i<n; i++) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxRowInd = findMaxInd(mat, mid);
            int left, right;
            if (mid - 1 >= 0) {
                left = mat[maxRowInd][mid-1];
            } else {
                left = -1;
            }
            if (mid + 1 < m) {
                right = mat[maxRowInd][mid+1];
            } else {
                right = -1;
            }
            if (mat[maxRowInd][mid] > left && mat[maxRowInd][mid] > right) {
                return {maxRowInd, mid};
            } else if (mat[maxRowInd][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};