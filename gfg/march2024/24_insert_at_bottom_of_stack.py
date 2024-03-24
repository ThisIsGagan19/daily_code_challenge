# CODE

class Solution:
    def insertAtBottom(self, st, x):
        
        # Cheating
        # st.insert(0, x)
        # return st
        
        def solve(st, x):
            if len(st) == 0:
                st.append(x)
                return 
            val = st[-1]
            st.pop()
            solve(st, x)
            st.append(val)
        solve(st, x)
        return st