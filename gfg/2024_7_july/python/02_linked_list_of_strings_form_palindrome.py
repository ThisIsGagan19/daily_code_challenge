# CODE

def compute(head):
    res = ""
    while head:
        res, head = res + head.data, head.next
    return res == res[::-1]