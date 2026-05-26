class Solution {
public:
    //Index mapping or tag sorting
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> idx(names.size());
        for(int i = 0; i<names.size(); i++){
            idx[i] = i;
        }
        
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return heights[i] > heights[j];
        });

        vector<string> ans(names.size());
        for(int i = 0; i<names.size(); i++){
            ans[i] = names[idx[i]];
        }
        return ans;
    }
};