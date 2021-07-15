class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected;
        findcombination(candidates, selected, target, candidates.size() - 1);
        return _res;
    }
private:
    void findcombination(vector<int>& remind, vector<int>& selected, int target, int rbegin) {
        for (int i = rbegin; i >= 0; --i) {
            int temp = remind[i];
            if (temp == target) {
                vector<int> combination = selected;
                combination.push_back(temp);
                _res.push_back(combination);
            } else if (temp < target){
                vector<int> next_selected = selected;
                next_selected.push_back(temp);
                findcombination(remind, next_selected, target - temp, i);
            }
        }
    }    
    vector<vector<int>> _res;
};