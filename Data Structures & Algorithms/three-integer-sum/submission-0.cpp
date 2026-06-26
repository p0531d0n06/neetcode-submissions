class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> resultSet;  // deduplicates automatically
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= (int)nums.size() - 3; i++) {
            int target = -nums[i];
            map<int, int> store;

            for (int j = i + 1; j < nums.size(); j++) {  // fix: j not i
                int complement = target - nums[j];

                if (store.find(complement) != store.end()) {
                    vector<int> entry = {nums[i], complement, nums[j]};  // fix: values not indices
                    resultSet.insert(entry);  // fix: fresh entry each time
                } else {
                    store[nums[j]] = nums[j];  // fix: store value not index
                }
            }
        }

        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};