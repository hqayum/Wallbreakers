class Solution {
public:
    bool isSubsequence(string s, string t) {
        string temp;
        int i = 0, j = 0;
        while(j < t.size()) {
            if(s[i] == t[j]) {
                temp += t[j];
                if(temp.size() == s.size()) break;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return temp.compare(s) == 0;
    }
};
