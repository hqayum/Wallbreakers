class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x == y) return 0;
        int xorVal = x ^ y, count = 0;
        while(xorVal != 0) {
            if((xorVal & 1) == 1) count++;
            xorVal /= 2;
        }
        return count;
        
        /*
        // my first solution
        if(x == y) return 0;
        
        int total = 0;
        if(x > y) {
            while(x != 0) {
                if((x & 1) != (y & 1)) {
                    ++total;
                }
                x /= 2;
                y /= 2;
            }
            return total;
        }
        while(y != 0) {
            if((x & 1) != (y & 1)) {
                ++total;
            }
            x /= 2;
            y /= 2;
        }
        return total;
        */
    }
};
