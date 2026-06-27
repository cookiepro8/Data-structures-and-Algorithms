class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int total = 0, lsum = 0;
        
        
        for(auto it: arr){
            total += it;
        }
        
        for(int i = 0; i<n; i++){
            lsum += arr[i];
            
            int rsum = total - lsum;
            
            if(lsum == rsum){
                return true;
            }
        }
        return false;
    }
};
