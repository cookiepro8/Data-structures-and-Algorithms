#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
    
    int partition(vector<int> &arr, int low , int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j){
            while(arr[i] <= pivot && i <= high-1){
                i++;
            }

            while(arr[j] > pivot && j >= low+1){
                j--;
            }

            swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void qs(vector<int> &arr, int low, int high){
        if(low < high){
            int pIndex = partition(arr, low, high);
            qs(arr, low, partition);
            qs(arr, partition+1, high);
        }
    }


};
int main(){
    
    return 0;
}