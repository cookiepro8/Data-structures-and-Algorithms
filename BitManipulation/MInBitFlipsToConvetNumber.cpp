class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int ans = start ^ goal; //number of flips needed to convert.

        //counting no. of set bits
        // for(int i =0; i<31; i++){
        //     if(ans & (1 << i)) cnt = cnt+1;
        // }

        while(ans >0){
            cnt += ans & 1;
            ans >>= 1;
        }
        return cnt;
    }
};