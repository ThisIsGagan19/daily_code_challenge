# INTUITION
# A path is eulerian path if every vertex has even degree

# CODE

class Solution:
	def isEularCircuitExist(self, v, adj):
	    return all([len(nbr) & 1 == 0 for nbr in adj])