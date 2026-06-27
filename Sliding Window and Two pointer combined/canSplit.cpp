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

//Brute force (similar to finding equilibrium)
#include <vector>
#include <iostream>
using namespace std;

bool canSplit(vector<int> &arr)
{
    // Try every possible split position
    for (int i = 0; i < arr.size(); i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        // Compute left sum (0 to i)
        for (int j = 0; j <= i; j++)
            leftSum += arr[j];

        // Compute right sum (i+1 to n-1)
        for (int j = i + 1; j < arr.size(); j++)
            rightSum += arr[j];

        // Check condition
        if (leftSum == rightSum)
            return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5};

    cout << boolalpha << canSplit(arr) << endl;
    return 0;
}