class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;   // Stores indices

        for (int i = n - 1; i >= 0; i--) {

            // Remove all temperatures that are not warmer
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If there is a warmer temperature
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Push current index
            st.push(i);
        }

        return ans;
    }
};