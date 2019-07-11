class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0) {
            return -1;
        }
        if(nums.size() == 1) {
            if(target == nums[0]) return 0;
            return -1;
        }
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
