class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while(low<=high){
            long long mid = low+ (high-low)/2;
            long long children_cnt = 0;
            
            //check how many children can get candies for the given mid
            for(int &c: candies){
                children_cnt += c/mid;
            }

            if(children_cnt >= k){  
                ans = mid;
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        return ans;

    }
};