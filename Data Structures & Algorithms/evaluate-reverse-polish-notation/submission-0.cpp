
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];

            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int t1 = stk.top();
                stk.pop();

                int t2 = stk.top();
                stk.pop();

                int ans;

                if (s == "+") {
                    ans = t2 + t1;
                }
                else if (s == "-") {
                    ans = t2 - t1;
                }
                else if (s == "*") {
                    ans = t2 * t1;
                }
                else {
                    ans = t2 / t1;
                }

                stk.push(ans);
            }
            else {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};
