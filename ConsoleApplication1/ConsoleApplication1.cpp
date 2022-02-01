#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int data;
	Node* Next;
	Node* Previous;
};
class Doubly
{
public:
	Node* head;
	Doubly()
	{
		head == NULL;
	}
	void insertionatfront(int val)
	{
		if (head == NULL)
		{
			Node* newnode = new Node;
			newnode->data = val;
			newnode->Next = newnode->Previous = NULL;
			head = newnode;
		}
		else
		{
			Node* newnode = new Node;
			newnode->data = val;
			head->Previous = newnode;
			newnode->Next = head;
			newnode->Previous = NULL;
			head = newnode;

		}
	}
	void insertionatend(int val)
	{
		Node* M = head;
		Node* N = new Node();
		if (head == NULL)
		{
			N->data = val;
			N->Next = N->Previous = NULL;
			head = N;
		}
		else
		{
			while (M->Next != NULL)
			{
				M = M->Next;
			}
			N->data = val;
			M->Next = N;
			N->Previous = M;
			N->Next = NULL;
		}
	}
	bool searchR(Node * N,int number)
	{
		if (N == NULL)return false;
		else
		{
			return N->data == number ? true : false;
		}
		searchR(N->Next, number);
	}
	bool searchWR(int number)
	{
		Node* N = head;
		while (N != NULL)
		{
			if (N->data == number)
			{
				return true;
			}
			N = N->Next;
		}
	}
	void insertion(int val, int number)
	{
		Node* M = head;
		Node* P = head;
		Node* N = new Node();
		if (searchWR(number))
		{
			while (M->data != number)
			{
				M = M->Next;
			}
		}
		else
		{
			cout << "Number not found\n";
			return;
		}
		P = M->Next;
		if (P == NULL)
		{
			insertionatend(val);
		}
		else
		{
			N->data = val;
			N->Next = P;
			P->Previous = N;
			M->Next = N;
			N->Previous = M;
		}

	}
	void sorting()
	{
		Node* N = head;
		vector<int>v;
		while (N != NULL)
		{
			v.push_back(N->data);
			N = N->Next;
		}
		sort(v.begin(), v.end());
		for (auto x : v)
		{
			cout << x << "\t";
		}
		cout << endl;

	}
	void deletion(int val)
	{
		Node* M = head;
		if (head != NULL)
		{	
			while (M->Next != NULL)
			{
				M = M->Next;
			}
		}
		else
		{
			cout << "List is empty\n";
			return;
		}
		if (searchWR(val))
		{
			if (head->data == val)
			{
				Node* N = head;
				head = head->Next;
				delete N;
			}
			else if (M->data == val)
			{
				Node* P;
				P = M->Previous;
				free(M);
				P->Next = NULL;
			}
			else
			{
				Node* N = head;
				while (N->data != val)
				{
					N = N->Next;
				}
				Node *P = N->Previous;
				Node* O = N->Next;
				P->Next = O;
				O->Previous = P;
				free(N);
			}
		}
		else
		{
			cout << "Value not found\n";
		}
	}
	void display()
	{
		Node* N = head;
		while (N != NULL)
		{
			cout << N->data << "\t";
			N = N->Next;
		}
		cout << endl;
	}

};
int main()
{
	Doubly D;
	D.insertionatfront(4);
	D.insertionatfront(5);
	D.insertionatfront(8);
	D.insertionatend(1);
	D.insertion(3, 5);
	if (D.searchR(D.head, 6))
	{
		cout << "found\n";
	}
	else
	{
		cout << "not found\n";
	}
	D.display();
	D.sorting();
	D.deletion(4);
	D.display();
	D.deletion(8);
	D.display();
	D.deletion(1);
	D.display();

}
