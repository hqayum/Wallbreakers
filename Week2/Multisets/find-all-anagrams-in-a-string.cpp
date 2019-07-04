class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        if(p.size() == s.size()) {
            if(p.compare(s) == 0) return {0};
            return {};
        }
        
        unordered_map <char, int> pMap;
        unordered_map <char, int> sMap;
        vector <int> vec;
        
        for(int i = 0; i < p.size(); ++i) {
            if(pMap.find(p[i]) == pMap.end()){
                pMap[p[i]] = 1;
            } else {
                pMap[p[i]]++;
            }
            if(sMap.find(s[i]) == sMap.end()){
                sMap[s[i]] = 1;
            } else {
                sMap[s[i]]++;
            }
        }
        
        if(sMap == pMap) vec.push_back(0);
        int j = 0;
        for(int i = p.size(); i < s.size(); ++i) {
            if(sMap.at(s[j]) > 1) {
                sMap[s[j++]]--;
            } else {
                sMap.erase(s[j++]);
            }
            if(sMap.find(s[i]) == sMap.end()) {
                sMap[s[i]] = 1;
            } else {
                sMap[s[i]]++;
            }
            if(sMap == pMap) vec.push_back((i - p.size() + 1));
        }
        return vec;
        
        /*
        // below code works but won't pass all tests
        // because time limit exceded. I know the code 
        // works, and I believe the reason for the 
        // time limit is because it takes a long
        // time to insert and erase an element in 
        // a multiset. If the multiset was unordered
        // it would be much quicker. I used sliding
        // window method but multiset is sorted and
        // its operations slow it down too much.
        if(p.size() > s.size()) return {};
        if(p.size() == s.size()) {
            if(p.compare(s) == 0) return {0};
            return {};
        }
        
        multiset <char> pSet;
        multiset <char> sSet;
        vector <int> vec;
        
        for(int i = 0; i < p.size(); ++i) {
            pSet.insert(p[i]);
            sSet.insert(s[i]);
        }
        
        if(sSet == pSet) vec.push_back(0);
        int j = 0;
        for(int i = p.size(); i < s.size(); ++i) {
            sSet.erase(sSet.lower_bound(s[j++]));
            sSet.insert(s[i]);
            if(sSet == pSet) vec.push_back((i - p.size() + 1));
        }
        return vec;
        */
    }
};

