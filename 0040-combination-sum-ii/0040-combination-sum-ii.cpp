class Solution {
public:
    void findCombinations(int idx, vector <int>& req, vector <int>& candidates, int target, vector <vector <int>>& ans) {
        
            if (target == 0) {
                ans.push_back(req);
                return;
            }
            
        
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            req.push_back(candidates[i]);
            findCombinations(i+1, req, candidates, target - candidates[i], ans);
            req.pop_back();
        }
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <int> req;
        vector<vector<int>> ans;
        findCombinations(0, req, candidates, target, ans);
        return ans;
    }
};