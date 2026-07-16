class Solution {
public:
    void findCombinations(int i, vector<int>& req, vector <int>& candidates, int target, vector <vector <int>>& ans) {
        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(req);
            }
            return;
        }
        if (candidates[i] <= target) {
            req.push_back(candidates[i]);
            findCombinations(i, req, candidates, target - candidates[i], ans);
            req.pop_back();
        }
        findCombinations(i+1, req, candidates, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> ans;
        vector <int> req;
        findCombinations(0, req, candidates, target, ans);
        return ans;
    }
};