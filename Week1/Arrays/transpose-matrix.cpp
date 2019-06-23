class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        vector<vector<int>> reVec(A[0].size(), vector<int>(A.size()));
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                reVec[j][i] = A[i][j];
            }
        }
            
        return reVec;
    }
};
