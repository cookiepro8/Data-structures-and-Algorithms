#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
        //Brute force appraoch
        void sortZeroOneTwo(vector<int>& nums){
            int cnt0 = 0, cnt1 = 0, cnt2 = 0;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] == 0)
                cnt0++;
                else if(nums[i] == 1)
                cnt1++;
                else
                cnt2++;
            }
            
            // for(int i = 0; i<nums.size(); i++){ 
            //     if(cnt0>0){
            //         nums[i] = 0;
            //         cnt0--;
            //     }
            //     else if(cnt1>0){
            //         nums[i] = 1;
            //         cnt1--;
            //     }
            //     else{
            //         nums[i] = 2;
            //         cnt2--;
            //     }
            // }

            int index = 0;
            while(cnt0--){
                nums[index++] = 0;
            }
            while(cnt1--){
                nums[index++] = 1;
            }
            while(cnt2--){
                nums[index++] = 2;  
            }

        }

        //Optimal approach
        void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){
    solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortZeroOneTwo(nums);
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}