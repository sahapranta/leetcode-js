class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int arr[2] = {0};
        int n = students.size();

        for (int i = 0; i < n; i++) {
            arr[students[i]]++;
        }

        for (int i = 0; i < n; i++) {
            int s = sandwiches[i];

            if(arr[s] == 0){
                return n-i;
            }

            arr[s]--;
        }

        return 0;
    }
};
