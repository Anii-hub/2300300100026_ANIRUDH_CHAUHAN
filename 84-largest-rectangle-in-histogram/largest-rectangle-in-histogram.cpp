class Solution {
public:

    class Pair {
    public:
        int key;
        int val;
        Pair(int k, int v) {
            key = k;
            val = v;
        }
    };

    vector<int> NSL_Solve(vector<int>& arr) {
        stack<Pair> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            if(st.empty()) {
                ans[i] = -1;
            }
            else if(!st.empty() && st.top().val < arr[i]) {
                ans[i] = st.top().key;
            }
            else if(!st.empty() && st.top().val >= arr[i]) {

                while(!st.empty() && st.top().val >= arr[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    ans[i] = -1;
                }
                else {
                    ans[i] = st.top().key;
                }
            }

            st.push(Pair(i, arr[i]));
        }

        return ans;
    }

    vector<int> NSR_Solve(vector<int>& arr) {
        stack<Pair> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            if(st.empty()) {
                ans[i] = n;
            }
            else if(!st.empty() && st.top().val < arr[i]) {
                ans[i] = st.top().key;
            }
            else if(!st.empty() && st.top().val >= arr[i]) {

                while(!st.empty() && st.top().val >= arr[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    ans[i] = n;
                }
                else {
                    ans[i] = st.top().key;
                }
            }

            st.push(Pair(i, arr[i]));
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL = NSL_Solve(heights);
        vector<int> NSR = NSR_Solve(heights);

        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, (NSR[i] - NSL[i] - 1) * heights[i]);
        }

        return maxArea;
    }
};