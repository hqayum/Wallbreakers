class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> reArr;
        for(int i = left; i <= right; i++) {
            if(i < 10) {
                reArr.push_back(i);
                continue;
            }
            int temp = i;
            while(temp > 0) {
                int digit = temp % 10;
                if(digit == 0 || i % digit != 0) {
                    //cout << i << endl;
                    break;
                }
                temp /= 10;
            }
            if(temp == 0) reArr.push_back(i);
        }
        return reArr;
    }
};
