class Solution {
public:
    vector<int> getTokens(string version) {
        stringstream ss(version);
        string token = "";

        vector<int> tokens;

        while (getline(ss, token, '.')) {
            tokens.push_back(stoi(token));
        }

        return tokens;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = getTokens(version1);
        vector<int> v2 = getTokens(version2);

        int m = v1.size();
        int n = v2.size();
        int i = 0;

        while (i < m || i < n) {
            int a = i < m ? v1[i] : 0;
            int b = i < n ? v2[i] : 0;

            if (a < b) {
                return -1;
            } else if (a > b) {
                return 1;
            } else {
                i++;
            }
        }

        return 0;
    }
};
