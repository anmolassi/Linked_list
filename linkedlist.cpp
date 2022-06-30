#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next=NULL;
	Node(int data)
	{
		this->data=data;
	}
};
Node *takeinput()
{
	int n;
	cout<<"Enter the size of the linked list: ";
	cin>>n;
	Node *head=NULL;
	Node *tail=NULL;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		Node *newnode=new Node(a);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
			continue;
		}
		tail->next=newnode;
		tail=tail->next;
	}
	return head;
}
Node *inserthead(Node *head)
{
	int n;
	cout<<"Enter the data :";
	cin>>n;
	if(head==NULL)
	{
		Node *newnode=new Node(n);
		head=newnode;
		return head;
	}
	Node *newnode=new Node(n);
	newnode->next=head;
	head=newnode;
	return newnode;
}
void *insertend(Node *head)
{
	int n;
	cout<<"Enter the data : "<<endl;
	cin>>n;
	Node *newnode =new Node (n);
	Node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=newnode;
}
Node *insertmiddle(Node *head)
{
	cout<<"Enter the node after which you want to insert : "<<endl;
	int n;
	cin>>n;
	Node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			cout<<"Enter the element you want to insert :";
			int a;
			cin>>a;
			Node *newnode=new Node(a);
			Node *tempo=temp->next;
			temp->next=newnode;
			newnode->next=tempo;
			return head;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"ELEMENT NOT FOUND"<<endl<<endl;
	}
}
void *display(Node *head)
{
	Node *newnode=head;
	if(head==NULL)
	{
		cout<<"EMPTY"<<endl<<endl<<endl;
	}
	else
	{
		while(newnode!=NULL)
	    {
		    cout<<newnode->data<<endl;
		    newnode=newnode->next;
	    }
	}
}
Node *deletehead(Node *head)
{
	Node *temp=head;
	head=head->next;
	delete temp;
	return head;
}
Node * deleteend(Node *head)
{
	Node *temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	Node *del=temp->next;
	temp->next=NULL;
	delete del;
	return head;
}
Node *deleteNode(Node*head)
{
	Node *temp=head;
	if (head==NULL)
	{
		cout<<"LINKED LIST IS EMPTY"<<endl;
		return NULL;
	}
	else if(head->next==NULL)
	{
		return NULL;
	}
	cout<<"Enter the node you want to delete : ";
	int n;
	cin>>n;
	Node * del;
	while(temp!=NULL)
	{
		if(n==temp->next->data)
		{
			del=temp->next;
			break;
		}
	}
	temp->next=del->next;
	delete del;
	return head;
}
Node * search(Node *head)
{
	int n;
	cout<<"Enter the node you want to search : ";
	cin>>n;
	Node *temp =head;
	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			cout<<"NODE FOUND"<<endl;
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"NODE NOT FOUND"<<endl;
	}
}
Node *reverse(Node *prev,Node *curr,Node *newnode)
{
	if(newnode==NULL&&curr==NULL)
	{
		return prev;
	}
	curr->next=prev;
	prev=curr;
	curr=newnode;
	if(newnode!=NULL)
	newnode=newnode->next;
	reverse(prev,curr,newnode);
}
int main()
{
	Node *head=NULL;
	char opt='y';
	do
	{
		cout<<"-------------MENU-------------"<<endl;
	    cout<<"0. Create a node\n";
	    cout<<"1. Insert at the head\n";
	    cout<<"2. Insert at the tail\n";
	    cout<<"3. Insert in between\n";
	    cout<<"4. Delete from the beginning\n";
	    cout<<"5. Delete from the end\n";
	    cout<<"6. Deletion of a specific node\n";
	    cout<<"7. Search for a node\n";
	    cout<<"8. Display all the node values."<<endl;
		cout<<"9. Reverse the linked list"<<endl;
	    cout<<"------------------------------"<<endl;
	    cout<<endl<<endl;
		cout<<"Enter the choice:";
	    int a;
	    cin>>a;
	    switch(a)
	    {
	    	case 0: 
	    	{
	    		head=takeinput();
	    		break;
			}
			case 1:
			{
				head=inserthead(head);
				break;
			}
			case 2:
			{
				insertend(head);	
				break;	
			}
			case 3:
			{
				insertmiddle(head);
				break;
			}
			case 4:
			{
				head=deletehead(head);
				break;
			}
			case 5:
			{
				head=deleteend(head);
				break;
			}
			case 6:
			{
				head=deleteNode(head);
				break;	
			}
			case 7:
			{
				search(head);
				break;
			}
			case 8:
			{
				display(head);
				break;
			}
			case 9:
			{
				head=reverse(NULL,head,head->next);
				cout<<"Linked List is reversed."<<endl;
				break;
			}
			default:
			{
				cout<<"invalid input"<<endl;
			}
		}
		cout<<"Do you want to continue ?(y/n)"<<endl;
		cin>>opt;
	}while(opt=='y');
}
