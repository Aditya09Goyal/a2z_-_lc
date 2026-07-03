class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;
        for (auto s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                if (s == "+")
                    st.push(n1 + n2);
                else if (s == "-")
                    st.push(n1 - n2);
                else if (s == "*")
                    st.push(n1 * n2);
                else
                    st.push(n1 / n2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top(); 
    }
};