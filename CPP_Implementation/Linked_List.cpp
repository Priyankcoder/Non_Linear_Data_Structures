#include <iostream>
using namespace std;
struct node{
  int data;
  node* next;
};

class linked_list
{ 
  private:
  node *head, *tail;
  public:
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }

  void add(int v)
  {
    node *temp = new(node);
    temp -> data = v;
    temp -> next = NULL;

    if (head == NULL)
    {
      head = temp;
      tail = temp;
    }
    
    else
    {
      tail -> next = temp;
      tail = tail -> next;
    }
  }
  void show()
  {
    if (head == NULL)
      cout<<"Nothing to show";
    else
    {
      node *t = head;
      while (t != NULL)
       {
        cout<<t -> data<<"\n";
        t = t -> next;
       }

    }
  }
  

};

int main()
{
    linked_list a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(9);
    a.show();
    linked_list b;
    b.add(1);
    b.add(2);
    b.add(3);
    b.add(9);
    b.show();
    return 0;
}
