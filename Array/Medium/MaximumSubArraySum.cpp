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
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
            }
        }
        return max(maxi, sum);
    }

    int KadanesAlgorithm(vector<int> &nums){
        int n = nums.size()
        long long sum = 0, maxi = LLONG_MIN;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }
        }

        if(sum < 0) sum =0;

        return maxi;
    }
};
int main(){
    
    return 0;
}