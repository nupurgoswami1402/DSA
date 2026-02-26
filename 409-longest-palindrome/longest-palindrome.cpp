class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for (char c : s) {
            count[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (int i = 0; i < 128; i++) {
            if (count[i] % 2 == 0) {
                length += count[i];
            } else {
                length += count[i] - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;  
        }

        return length;
    }
};