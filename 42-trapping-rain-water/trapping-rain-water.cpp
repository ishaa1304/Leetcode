class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> maxL(n), maxR(n), water(n);

        maxL[0]=arr[0];
        for(int i=1;i<n;i++){
            maxL[i]= max(maxL[i-1],arr[i]);
        }
         maxR[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxR[i] = max(maxR[i + 1], arr[i]);
        }
        for(int i=0;i<n;i++){
            water[i]= min(maxL[i],maxR[i])-arr[i];

        }
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=water[i];
        }
        return sum;
     }
};
