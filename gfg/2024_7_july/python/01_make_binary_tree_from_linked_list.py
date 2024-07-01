# CODE

class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def convert(head):
    nodes = [] # for storing tree nodes
    while head:
        nodes.append(Tree(head.data))
        head = head.next
    n = len(nodes)
    for i, node in enumerate(nodes):
        if 2 * i + 1 < n:
            nodes[i].left = nodes[2 * i + 1]
        if 2 * i + 2 < n:
            nodes[i].right = nodes[2 * i + 2]
    return nodes[0]