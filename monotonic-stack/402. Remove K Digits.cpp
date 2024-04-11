class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = num.length();
        string result = "";

        for (int i = 0; i < n; i++) {            
            while (result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }

            if (result.length() > 0 || num[i] != '0') {
                result.push_back(num[i]);
            }
        }

        while (result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }

        if (result == "") {
            return "0";
        }

        return result;
    }
};
