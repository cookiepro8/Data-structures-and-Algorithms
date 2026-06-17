class Solution {
private:
    double totalTime(vector<int>& dist, int speed) {
        double tt = 0;
        for(int i = 0; i<dist.size()-1; i++){
            tt += ceil((double)dist[i]/ speed);
        }
        tt += (double)dist.back()/speed;

        return tt;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            double tt = totalTime(dist, mid);

            if (tt <= hour) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};