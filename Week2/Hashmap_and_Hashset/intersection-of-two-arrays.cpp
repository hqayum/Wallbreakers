class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> uSet;
        vector <int> reVec;
        for(int i = 0; i < nums1.size(); ++i) {
            uSet.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); ++i) {
            if(uSet.find(nums2[i]) != uSet.end()) {
                reVec.push_back(nums2[i]);
                uSet.erase(nums2[i]);
            }
        }
        return reVec;
    }
};
