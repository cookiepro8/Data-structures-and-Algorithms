class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        createsubset(nums, 0, res, subset);
        return res;
    }

    void createsubset(vector<int> &nums, int index, vector<vector<int>> &res, vector<int> &subset){
            if(index == nums.size()){
                res.push_back(subset);
                return;
            }

            //pick
            subset.push_back(nums[index]);
            createsubset(nums, index+1, res, subset);
            subset.pop_back();

            while(index+1 < nums.size() && nums[index] == nums[index+1]){
                index++;
            }

            createsubset(nums, index+1, res, subset);

    }
};