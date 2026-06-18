//FInd XOR of numbers which appear twice

class Solution {
public:
//Early duplicate detection

    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> s;
        int xr = 0;

        for(auto &x: nums){
            if(s.count(x)){  //if already seen the number then xor it.
                xr ^= x;
            }
            s.insert(x);
        }
        return xr;
    }
};