class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for(int i = 0; i < word.size(); i++) {
            int charVal = (int) word[i];
            if(charVal >= 65 && charVal <= 90) {
                capitalCount++;
            }
        }
        if(capitalCount == 0 || capitalCount == word.size()) {
            return true;
        } else if(capitalCount == 1 && word[0] >= 65 && word[0] <= 90) {
            return true;
        }
        return false;
    }
};
