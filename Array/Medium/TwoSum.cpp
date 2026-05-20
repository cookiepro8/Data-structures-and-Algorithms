#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class solution{
    public:
    //Brute force approach
        vector<int> twosum1(vector<int>& nums, int target){
            int n = nums.size();

            for(int i = 0; i<n-1; i++){
                for(int j = i+1; j<n; j++){
                    if(nums[i] + nums[j] == target){
                        return {i,j};
                    }
                }
            }
            return {};
        }

    //Appraoch 2: Better using unordered_map
    vector<int> twosum2(vector<int>& nums, int target){
        map<int, int> mpp;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(mpp.find(target-nums[i]) != mpp.find()){
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }

    //Optimal approach using two pointers

    vector<int> twosum3(vector<int>& nums, int target){
        vector<pair<int, int>> v;
        for(int i = 0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        int left = 0, right = nums.size()-1;
        while(left<right){
            int sum = v[left].first+v[right].first;
            if(sum == target){
                return {v[left].second, v[right].second};
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};

int main(){
    solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = sol.twosum3(nums, target);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}