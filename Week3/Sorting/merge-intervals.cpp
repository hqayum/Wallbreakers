class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 0) return {};
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= vec[j][1]) {
                if(vec[j][0] > intervals[i][0]) {
                    vec[j][0] = intervals[i][0];
                }
                if(vec[j][1] < intervals[i][1]) {
                    vec[j][1] = intervals[i][1];
                }
            } else {
                vec.push_back(intervals[i]);
                ++j;
            }
        }
        return vec;
    }
};
