class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevrow;
        for(int i=0;i<numRows;i++){
            vector<int> currentrow (i+1,1);
            for(int j=1;j<i;j++){
                currentrow[j] = prevrow[j-1] +prevrow[j];
            }
            result.push_back(currentrow);
            prevrow=currentrow;
        }
        return result;
    }
};