class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() <= 0) {
            return "";
        } else if(strs.size() == 1) {
            return strs[0];
        }
        
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            if(str.size() > strs[i].size()) {
                str = strs[i];
                continue;
            }
            for(int j = 0; j < strs[i].size() && j < str.size(); j++) {
                if(str[j] != strs[i][j]) {
                    str.erase(j, str.size());
                    if(str == "") return str;
                    break;
                }
            }
        }
        
        for(int i = 0; i < strs.size(); i++) {
            for(int j = 0; j < str.size(); j++) {
                if(str[j] != strs[i][j]) {
                    str.erase(j, str.size());
                    break;
                }
            }
        }
        
        return str;
    }
};
