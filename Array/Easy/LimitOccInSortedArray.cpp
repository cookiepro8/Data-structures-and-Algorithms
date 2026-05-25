//3940.

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int idx = 0;
        for(int n: nums){
            if(idx < k || n > nums[idx-k]){
                nums[idx] = n;
                idx++;
            }
        }
        nums.resize(idx);
        return nums;
    }
};