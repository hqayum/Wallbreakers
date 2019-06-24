class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int leftmostBit = 0;
        while(temp != 0) {
            temp /= 2;
            ++leftmostBit;
        }
        temp = (pow(2, leftmostBit) - 1);
        return num ^ temp;
    }
};
