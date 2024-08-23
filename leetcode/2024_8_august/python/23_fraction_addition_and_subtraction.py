# CODE

from math import gcd
import re

class Solution:
    def fractionAddition(self, expression: str) -> str:
        numerator = 0
        denominator = 1
        integers = list(filter(None, re.split('/|(?=[-+])', expression)))
        print(integers)
        for i in range(0, len(integers), 2):
            curr_numerator = int(integers[i])
            curr_denominator = int(integers[i + 1])
            numerator = (numerator * curr_denominator + 
                         curr_numerator * denominator)
            denominator = denominator * curr_denominator
        GCD = gcd(numerator, denominator)
        numerator //= GCD
        denominator //= GCD
        return str(numerator) + '/' + str(denominator)