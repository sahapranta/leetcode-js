class Solution {
public:
    vector<int> getNSR(vector<int>& height, int n) {
        stack<int> st;

        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                right[i] = n;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    right[i] = n;
                } else {
                    right[i] = st.top();
                }
            }

            st.push(i);
        }

        return right;
    }

    vector<int> getNSL(vector<int>& height, int n) {
        stack<int> st;

        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                right[i] = -1;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    right[i] = -1;
                } else {
                    right[i] = st.top();
                }
            }

            st.push(i);
        }

        return right;
    }

    int findMaxArea(vector<int>& height, int n) {
        vector<int> NSR = getNSR(height, n);
        vector<int> NSL = getNSL(height, n);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            int a = width * height[i];

            maxArea = max(maxArea, a);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n);

        for (int i = 0; i < n; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(height, n);

        for (int r = 1; r < m; r++) {
            for (int col = 0; col < n; col++) {
                if (matrix[r][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }

            maxArea = max(maxArea, findMaxArea(height, n));
        }

        return maxArea;
    }
};
