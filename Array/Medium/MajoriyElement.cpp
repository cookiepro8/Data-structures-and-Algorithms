//[2,2,1,1,1,2,2]

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int ele;
            for(int i = 0; i<n; i++){
            if (cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
                if (nums[i] == ele)
                    cnt++;
                else
                    cnt--;
            }
            }

            int cnt1 = 0;
            for(int i =0; i<n; i++){
            if (nums[i] == ele)
                cnt1++;
            }
            if(cnt1 > n/2) return ele;
            else return -1;

            return ele;
    }
};

int main()
{
    solution sol;
    vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
    int res = sol.majorityElement(nums);
    cout << res;
    return 0;
}