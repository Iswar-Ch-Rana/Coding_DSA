// 138. Copy List with Random Pointer

/*********** Approach 1  ***********/

// Time = O(n)
// Space = O(n)

class Solution
{
public:
    void getNode(Node *&head, Node *&tail, int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            return;
        }
    }
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        while (temp != NULL)
        {
            getNode(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Map oreginal linked list and copy linked list

        unordered_map<Node *, Node *> oldToNew;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;

        // add random pointers of the list
        while (originalNode != NULL)
        {
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

/*********** Approach 2  ***********/

// Time = O(n)
// Space = O(1)

class Solution
{
public:
    // Copy list funtion
    Node *copyRandomList(Node *head)
    {
        // Step 1: Clone the nodes and insert them in between the original nodes
        Node *curr = head;
        while (curr != NULL)
        {
            Node *cloneNode = new Node(curr->val);
            cloneNode->next = curr->next;
            curr->next = cloneNode;
            curr = cloneNode->next;
        }

        // Step 2: Copy the random pointers
        curr = head;
        while (curr != NULL)
        {
            if (curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and cloned lists
        Node *clonedHead = head != NULL ? head->next : NULL;
        Node *cloneCurr = clonedHead;
        curr = head;
        while (curr != NULL)
        {
            curr->next = curr->next->next;
            if (cloneCurr->next != NULL)
            {
                cloneCurr->next = cloneCurr->next->next;
            }
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return clonedHead;
    }
};
