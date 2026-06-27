class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        int q = queries.size();
        
        vector<int> pref(n+1, 0);
        vector<int> ans;
        
        for(int i = 1; i<=n; i++){
            pref[i] = pref[i-1] + arr[i-1];
        }
        
        for(int i = 0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            int sum = pref[r+1] - pref[l];
            
            ans.push_back(sum/(r-l+1));
        }
        return ans;
    }
};