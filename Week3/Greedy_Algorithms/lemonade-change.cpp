class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size() <= 0) return true;
        if(bills[0] > 5) return false;
        
        // array that holds number of 5's and 10's
        int change[] = {0, 0};
        
        for(int i = 0; i < bills.size(); ++i) {
            if(bills[i] == 5) {
                change[0] += 1;
            } else if(bills[i] == 10) {
                if(change[0] <= 0) return false;
                change[0] -= 1;
                change[1] += 1;
            } else {
                if(change[1] <= 0) {
                    if(change[0] < 3) return false;
                    change[0] -= 3;
                } else {
                    if(change[0] < 1) return false;
                    change[0] -= 1;
                    change[1] -= 1;
                }
            }
        }
        return true;
    }
};
