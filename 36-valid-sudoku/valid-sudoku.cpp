class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9],cols[9],boxes[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c=='.')continue;
                int boxind = (i/3)*3 +j/3;
                // Each sub-box is a 3×3 square.
                // (i/3) gives which "row-block" (0,1,2).
                // (j/3) gives which "col-block" (0,1,2).
                // Combine them to get a unique ID from 0 to 8.
                if(row[i].count(c) || cols[j].count(c) || boxes[boxind].count(c)) return false;
                row[i].insert(c);
                cols[j].insert(c);
                boxes[boxind].insert(c);
            }
        }
        return true;
    }
};