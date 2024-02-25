class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;
        char s[10];
        int iter = 0;

        while (x >= 1)
        {
            s[iter] = '0' + (x % 10);
            x /= 10;
            iter++;
        }

        int j = iter - 1;

        for(int i = 0; i < iter / 2; i++)
        {
            if (s[i] != s[j])
                return false;
            j--;
        }
        return true;
    }
};