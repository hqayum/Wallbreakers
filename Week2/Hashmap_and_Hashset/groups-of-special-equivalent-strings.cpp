class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set <string> uSet;
        for(string str: A) {
            string even = "", odd = "";
            for(int i = 0; i < str.size(); ++i) {
                if(i % 2 == 0) {
                    even += str[i];
                } else {
                    odd += str[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            uSet.insert(even + odd);
        }
        return uSet.size();
    }
};
