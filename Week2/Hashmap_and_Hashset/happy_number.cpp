class Solution {
public:
    bool isHappy(int n) {
        if(n <= 1) return 1;
        
        //unordered_map <int, int> uMap;
        //for(int i = 0; i <= 10; ++i) uMap[i] = i * i;
        
        unordered_set <int> uSet;
        int digit, total = 0;
        while(1) {
            while(n != 0) {
                digit = n % 10;
                n /= 10;
                total += (digit * digit);
            }
            if(total == 1) return true;
            if(uSet.find(total) == uSet.end()) {
                uSet.insert(total);
            } else {
                return false;
            }
            n = total;
            total = 0;
        }
    }
};
