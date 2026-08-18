class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        int total;
        int x;
        for(auto i{0uz}; i++ < n+1;){
            total = 0;
            x = (i-1) & INT_MAX;
            for(auto j{32}; j-- > 0;){
                total += x % 2;
                x /= 2;
            }
            result.push_back(total);
        }

        return result;
    }
};
