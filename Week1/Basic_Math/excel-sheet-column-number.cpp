class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() <= 0) {
            return 0;
        }
        
        int total = 0, power = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            int charVal = (int) (s[i] - '@');
            //cout << charVal << endl;
            total += (charVal * pow(26, power++));
        }
        return total;
    }
};
