/* Merging K lists using priority queue. Source: leetcode
 */
#include<bits/stdc++.h>
using namespace std;

struct LinkedList
{
  int val;
  LinkedList* next;
};

void printNode(LinkedList *h)
{
  while (h != NULL)
    {
      cout << h->val << " ";
      h = h->next;
    }
  cout << endl;
}

LinkedList* newNode(int d)
{
  LinkedList *temp = new LinkedList;
  temp->val = d;
  temp->next = NULL;
  return temp;
}

LinkedList* mergeKlists(vector<LinkedList*>& l1)
{
  LinkedList* temp = new LinkedList();
  LinkedList* l2 = temp;
  priority_queue<pair<int, LinkedList*>> p;

  for (int i = 0; i < l1.size(); i++)
    {
      // Push elements in the linked list into the priority queue
      if (l1[i] != NULL) p.push({-(l1[i] -> val), l1[i]});
    }
  while (!p.empty())
    {
      auto j = p.top();
      p.pop();
      l2->next = j.second;
      l2 = l2->next;
      if (j.second->next)
	{
	  // Pop values out of the priority queue to place them into l2
	  p.push({-(j.second->next->val), j.second->next});
	}
    }
  return temp->next;
}

int main()
{
  
  return 0;
]
