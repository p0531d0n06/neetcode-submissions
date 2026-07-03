class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int mid = (l + r) / 2;

        while(l < r){
            if(nums[mid] > nums[r]){
                l = mid + 1;
            } else {
                r = mid;
            }
            mid = (l + r) / 2;
        }

        int offset = mid;
        l = 0;
        r = nums.size() - 1;
        mid = (l + r) / 2;
        int n = nums.size();

        while(l < r){
            if(nums[(mid + offset) % n] < target){
                l = mid + 1;
            } else if (nums[(mid + offset) % n] > target) {
                r = mid;
            } else {
                return (mid + offset) % n;
            }
            mid = (l + r) / 2;
        }
        if(nums[(mid + offset) % n] < target){
            l = mid + 1;
        } else if (nums[(mid + offset) % n] > target) {
            r = mid;
        } else {
            return (mid + offset) % n;
        }

        return -1;
    }
};
