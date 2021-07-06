class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int step = 0;
        int res = -1;
        while (begin <= end)
        {
            int mid = (begin + end) >> 1;
            if (nums[mid] < nums[end]) {
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    step = mid;
                    break;
                }
                end = mid - 1;
            } else {
                if (mid < nums.size() - 1 && nums[mid + 1] < nums[mid] ) {
                    step = mid + 1;
                    break;
                }
                begin = mid + 1;
            }
        }
        int min = step;
        int max = step + nums.size() - 1;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (nums[mid % nums.size()] == target) {
                res = mid % nums.size();
                break;
            } 
            if (nums[mid % nums.size()] < target) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return res;
    }
};