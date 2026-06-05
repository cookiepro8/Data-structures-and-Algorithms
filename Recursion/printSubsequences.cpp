#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it: ds){
            cout << it << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout << endl;
        
        return;
    }

    ds.push_back(arr[ind]); //take or pick particular ele in the subsequence
    printF(ind+1, ds, arr, n);
    ds.pop_back();
    printF(ind+1, ds, arr, n);  //remove from subsequence (not pick condn)
}

int main(){
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printF(0, ds, arr, n);
    return 0;
}