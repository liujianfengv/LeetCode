class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0;
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == tmp) {
                continue;
            }
            nums[++index] = nums[i];
            tmp = nums[i];
        }
        return index + 1;
    }
};