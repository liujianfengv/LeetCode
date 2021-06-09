class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        int right[26] = {};
        right['I' - 'A'] = 1;
        right['V' - 'A'] = 5;
        right['X' - 'A'] = 10;
        right['L' - 'A'] = 50;
        right['C' - 'A'] = 100;
        right['D' - 'A'] = 500;
        right['M' - 'A'] = 1000;
        int result = 0;
        for (int i = 0; i < (s.size() - 1); ++i) {
            if (right[s[i] - 'A'] < right[s[i + 1] - 'A']) {
                result -= right[s[i] - 'A'];
            } else {
                result += right[s[i] - 'A'];
            }
        }
        return result + right[s.back() - 'A'];
    }
};