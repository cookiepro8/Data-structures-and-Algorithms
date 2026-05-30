// [2, 3, 5, -2, 7, -4] 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
    //Brute force
    int maximumSubarrayWithSum(vector<int> &nums){
        int n = nums.size();
        int maxi = INT_MIN;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                for(int k = i; k<=j; k++){
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return sum;
    }
    //Better solution
    int maximumSubarrayWithSum2(vector<int> &nums){
        int maxi = LONG_MIN;
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
            }
        }
        maxi = max(maxi, sum);
        return maxi;
    }

    int KadanesAlgorithm(vector<int> &nums){
        int n = nums.size()
        long long sum = 0;
        long long maxi = LLONG_MIN;
        int start = -1;
        int ansStart = -1, ansEnd = -1;

        for(int i = 0; i<n; i++){
            if(sum == 0)  start = i;
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
                 ansStart = start;
                 ansEnd = i;
            }
        }

        if(sum < 0) sum =0;

        // for(int i = ansStart; i< ansEnd; i++){
        //     //To print the Subarray
        //     cout << nums[i] << " ";
        // }

        return maxi;
    }
};
int main(){
    solution sol;
    vector<int> nums = {2, 3, 5, -2, 7, -4};
    int res = sol.KadanesAlgorithm(nums);
    cout << res << endl;
    return 0;
}