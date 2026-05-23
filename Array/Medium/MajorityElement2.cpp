//Implemented Boyer-Moore voting algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        int threshold = nums.size()/3;

        for(auto num: mpp){
            int ele = num.first;
            int count = num.second;

            if(num.second > threshold){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};