#include <iostream>
using namespace std;

// Main Queue
// Queue Defn
struct qNode
{
    string name;
    int age, yearofBirth;
    struct qNode *next;
};

// queue main head & temp head
struct qNode *head = NULL;
struct qNode *tempHead = NULL;

// enqueue function
void enqueue(string name, int age, int yearofBirth)
{
    struct qNode *newNode = (struct qNode*)malloc(sizeof(struct qNode));
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
        struct qNode *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = NULL;
        temp->next = newNode;
    }
}

// enqueue method for temp queue (i.e. with tempHead)
void enqueueTemp(struct qNode *head)
{
    struct qNode *newNode = (struct qNode*)malloc(sizeof(struct qNode));
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
        struct qNode *temp = tempHead;
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

        struct qNode *temp = head;
        head = head->next;

        enqueueTemp(temp);
        delete temp;
    }
}

// method to display queue for given head (passed as parameter)
void displayQueue(struct qNode *node)
{
    cout << endl;
    if(node == NULL)
    {
        cout << "Queue is now empty!" << endl;
        return;
    }

    struct qNode *temp = node;
    while(temp != NULL)
    {
        cout << temp->name << ", " << temp->age << ", " << temp->yearofBirth << endl;
        temp = temp->next;
    }

    cout << endl;
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

    struct qNode *temp = tempHead;
    while(temp != NULL)
    {
        enqueue(temp->name, temp->age, temp->yearofBirth);
        temp = temp->next;
    }

    cout << endl << "Queue after requeuing to it: ";
    displayQueue(head);

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

    int ctr = n;
    cout << "Now popping each off and queueing to Queue ADT: " << endl;
    while(ctr--)
    {
        enqueue(top->name, top->age, top->yearofBirth);
        popStack();
    }

    cout << endl << "Reversed Queue now: ";
    displayQueue(head);

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