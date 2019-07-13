class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 0) return 0;
        if(points.size() == 1) return 1;
        sort(points.begin(), points.end());
        vector<vector<int>> vec;
        vec.push_back(points[0]);
        int j = 0;
        //for(auto a: points) cout << a[0] << " " << a[1] << endl;
        for(int i = 1; i < points.size(); ++i) {
            if(vec[j][1] < points[i][0]) {
            //if(vec[j][0] >= points[i][0] && vec[j][1] <= points[i][1]) {
                vec.push_back(points[i]);
                ++j;
            } else {
                if(vec[j][0] <= points[i][0] && vec[j][0] <= points[i][1]) {
                    vec[j][0] = points[i][0];
                }
                if(vec[j][1] >= points[i][1]) {
                    vec[j][1] = points[i][1];
                }
                //cout << "check: " << vec[j][0] << " " << vec[j][1] << endl;
            }
        }
        //cout << endl;
        //for(auto a: vec) cout << a[0] << " " << a[1] << endl;
        return vec.size();
    }
};
