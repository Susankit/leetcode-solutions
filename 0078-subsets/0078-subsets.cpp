class Solution {
public:
    vector <vector <int>> ans; // THIS NEW VECTOR OF VECTORS WILL STORE THE ANSWER 
    vector <int> ds; // THIS VECTOR IS TO STORE THE CURRENT SUBSET
 
    // THIS FUNCTION WILL GENERATE ALL SUBSETS AND ADD IT TO ANS.
    void allSubsets (int i, vector <int>& nums) {
        if (i == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        allSubsets(i+1, nums);
        ds.pop_back();
        allSubsets(i+1, nums);
    }

    vector<vector<int>> subsets( vector<int>& nums) {
        allSubsets(0, nums);
        return ans;
    }
};