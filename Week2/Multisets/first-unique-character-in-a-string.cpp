class Solution {
public:
    int firstUniqChar(string s) {
        // Using a vector to count, this 
        // method is extremely faster then
        // using either the unordered_map or
        // multiset methods, even though 
        // all 3 methods work.
        vector <int> count(26, 0);
        for(char a: s) ++count[a - 'a'];
        for(int i = 0; i < s.size(); ++i) {
            if(count[s[i] - 'a'] == 1) return i;
        }
        return -1;
        /*
        // similar code as the multiset but much quicker
        // since I am using an unordered_map
        unordered_map <char, int> uMap;
        for(char a: s) {
            if(uMap.find(a) == uMap.end()) {
                uMap[a] = 1;
            } else {
                uMap[a]++;
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(uMap.at(s[i]) == 1) {
                return i;
            }
        }
        return -1;
        */
        /*
        // Code below works using multiset but it's very slow.
        // Time limit gets excedded if I don't do mSet.erase()
        multiset <char> mSet;
        for(char a: s) mSet.insert(a);
        for(int i = 0; i < s.size(); ++i) {
            if(mSet.count(s[i]) == 1) {
                return i;
            } else {
                mSet.erase(s[i]);
            }
        }
        return -1;
        */
    }
};

