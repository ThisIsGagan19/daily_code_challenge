int countPairs(struct Node *head1, struct Node *head2, int x) {
    unordered_map<int, int> mp;
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    while (ptr1) {
        mp[ptr1->data]++;
        ptr1 = ptr1->next;
    }
    int cnt = 0;
    while (ptr2) {
        if (mp.find(x - ptr2->data) != mp.end())
            cnt++;
        ptr2 = ptr2->next;
    }
    return cnt;
}