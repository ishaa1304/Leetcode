class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Remove remaining digits from the end if k is still greater than 0
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Build the answer from the stack
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i); // Skip leading zeros

        return ans.empty() ? "0" : ans;
    }
};
