class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;

        while(n!=0) {
            int rem = n%10;
            prod *= rem;
            sum += rem;
            n /= 10;
        }
        return prod - sum;
    }
};
