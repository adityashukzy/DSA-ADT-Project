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

// Main Queue Head
struct qNode *head = NULL;
struct qNode *tempHead = NULL;

// Main Queue 
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

void dequeue()
{
    if(head == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }
    else
    {
        cout << "Dequeueing Node: " << endl <<  head->name << ", " << head->age << ", " << head->yearofBirth << endl;

        struct qNode *temp = head;
        head = head->next;

        enqueueTemp(temp);
    }
}

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

int main()
{
    int n, age, yearofBirth;
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

    cout << endl << "New temporary queue: ";
    displayQueue(tempHead);

    cout << "Original queue: ";
    displayQueue(head);

    return 0;
}
