class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() <= 1) return A;
        
        int left = 0, right = A.size() - 1;
        while(left < right) {
            if(A[left] % 2 == 1) {
                swap(A[left], A[right--]);
            } else {
                left++;
            }
        }
        return A;
        
        /*
        // my initial code
        
        if(A.size() <= 1) return A;
        
        vector<int> v;
        
        int i;
        for(i = 0; i < A.size(); i++) {
            if(A[i] % 2 == 0) {
                v.insert(v.begin(), 1, A[i]);
            } else {
                v.push_back(A[i]);
            }
        }
        return v;
        */
    }
};