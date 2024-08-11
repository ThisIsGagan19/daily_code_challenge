# CODE

class Solution:
    def JobScheduling(self, Jobs, n):
        Jobs.sort(key = lambda x: x.profit, reverse=True)
        
        slots = [False] * (n + 1)
        profit = 0
        cnt = 0
        
        for job in Jobs:
            deadline = job.deadline
            while deadline > 0:
                if not slots[deadline]:
                    slots[deadline] = True
                    cnt += 1
                    profit += job.profit
                    break
                deadline -= 1
                
        return cnt, profit