# CODE

from typing import List
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split()
        dict_set = set(dictionary)
        for i in range(len(words)):
            words[i] = self.find_root(words[i], dict_set)
        return " ".join(words)
    
    def find_root(self, word, dict_set):
        for i in range(len(word)):
            root = word[0 : i]
            if root in dict_set:
                return root
        return word