class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // similar code as before but more efficient
        if(candies.size() <= 2) return 1;
        
        unordered_set <int> uSet;
        
        for(int i: candies) uSet.insert(i);
        
        return min(uSet.size(), candies.size() / 2);
        
        /*
        // Code works and passes test, but map was not needed.
        if(candies.size() <= 2) return 1;
        
        unordered_map <int, int> uMap;
        
        for(int i: candies) {
            if(uMap.find(i) == uMap.end()) {
                uMap[i] = 1;
            } else {
                uMap[i] = uMap.at(i) + 1;
            }
        }
        
        int vecSize = candies.size();
        int mapSize = uMap.size();
        if((vecSize / 2) <= mapSize) return (vecSize / 2);
        return mapSize;
        */
    }
};
