class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set <char> uSet;
        for(char a: J) {
            //cout << a << endl;
            uSet.insert(a);
        }
        int total = 0;
        for(char a: S) {
            if(uSet.find(a) != uSet.end()) ++total;
        }
        
        return total;
    }
};
