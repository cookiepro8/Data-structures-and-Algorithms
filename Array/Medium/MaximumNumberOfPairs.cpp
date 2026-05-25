class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0, leftover = 0;
        vector<int> freq(101, 0);
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        for(int i = 0; i<freq.size(); i++){
            pairs += freq[i]/2;
            leftover += freq[i]%2;
        }

        return{pairs, leftover};
    }
};