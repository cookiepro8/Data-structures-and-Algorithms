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

    //Boyer-Moore voting algorithm
    vector<int> majorityElement2(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }

            else if (nums[i] == ele1){
                cnt1++;
            }else if (nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int threshold = nums.size()/3;
        vector<int> ans;
         cnt1 = 0, cnt2 = 0; //resetting values to 0
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }

        if(cnt1 > threshold) ans.push_back(ele1);
        if(cnt2 > threshold) ans.push_back(ele2);

        return ans;
        
    }

};