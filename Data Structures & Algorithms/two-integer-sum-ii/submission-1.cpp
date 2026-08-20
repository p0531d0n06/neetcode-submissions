class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        result.push_back(1);
        result.push_back(numbers.size());

        while(numbers[result[0]-1] + numbers[result[1]-1] != target){
            if(numbers[result[0]-1] + numbers[result[1]-1] > target){
                result[1]--;
            } else {
                result[0]++;
            }
        }

        return result;
    }
};
