class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
    //brute force
    // //traverse the matrix:
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (matrix[i][j] == target)
    //             return true;
    //     }
    // }
    // return false;

    //binary search

    //approach
    // converting 2d in 2d we have mid 
    // but mid in 2d terms will be row and column so how do we convert it back into row and col 
    // so using 
//     Row number = index ÷ columns
// (row = mid / m)
// Because every m elements we move to the next row.

// Column number = index % columns
// (col = mid % m)
// Because remainder tells us the position inside the row.
        

        int left=0;
        int right = n*m-1;
        while(left<=right){
            int mid =  left+(right-left)/2;
            int row = mid/m;
            int col = mid%m;
            int val = matrix[row][col];
            if(val == target){
                return true;
            }else if(val<target){
                left  = mid+1;

            }else{
                right= mid-1;
            }
        }
        return false;
        
    }
};