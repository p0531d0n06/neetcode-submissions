class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(auto i{16}; i-- > 0;){
            if(((n >> i) & 1) != ((n >> (31-i)) & 1)){
                if((n >> i) & 1){
                    n -= 1 << i;
                    n += 1 << (31-i);
                } else {
                    n += 1 << i;
                    n -= 1 << (31-i);
                }
            }
        }

        return n;
    }
};
