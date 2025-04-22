class Solution {
public:
    bool check(vector<int>& arr) {
        int count = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                count++;
            }
        }
        if (arr[arr.size() - 1] >arr[0]) {
            count++;
        }
        return count <= 1;
    }
};


//brute forcr
// for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) {
//       if (arr[j] < arr[i])
//         return false;
//     }
//   }

//   return true;