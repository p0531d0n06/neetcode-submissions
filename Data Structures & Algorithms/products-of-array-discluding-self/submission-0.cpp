class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        int prefix[size];
        int suffix[size];

        int prefix_cum = 1;
        prefix[0] = 1;

        for(int i = 1; i < size; i++){
            prefix_cum *= nums[i-1];
            prefix[i] = prefix_cum;
        }

        int suffix_cum = 1;
        suffix[size - 1] = 1;

        for(int i = size - 2; i >= 0; i--){
            suffix_cum *= nums[i + 1];
            suffix[i] = suffix_cum;
        }

        vector<int> result = {};

        for(int i = 0; i < size; i++){
            result.push_back(prefix[i] * suffix[i]);
        }

        return result;
    }
};
