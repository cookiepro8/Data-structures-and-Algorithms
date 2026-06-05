#include <iostream>
using namespace std;

int countS(int ind, int arr[], int n, int s)
{
    if(ind == n){
        if(sum == s){
            return 1;
        } 
        else return 0;
    }

    s += arr[ind];

    int l = countS(ind + 1, arr, n, s);

    s -= arr[ind];

    int r = countS(ind + 1, arr, n, s);

    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    countS(0, arr, n, sum);
    return 0;
}