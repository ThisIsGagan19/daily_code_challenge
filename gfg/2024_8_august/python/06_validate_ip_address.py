# CODE

class Solution:
    def isValid(self, input: str):
        segments = input.split('.')
        
        # size check
        if len(segments) != 4:
            return False
        
        for segment in segments:
            
            # numeric check
            if not segment.isdigit():
                return False
                
            byte_val = int(segment)
            
            # value and leading zeros check
            if (not (0 <= byte_val <= 255)) or (segment != str(byte_val)):
                return False
            
        return True