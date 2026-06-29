class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;

        for (string op : ops) {
            if (op == "+") {
                int top1 = s.top(); s.pop();
                int top2 = s.top();
                int sum = top1 + top2;
                s.push(top1);  // restore top1
                s.push(sum);
            }
            else if (op == "C") {
                s.pop();
            }
            else if (op == "D") {
                int val = s.top();
                s.push(2 * val);
            }
            else {
                s.push(stoi(op));
            }
        }

        int total = 0;
        while (!s.empty()) {
            total += s.top();
            s.pop();
        }

        return total;
    }
};
