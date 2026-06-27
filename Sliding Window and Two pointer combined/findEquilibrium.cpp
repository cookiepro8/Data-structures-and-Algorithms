class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        // code here
        // prefix sum and suffix sum
        int n = arr.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == suffix[i])
            {
                return i;
            }
        }
        return -1;
    }

    // optimized code
    // tc: O(n), sc: O(1)

    int equilibriumPoint(vector<int> &arr)
    {
        int prefSum = 0, total = 0;

        // Calculate the array sum
        for (int ele : arr)
        {
            total += ele;
        }

        // Iterate pivot over all the elements
        // of the array and till prefSum != suffSum
        for (int pivot = 0; pivot < arr.size(); pivot++)
        {
            int suffSum = total - prefSum - arr[pivot];
            if (prefSum == suffSum)
            {
                return pivot;
            }
            prefSum += arr[pivot];
        }

        return -1;
    }
};