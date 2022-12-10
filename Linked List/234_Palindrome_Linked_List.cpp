#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void appendNode(ListNode *&list, int value)
{
    ListNode *newNode = new ListNode;
    newNode->val = value;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        ListNode *tNode = list;
        while (tNode->next != NULL)
        {
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
}

void displayList(ListNode *list)
{
    ListNode *tNode = list;
    while (tNode != NULL)
    {
        cout << tNode->val << "->";
        tNode = tNode->next;
    }
    cout << "NULL" << endl;
}

void reverseAList(ListNode *pNode, ListNode *tNode, ListNode *&head)
{

    if (tNode == NULL)
        return;

    if (tNode->next == NULL)
    {
        head = tNode;
    }

    pNode = tNode;
    tNode = tNode->next;

    reverseAList(pNode, tNode, head);

    if (tNode != NULL)
    {
        // cout << tNode->val << " ";
        tNode->next = pNode;
        pNode->next = NULL;
    }
}

ListNode *reverseList(ListNode *head)
{
    ListNode *pNode = NULL;
    ListNode *tNode = head;

    reverseAList(pNode, tNode, head);

    return head;
}

// using two pointer approach
ListNode *getMiddleOfTheList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;

        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    // so, slow is the middle element
    slow = slow->next;
    return slow;
}

bool isPalindrome(ListNode *head)
{
    // mHead -> points to the middle of the list
    ListNode *mHead = getMiddleOfTheList(head);
    // now, reverse this list
    ListNode *rList = reverseList(mHead);

    while (head != NULL && rList != NULL)
    {

        if (head->val != rList->val)
            return false;

        head = head->next;
        rList = rList->next;
    }
    // if (head != NULL || rList != NULL)
    //     return false;

    return true;
}
int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 2);
    appendNode(l1, 1);

    // displayList(l1);

    if (isPalindrome(l1))
    {
        cout << "Yes! This list is Palindrome!" << endl;
    }
    else
    {
        cout << "Opps! This list is not Palindrome" << endl;
    }

    return 0;
}