# CODE 1

from collections import Counter
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        n = len(words)
        res = []
        
        common = Counter(words[0])
        for i in range(1, n):
            current = Counter(words[i])
            for ch in common.keys():
                common[ch] = min(common[ch], current[ch])
        
        for ch, cnt in common.items():
            for _ in range(cnt):
                res.append(ch)
        
        return res

# IMPORTANT POINTS BEFORE CODE 2:
# 1. The bitwise AND operator (&) when used with Counter objects 
#    from the collections module performs an intersection operation. 
#    This means it finds the minimum count for each element that is present 
#    in both Counter objects.

# 2. How Bitwise AND Performs Intersection in Counters?
#    When you perform the bitwise AND operation between two Counter objects, 
#    Counter1 & Counter2, it creates a new Counter object that contains only 
#    the elements that are present in both Counter1 and Counter2, with each element's 
#    count being the minimum of its count in Counter1 and Counter2.

# 3. What Counter.elements() will do?
#    A. Repeats Each Element: Each element in the Counter is repeated according to its count.
#    B. Order: The order of elements is the same as the order they were first encountered in 
#              the input iterable used to create the Counter.

#     Example:

#     Code:
#     c = Counter({'apple': 3, 'banana': 2, 'orange': 1})
#     elements = c.elements()
#     print(list(elements))

#     Output:
#     ['apple', 'apple', 'apple', 'banana', 'banana', 'orange']

# CODE 2

from typing import List
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        common = Counter(words[0])
        for word in words:
            common &= Counter(word)
        return list(common.elements())