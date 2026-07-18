class Solution {
public:
    void findPermutations(int idx, vector <int>& nums, vector <vector <int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i=idx; i<nums.size(); i++) {
            int temp = nums[idx];
            nums[idx] = nums[i];
            nums[i] = temp;
            findPermutations(idx+1, nums, ans);
            temp = nums[idx];
            nums[idx] = nums[i];
            nums[i] = temp;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};