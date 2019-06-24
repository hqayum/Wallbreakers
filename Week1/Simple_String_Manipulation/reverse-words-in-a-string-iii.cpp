class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        while(right < s.size()) {
            int charVal = (int) s[right];
            if(s[right] == 32) {
                int hold = right--;
                while(left < right) {
                    swap(s[left++], s[right--]);
                }
                right = hold + 1;
                left = right;
            } else if(right == s.size() - 1) {
                while(left < right) {
                    swap(s[left++], s[right--]);
                }
                break;
            }
            ++right;
        }
        return s;
    }
};
