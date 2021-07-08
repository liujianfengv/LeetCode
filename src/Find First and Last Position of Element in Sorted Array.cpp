class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int lo = 0, hi = nums.size() - 1;
        int start = -1, end = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target) {
                start = mid;
                hi = mid - 1;
            } else if (nums[mid] < target){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target) {
                end = mid;
                lo = mid + 1;
            } else if (nums[mid] < target){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return {start, end};
    }
};