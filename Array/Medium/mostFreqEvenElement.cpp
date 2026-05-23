class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> mpp;
    int hasEvenele = -1;
    for(int i =0 ; i<nums.size(); i++){
        if(nums[i]%2 == 0){
            mpp[nums[i]]++;
            int hasEvenele = 1;
        }
    }
    if(hasEvenele == 1) return -1; 
    int smallestHighestFreq = -1, prevfreq = -1;
    for(auto it: mpp){
        if(it.second > prevfreq){
            prevfreq = it.second;
            smallestHighestFreq = it.first;
        }
        else if(it.second == prevfreq){
            smallestHighestFreq = min(smallestHighestFreq, it.first);
        }

    }
    return smallestHighestFreq;
    }
};