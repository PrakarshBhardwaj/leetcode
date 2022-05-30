class Solution {
    public int divide(int dividend, int divisor) {
        int sign = (dividend<0)^(divisor<0) ? -1 : 1, quotient = 0;
        if(dividend == Integer.MIN_VALUE){
            if(divisor == -1) return Integer.MAX_VALUE;
            if(divisor == Integer.MIN_VALUE) return 1;
            dividend += Math.abs(divisor);
            quotient++;
        }
        if(divisor == Integer.MIN_VALUE) return 0;
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor); //Math.abs(-2147483648)=-2147483648
        while(dividend >= divisor){
            int tmp = divisor, count = 1;
            while(dividend - tmp >= tmp){ //(dividend >= tmp<<1 or >= 2*tmp) may cause overflows
                tmp <<= 1;
                count <<= 1;
            }
            dividend -= tmp;
            quotient += count;
        }
        return sign * quotient;
    }
}
