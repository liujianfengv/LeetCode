class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while ((x / 10)) {
            int reminder = x % 10;
            result = result * 10 + reminder;
            x = x / 10;
        }
        if(((long)result * 10 + x)> 2147483647 || ((long)result * 10 + x) < -2147483648){
            return 0;
        } else {
            result = result * 10 + x;
            return result;
        }
    }
};