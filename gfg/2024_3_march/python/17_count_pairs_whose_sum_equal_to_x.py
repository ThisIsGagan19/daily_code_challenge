class Solution:
    def countPair(self, head1, head2, n1, n2, x):
        count, set_values = 0, set()

        # Add values from the second linked list to a set
        while head2:
            set_values.add(head2.data)
            head2 = head2.next

        # Check for pairs in the first linked list that sum up to x
        while head1:
            count += int(x - head1.data in set_values)
            head1 = head1.next

        return count