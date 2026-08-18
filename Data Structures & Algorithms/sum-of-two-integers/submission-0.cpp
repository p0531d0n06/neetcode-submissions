class Solution {
public:
    int getSum(int a, int b) {
        bool x;
        bool y;
        bool z = 0;
        int r = 0;
        for(int i{0uz}; i < 32; i++){
            x = (a >> i) & 1;
            y = (b >> i) & 1;
            r += ((x ^ y) ^ z) << i;
            z = (x & y) | (z & (x ^ y));
        }

        return r;
    }
};
