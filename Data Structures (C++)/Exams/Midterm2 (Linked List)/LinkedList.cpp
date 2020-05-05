#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
	Node *previous;
	Node(int k, Node *n, Node *p){
		key = k;
		next = n;
		previous = p;
	}
};

class LinkedList{
	private:
		Node *head;
		Node *search(int value){
		 
		}


	public:

		LinkedList(){head = NULL;};
		
		void getName()
		   {
			cout<<"Dominic Bashford";
		   }

		void addNode(int value, int newVal)
		{
			Node *tmp = head;
			Node *x = new Node(newVal, NULL, NULL);
			if(head == NULL)
			{
				head = x;
			}
			else
			{
				bool found = false;
				while(found == false)
				{
					if(tmp -> next == NULL && tmp -> key != value)
					{
						tmp = head;
						x -> next = tmp;
						head = x;	
						found = true;
					}
					else if(tmp -> key == value)
					{
						if(tmp -> next == NULL)
						{
							tmp -> next = x;
							x -> previous = tmp;
							found = true;
						}
						else
						{
							x -> next = tmp -> next;
							tmp -> next -> previous = x;
							tmp -> next = x;
							x -> previous = tmp;
							found = true;
						}
					}
					else
					{
						tmp = tmp -> next;
					}
				}
			}	
		}
	
		
		
		
   Node *getHead()
      {
		return head;
      }


		void printList(){
			Node *x = head;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}
};
