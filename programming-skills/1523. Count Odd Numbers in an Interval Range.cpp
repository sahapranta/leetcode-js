class Solution {
public:
    int countOdds(int low, int high) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (low % 2 == 0 && high % 2 == 0) {
            return (high - low) / 2;
        }
        
        return ((high - low) / 2) + 1;
    }
};
