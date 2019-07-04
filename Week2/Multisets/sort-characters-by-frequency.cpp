class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> uMap;
        for(char a: s) uMap[a]++;
        
        multimap<int, char, greater<int>> mMap;
        for(auto it: uMap) mMap.insert(pair<int, char> (it.second, it.first));
        
        string str;
        for(auto it: mMap) {
            int iterations = it.first;
            while(iterations > 0) {
                str += it.second;
                --iterations;
            }
        }
        return str;
    }
};

