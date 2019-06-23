class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++) {
            int left = 0;
            int right = A[i].size() - 1;
            while(left < right) {
                swap(A[i][left++], A[i][right--]);
            }
        }
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                A[i][j] ^= 1;
            }
        }
        return A;
    }
};