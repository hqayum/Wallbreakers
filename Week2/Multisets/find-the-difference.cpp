class Solution {
public:
    char findTheDifference(string s, string t) {
        // Quickest way is bit mainip. Since one char is different/odd
        // and the rest are the same, we can use xor to find the
        // different/odd character out of the strings.
        int xorVal = 0;
        string temp = s + t;
        for(char a: temp) xorVal ^= a;
        return (char) xorVal;
        /*
        // hashmap solution is much faster then multiset
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for(char a: s) {
            if(sMap.find(a) == sMap.end()) {
                sMap[a] = 1;
            } else {
                sMap[a]++;
            }
        }
        for(char a: t) {
            if(tMap.find(a) == tMap.end()) {
                tMap[a] = 1;
            } else {
                tMap[a]++;
            }
        }
        for(int i = 0; i < t.size(); ++i) {
            if(sMap.find(t[i]) == sMap.end()) {
                return t[i];
            } else if(sMap.at(t[i]) != tMap.at(t[i])) {
                return t[i];
            }
        }
        return '0';
        */
        /*
        // multiset solution is slow, unordered_map is much quicker
        multiset<char> sSet;
        multiset<char> tSet;
        for(char a: s) {
            sSet.insert(a);
        }
        for(char a: t) {
            tSet.insert(a);
        }
        for(int i = 0; i < t.size(); ++i) {
            if(sSet.find(t[i]) == sSet.end()) {
                return t[i];
            } else if(sSet.count(t[i]) != tSet.count(t[i])) {
                return t[i];
            }
        }
        return '0';
        */
    }
};
