class Solution {
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto it : mpp) {
            v.push_back(it);
        }

        sort(v.begin(), v.end(), compare);

        vector<int> ans;
        // for(int i = 0; i<k; i++){
        //     ans.push_back(v[i].first);
        // }

        while (k--) {
            ans.push_back(v[k].first);
        }
        return ans;
    }
};