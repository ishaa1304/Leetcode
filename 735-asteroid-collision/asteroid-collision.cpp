class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++){
            int siz=abs(asteroids[i]);
            while(!st.empty() && (st.top()>0 && asteroids[i]<0) && st.top()<siz){
                st.pop();
            }
            if(!st.empty() && (st.top()>0 && asteroids[i]<0) && st.top()==siz){
                st.pop();
            }
            else if (st.empty() || !(st.top()>0 and asteroids[i]<0)){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};