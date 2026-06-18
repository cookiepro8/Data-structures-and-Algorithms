/*
Ex: [1, 2, 1, 2, 3, 5]
output: [3, 5] or [5, 3].

Approach:
1. xor all numbers
2. Unique numbers are also xorred, the result is obtained
3. check where they differ by using rightmost set bit (xor & (xor-1)) ^ xor
4. separate the integers into to different buckets, and xor the elements in the bucket
5. Unique elements are obtained.

*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xoR = 0;
        for(int i = 0; i<nums.size(); i++){
            xoR ^= nums[i];
        }

        int rightmost = (xoR & (xoR-1)) ^ xoR; //check where they differ based on the rightmost set bit.
        
        int xor1 = 0, xor2 = 0;

        for(int i = 0; i<nums.size(); i++){  //separate elements based on their difference
            if(nums[i] & rightmost){
                xor1 ^= nums[i];
            } else{
                xor2 ^= nums[i];
            }
        }

        return {xor1, xor2};
    }
};