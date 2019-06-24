class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            int charValLeft = (int) s[i];
            int charValRight = (int) s[j];
            
            // uppercase
            if(charValLeft >= 65 && charValLeft <= 90) {
                // make lowercase
                s[i] = (char) (s[i] + 32);
            // lowercase or number
            } else if((charValLeft >= 97 && charValLeft <= 122) || (charValLeft >= 48 && charValLeft <= 57)) {
                // uppercase
                if(charValRight >= 65 && charValRight <= 90) {
                    // make lowercase
                    s[j] = (char) (s[j] + 32);
                // lowercase or number
                } else if((charValRight >= 97 && charValRight <= 122) || (charValRight >= 48 && charValRight <= 57)) {
                    if(s[i] == s[j]) {
                        ++i;
                        --j;
                    } else {
                        return false;
                    }
                } else {
                    --j;
                }
            } else {
                ++i;
            }
        }
        return true;
    }
};
