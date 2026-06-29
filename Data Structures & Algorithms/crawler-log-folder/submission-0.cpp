class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (string op : logs) {
            if (op == "./") {
                continue; // stay in current folder
            } 
            else if (op == "../") {
                if (!st.empty()) st.pop(); // go up one folder
            } 
            else {
                st.push(op); // move into child folder
            }
        }

        return st.size(); // remaining depth = ops needed to go back to main folder
    }
};
