class Solution {
public:
    int findMin(vector<int>& arr) {
        //brute force approach is using linear search
        //optimal is using binary search

        int n = arr.size();
        int ans = INT_MAX;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        ans = min(ans, arr[mid]);
        if (arr[low] <= arr[mid]) {
                // Left half is sorted, so the minimum must be in the right half.
                low = mid + 1;
            } else {
                // Right half is sorted, so the minimum must be in the left half.
                high = mid - 1;
            }
        }
            

        
        // If both the left and right halves of an index are sorted, it implies that the entire search space between the low and high indices is also sorted.
        // In this case, there is no need to conduct a binary search within that segment to determine the minimum value. 
        // Instead, we can simply select the leftmost element as the minimum.


        return ans;


        
    }
};