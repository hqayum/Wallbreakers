class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> hm1;
        unordered_map<char, int> hm2;
        int temp;
        for(int i = 0; i < s.size(); ++i) {
            if(hm1.find(s[i]) == hm1.end()) {
                hm1.insert(make_pair(s[i], 1));
            } else {
                temp = hm1.at(s[i]);
                hm1[s[i]] = temp + 1;
            }
            //cout << s[i] << " ";
            //cout << hm1.at(s[i]) << endl;
        }
        //cout << endl;
        for(int i = 0; i < t.size(); ++i) {
            if(hm2.find(t[i]) == hm2.end()) {
                hm2.insert(make_pair(t[i], 1));
            } else {
                temp = hm2.at(t[i]);
                hm2[t[i]] = temp + 1;
            }
            //cout << t[i] << " ";
            //cout << hm2.at(t[i]) << endl;
        }
        
        if(hm1.size() != hm2.size()) return false;
        for(auto itor = hm1.begin(); itor != hm1.end(); ++itor) {
            if(hm2.find(itor->first) == hm2.end()) {
                return false;
            } else if(hm2.at(itor->first) != itor->second) {
                return false;
            }
        }
        
        return true;
    }
};