class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0;
        int tens = 0;

        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                tens++;
                fives--;
            } else if (bills[i] == 20) {
                if (tens > 0) {
                    tens--;
                } else {
                    fives -= 2;
                }
                fives--;
            }

            if (fives < 0) {
                return false;
            }
        }

        return fives >= 0;
    }
};
