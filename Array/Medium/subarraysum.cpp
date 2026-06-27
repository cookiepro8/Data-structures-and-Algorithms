class Solution {
	public:
	vector<int> subarraySum(vector<int> &arr, int target) {
		// code here
		int sum = 0;
		int j = 0;
		int n = arr.size();
		
		for (int i = 0; i<n; i++) {
			sum += arr[i];
			while (sum > target && j<i) {
				sum -= arr[j];
				j++;
			}
			
			if (sum == target) {
				return {j+1, i+1};
			}
		}
		return {-1};
	}
	
};
