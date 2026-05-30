#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
        //Brute force
    bool ls(vector<int> &a, int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    int consecutiveLongestSequence1(vector<int> &a)
    {
        int longest = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            cnt = 1;
            while (ls(arr, x + 1) == true)
            {
                x = x + 1;
                cnt = cnt + 1;
            }
        }
        longest = max(longest, cnt);
        return longest;
    }
    //Better solution by sorting
    int consecutiveLongestSequence2(vector<int> &nums)
    {
        int cnt = 0;
        int last_smaller = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == last_smaller)
            {
                cnt++;
                last_smaller = nums[i];
            }
            if (nums[i] != last_smaller)
            {
                cnt = 1;
                last_smaller = nums[i];
            }
        }

        longest = max(longest, cnt);

        return longest;
    }

    // optimal solution
    //using set datastructure to store unique elements, and start from the beginning point

    int longestConsecutiveSequence(vector<int> &a)
    {

        int x = 0, cnt = 0;
        int n = a.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(a[i]);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
