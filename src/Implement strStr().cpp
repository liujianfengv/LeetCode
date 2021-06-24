class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        auto res = haystack.find(needle);
        return res == string::npos ? -1 : res;
    }
};