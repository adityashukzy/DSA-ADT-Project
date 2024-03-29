#include <iostream>
using namespace std;

// STACK DEFINITIONS AND METHODS
// stack structure definition
struct node
{
    string name;
    int age, yearofBirth;
    struct node *next;
};

// top of stack
struct node *top = NULL;

// method to push to TOS
void pushStack(string name, int age, int yearofBirth)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->age = age;
    newNode->yearofBirth = yearofBirth;

    if(top == NULL)
    {
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

// method to pop off tos and print to terminal
void popStack()
{
    if(top == NULL)
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        struct node *temp = top;
        top = top->next;
        cout << "Popping Node: " << temp->name << ", " << temp->age << ", " << temp->yearofBirth << endl;
        delete temp;
    }
}

// method to display stack
void displayStack()
{
    struct node *temp = top;
    
    cout << endl << "Stack: " << endl;
    while(temp != NULL)
    {
        cout << temp->name << ", " << temp->age << ", " << temp->yearofBirth << endl;
        temp = temp->next;
    }

    cout << endl;
}



// QUEUE DEFINITIONS AND METHODS
// queue structure defintion
/*struct qNode
{
    string name;
    int age, yearofBirth;
    struct qNode *next;
};*/

// queue main head & temp head
struct node *head = NULL;
struct node *tempHead = NULL;

// enqueue function
void enqueue(string name, int age, int yearofBirth)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->age = age;
    newNode->yearofBirth = yearofBirth;

    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = NULL;
        temp->next = newNode;
    }
}

// enqueue method for temp queue (i.e. with tempHead)
void enqueueTemp(struct node *head)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->name = head->name;
    newNode->age = head->age;
    newNode->yearofBirth = head->yearofBirth;

    if(tempHead == NULL)
    {
        newNode->next = NULL;
        tempHead = newNode;
    }
    else
    {
        struct node *temp = tempHead;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = NULL;
        temp->next = newNode;
    }
}

// method to dequeue main queue
void dequeue()
{
    if(head == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    else
    {
        cout << "Dequeueing Node: " <<  head->name << ", " << head->age << ", " << head->yearofBirth << endl;

        struct node *temp = head;
        head = head->next;

        enqueueTemp(temp);
        delete temp;
    }
}

// method to display queue for given head (passed as parameter)
void displayQueue(struct node *node)
{
    cout << endl;
    if(node == NULL)
    {
        cout << "Queue is now empty!" << endl;
        return;
    }

    struct node *temp = node;
    while(temp != NULL)
    {
        cout << temp->name << ", " << temp->age << ", " << temp->yearofBirth << endl;
        temp = temp->next;
    }

    cout << endl;
}

struct tree
{
    string name;
    int age, yearofBirth;
    struct tree *left;
    struct tree *right;
};

struct tree *root = NULL;
static int count = 0; //for correct number of insertions

struct tree *insert(struct tree *rt, int  level, int n)
{
    if(count == n)
	    return rt;
    if(level == 1)
    {
	struct tree *tmp = new struct tree;
 	tmp->name = head->name;
	tmp->age = head->age;
	tmp->yearofBirth = head->yearofBirth;
 	tmp->left = tmp->right = NULL;
 	rt = tmp;
	dequeue();
	count++;
	
    }
    else
    {
	rt->left = insert(rt->left,level-1,n);
	rt->right = insert(rt->right, level-1,n);
    }
    return rt;
}

void preorder(struct tree *link)
{
    if(link == NULL)
    {
	return;
    }
    else
    {
	 cout << link->name << ", " << link->age << ", " << link->yearofBirth << "\n";
	preorder(link->left);
	preorder(link->right);
    }
}

void postorder(struct tree *link)
{
    if(link == NULL)
    {
	return;
    }
    else
    {
	postorder(link->left);
	postorder(link->right);
	cout << link->name << ", " << link->age << ", " << link->yearofBirth << "\n";
    }
}

struct node *list = NULL;

void listInsert(struct tree *link)
{
    struct node *tmp = new struct node;
    tmp->name = link->name;
    tmp->age = link->age;
    tmp->yearofBirth = link->yearofBirth;
    tmp->next =  NULL;

    if(list == NULL)
	list = tmp;
    else
    {
	struct node *nt = list;
	while(nt->next != NULL)
	    nt = nt->next;
	nt->next = tmp;
    }
}

void inorderInsert(struct tree *link)
{
    if(link == NULL)
	return;
    else
    {
	inorderInsert(link->left);
	listInsert(link);
	inorderInsert(link->right);
    }
}

void display(struct node *link)
{
    struct node *tmp = link;
    while(tmp != NULL)
    {
	cout << tmp->name << ", " << tmp->age << ", " << tmp->yearofBirth << "\n";
	tmp = tmp->next;
    }
}

struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

//Partitions the list taking the last element as the pivot. 
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->name < pivot->name)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

//Quick sort function using recursion. 
struct node *quickSortRecur(struct node *head, struct node *end)
{
    if (!head || head == end)
        return head;

    node *newHead = NULL, *newEnd = NULL;

    struct node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

//The main function for quicksort which calls the quickSortRecur function. This is a wrapper over the recursive function. 
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

void update()
{
    struct node *newNode = new struct node;
    cin >> newNode->name >> newNode->age >> newNode->yearofBirth;
    newNode->next = NULL;

    if(newNode->name < list->name)
    {
	newNode->next = list;
	list = newNode;
    }
    else
    {
	struct node *prev = list;
	struct node *nt = list;
	while(nt != NULL)
	{
	    if(newNode->name < nt->name)
		break;
	    prev = nt;
	    nt = nt->next;
	}
	if(nt == list)
	{
	    nt = nt->next;
	}
	prev->next = newNode;
	newNode->next = nt;
    }
}

void userResponse()
{
    cout << "\nPlease enter any key to continue:\n";
    char c = cin.get();
}


// MAIN FUNCTION
int main()
{
    // basic definitions
    int n, age, yearofBirth, choice;
    string name;

    cout << "Please enter number of records: ";
    cin >> n;
    cout << "Please enter name, age and year of birth for each record: " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> name >> age >> yearofBirth;
        enqueue(name, age, yearofBirth);
    }

    cout << endl << "Queue: ";
    displayQueue(head);

    int i = n;
    while(i--)
    {
        dequeue();
    }

    cout << endl << "Queue now: ";
    displayQueue(head);

    struct node *temp = tempHead;
    while(temp != NULL)
    {
        enqueue(temp->name, temp->age, temp->yearofBirth);
        temp = temp->next;
    }

    cout << endl << "Queue after requeuing to it: ";
    displayQueue(head);
userResponse();
/*
    cout << endl << endl << "Do you wish to continue processing? (y/n)" << endl;
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
        cout << endl << "Continuing!" << endl;
    else
        exit(0);
*/

    // =========================================================================== //

    cout << "Dequeueing elements and pushing them to top of stack: " << endl;
    while(head != NULL)
    {
        pushStack(head->name, head->age, head->yearofBirth);
        dequeue();
    }

    displayStack();
userResponse();
    int ctr = n;
    cout << "Now popping each off and queueing to Queue ADT: " << endl;
    while(ctr--)
    {
        enqueue(top->name, top->age, top->yearofBirth);
        popStack();
    }

    cout << endl << "Reversed Queue now: ";
    displayQueue(head);
	userResponse();

    int level = 0;
    ctr = n;
    while(ctr > 0)
    {
	level++;
	ctr /=2;
    }
    cout << "Dequeueing data into an unordered binary tree:\n";
    int l = 1;
    while(l <= level)
    {
        root = insert(root,l,n);
	l++;
    }
    
    cout << "\nPreorder traversal of the unordered binary tree:\n";
    preorder(root);
	userResponse();
    cout << "\nPostorder traversal of the unordered binary tree:\n";
    postorder(root);
	userResponse();
	cout << "\nInserting contents into a linked list in in-order:\n";
    inorderInsert(root);
    cout << "The linked list:\n";
    display(list);
	
	cout<<"\nQuicksorting the list:\n";
    //node *a=list;
    quickSort(&list);
    display(list);
	userResponse();
	cout << "\nPlease enter the new set of input:\n";
    update();
    cout << "\nFinal list:\n";
    display(list);
/*
    cout << endl << endl << "Do you wish to continue processing? (y/n)" << endl;
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
        cout << endl << "Continuing!" << endl;
    else
        exit(0);
*/

    // =========================================================================== //

    return 0;
}
