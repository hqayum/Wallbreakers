class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // Multiset solution
        multiset<int> mSet;
        vector<int> reVec;
        for(int i: nums) mSet.insert(i);
        for(int i = 1; i <= nums.size(); ++i) {
            if(mSet.find(i) != mSet.end()) {
                if(mSet.count(i) > 1) {
                    reVec.insert(reVec.begin(), i);
                }
            } else {
                reVec.push_back(i);
            }
        }
        return reVec;

        /*
        // unordered_map() solution
        unordered_map<int, int> uMap;
        vector<int> reVec;
        for(int i: nums) uMap[i]++;
        for(int i = 1; i <= nums.size(); ++i) {
            if(uMap.find(i) != uMap.end()) {
                if(uMap.at(i) > 1) reVec.insert(reVec.begin(), i);
            } else {
                reVec.push_back(i);
            }
        }
        return reVec;
        */
    }
};

