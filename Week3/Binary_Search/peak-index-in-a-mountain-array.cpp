class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = INT_MIN, max_index = 0;
        int left = 0, right = A.size() - 2, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(A[mid] > max) {
                max = A[mid];
                max_index = mid;
            }
            if(A[mid] > A[mid+1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return max_index;
    }
};
