
//BRUTE FORCE

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1 || numRows >= s.size()) 
//             return s;
//         vector<string> rows(numRows);
//         int currRow=0;
//         int step=1;// +1 means going down, -1 means going up
//         for(char c :s){
//             rows[currRow] +=c;
//             currRow +=step;
//             if(currRow ==0 || currRow == numRows-1){
//                 step=-step;
//             }
            
//         }
//         string result;
//         for(string &row:rows){
//             result.append(row);
//         }
//         return result;
//     }
// };

//OPTIMALLL


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) 
            return s;

        string result;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int r = 0; r < numRows; r++) {
            for (int i = 0; i + r < n; i += cycleLen) {
                // vertical down character
                result += s[i + r];

                // diagonal character (only for middle rows)
                if (r != 0 && r != numRows - 1 && i + cycleLen - r < n) {
                    result += s[i + cycleLen - r];
                }
            }
        }

        return result;
    }
};
