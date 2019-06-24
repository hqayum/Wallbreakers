class Solution {
public:
    int binaryGap(int N) {
        // if power of 2, then there
        // aren't two consecutive 1's
        if((N & (N-1)) == 0) return 0;
        
        int max = 0, count = 0, bit;
        bool firstOne = false;
        while(N != 0) {
            bit = (N & 1);
            if(bit == 1) {
                firstOne = true;
                if(max < count) max = count;
                count = 1;
            } else if(firstOne) {
                count++;
            }
            N >>= 1;
        }
        if(max < count) max = count;
        return max;
    }
};
