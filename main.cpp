/*1  Write a function which, given a pointer to the head of the list and an integer,
inserts the integer into the list, keeping it in sorted order (ascending).*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int data;
	Node * next;
};
// function prototypes
Node * createNode(int n);
Node * insertAtHead(Node * top, int n);
int size(Node * top);
void printList(Node * top);
int sumList(Node * top);
bool isSorted(Node *top);
Node* insertInOrder(Node * top, int key);
Node* reverse(Node* top);
Node* sort(Node* top);


int main() {



	int num;

	//int nodeSize;  /* Make things once you need them, you will get a warning otherwise */                //these i just made in case i wanted to sort the  list and needed its size or whatever
	Node *myList = nullptr;
	cout << "Enter numbers for a linked list.\nEnter -1 to terminate\n";
	while (cin >> num && num != -1)
		myList = insertAtHead(myList, num);
	cout << "List = ";
	printList(myList);
	cout << ", n = ";
	cout << size(myList) << ", sum = " << sumList(myList);
	cout << ((isSorted(myList)) ? "\nThis list is sorted\n" : "\nThis list is not sorted\n");
	cout << "Sorted list = ";
	printList(sort(myList));
	system("PAUSE");
}


Node * createNode(int n) {
	Node * newNode;

	newNode = (Node *)malloc(sizeof(Node));      //my lecturer insists on this shit
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

Node * insertAtHead(Node * top, int n) {
	Node * newNode;

	newNode = createNode(n);
	newNode->next = top; // this works even if the list isempty (i.e., top = NULL)
	top = newNode;
	return top; // return pointer to new head of list
}

int size(Node * top) {
	Node * curr;
	int numNodes = 0;

	curr = top;
	while (curr != NULL) {
		numNodes = numNodes + 1;
		curr = curr->next;
	}
	return numNodes;
}

void printList(Node* top)
{
	if (top == NULL)
	{
		cout << "[<empty-list>]";
		return;
	}
	Node *temp = top;
	cout << "[ ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "]";
}

int sumList(Node * top) {
	Node * curr = top; // again, on one line...
	int count = 0;
	if (top == NULL) {
		cout << "Error: [<empty-list>]";
		return 0;
	}
	while (curr != NULL) {
		// cout << curr -> data << "\t";
		count = count + curr->data; // or count += curr->data; btw, on your line the brackets are not needed
		curr = curr->next;
	}
	return count;
}

bool isSorted(Node *top) {
	if (top == NULL) // This is good
		return 0;
	for (Node *t = top; t->next != NULL; t = t->next)
	{
		if (t->data <= t->next->data)
			return false; //if at least one is not sorted, return false...
	}
	return true; // ...otherwise true
}

// Write a function which, given a pointer to the head of the list and an integer, 
//inserts the integer into the list, keeping it in sorted order (ascending).*/

Node* insertInOrder(Node * top, int num) // keep the var names the same
{
	Node* newNode = createNode(num);
	delete newNode;
	top = reverse(top);
	return top;
}

//Node* reverse(Node *top) {
//	Node *curr = top;
//	Node *advCurr = NULL;
//	while (curr != NULL) {
//		advCurr = curr->next;
//		if (top == curr)
//			top->next = NULL;
//		else {
//			curr->next = top;
//			top = curr;
//		}
//		curr = advCurr;
//	} //while      
//	return top;
//}
Node* reverse(Node* head)
{
	// Initialize current, previous and 
	// next pointers 
	Node *current = head;
	Node *prev = NULL, *next = NULL;


	while (current != NULL)
	{
		next = current->next;
		current->next = prev; //Switch pointer around
		prev = current;
		current = next;
	}
	head = prev;
	head->next = current;
	return head;
}

Node* sort(Node * top)
{
	while (!isSorted(top))
	{
		for (Node* ptr = top; ptr != NULL; ptr = ptr->next)
			if (ptr->next != NULL)
				if (ptr->data > ptr->next->data)
					swap(ptr->data, ptr->next->data);
	}
	return top;
}