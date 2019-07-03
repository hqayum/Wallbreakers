class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream s(str);
        string temp;
        vector<string> vec;
        while(s >> temp) vec.push_back(temp);
        
        if(pattern.size() != vec.size()) return false;
        
        unordered_map <char, string> uMap;
        for(int i = 0; i < pattern.size(); ++i) {
            if(uMap.find(pattern[i]) == uMap.end()) {
                uMap[pattern[i]] = vec[i];
            } else {
                if(uMap.at(pattern[i]) != vec[i]) return false;
            }
        }
        uMap.clear();
        unordered_map <string, char> checkMap2;
        for(int i = 0; i < vec.size(); ++i) {
            if(checkMap2.find(vec[i]) == checkMap2.end()) {
                checkMap2[vec[i]] = pattern[i];
            } else {
                if(checkMap2.at(vec[i]) != pattern[i]) return false;
            }
        }
        checkMap2.clear();
        return true;
    }
};
