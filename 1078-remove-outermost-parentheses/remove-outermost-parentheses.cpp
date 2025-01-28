class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(int i =0;i<s.size();i++){
            if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    ans +=s[i];

                }
            }else{
                if(!st.empty()){
                    ans +=s[i];
                }
                st.push(s[i]);
            }
        }
        return ans;
    }
};