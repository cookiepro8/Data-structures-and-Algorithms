/*
Ex: nums = [1, 2, 3]
subsets = [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]; (1 << 3) number of subsets

Approach:
We are trying out for each and every combination, check for the set bit and then include it in the subset array
Finally add all the subsets in the result array.

0   0   0
0   0   1
0   1   0
0   1   1
1   0   0
1   0   1
1   1   0
1   1   1
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int subsets = 1 << nums.size();  //i.e if n=3, then 1<<3 means 8 subsets for 3 numbers

        for(int num = 0; num < subsets; num++){
            vector<int> sub;
            for(int i = 0; i<nums.size(); i++){
                if(num & (1<<i)) sub.push_back(nums[i]);
            }
            result.push_back(sub);
        }
        return result;
    }
};