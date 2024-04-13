class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();

        int mx = 0;
        int mn = INT_MAX;
        double total = 0;

        for (int i = 0; i < n; i++) {
            int s = salary[i];

            if (s > mx) {
                mx = s;
            }

            if (s < mn) {
                mn = s;
            }

            total += s;
        }

        return (total - mx - mn) / (n - 2);
    }
};
