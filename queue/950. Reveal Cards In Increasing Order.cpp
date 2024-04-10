class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        queue<int> que;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            que.push(i);
        }

        sort(deck.begin(), deck.end());

        for (int i = 0; i < n; i++) {
            result[que.front()] = deck[i];
            que.pop();

            if (!que.empty()) {
                que.push(que.front());
                que.pop();
            }
        }

        return result;
    }
};
