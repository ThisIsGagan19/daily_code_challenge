# CODE

class Solution:
    def armstrongNumber (self, n):
        return 'true' if n == sum(int(digit) ** 3 for digit in str(n)) else 'false'