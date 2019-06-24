class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> hm;
        for(int i = 0; i < nums.size(); i++) {
            if(hm.find(nums[i]) != hm.end()) {
                v.push_back(hm.at(nums[i]));
                v.push_back(i);
                return v;
            } else {
                hm.insert(make_pair(target - nums[i], i));
            }
        }
        return v;
    }
};
