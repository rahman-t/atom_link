#include<bits/stdc++.h>
using namespace std;

struct LinkedList
{
  int val;
  LinkedList* next;
};

void pushNode(LinkedList** head_ptr, int n)
{
  LinkedList* new_node = new LinkedList();
  new_node->val = n;
  new_node->next = *head_ptr;
  (*head_ptr) = new_node;
}
/*when specified to use One-pass, it's necessary to have two pointers. One fast and the other slow...https://helloacm.com/how-to-remove-nth-node-from-end-of-list-in-cc/
 */
LinkedList* delNthNode(LinkedList* h, int k)
{
  LinkedList* fast = h, *slow = h;
  
  while (fast != NULL)
    {
      fast = fast->next;

      if (k-- < 0) 
	{
	  slow = slow->next;
	}
    }
  if (k == 0) h = h->next;
  else slow->next = slow->next->next;
  return h;
}

void printList(LinkedList* l)
{
  while (l != NULL)
    {
      cout << l->val << " ";
      l = l->next;
    }
  cout << endl;
}

int main() 
{
  LinkedList* head = NULL;
  
  pushNode(&head, 5);
  pushNode(&head, 4);
  pushNode(&head, 3);
  pushNode(&head, 2);
  pushNode(&head, 1);

  cout << "Linked list created..." << endl;
  printList(head);

  LinkedList* res = delNthNode(head, 2);
  printList(head);
  return 0;
}
