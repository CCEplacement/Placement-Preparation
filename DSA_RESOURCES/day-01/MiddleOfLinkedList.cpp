//MIDDLE OF LINKED LIST
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* nextPointer;
};

class MiddleNode
{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        //constructor
        MiddleNode() = default;
        //------NODE CREATION------
        void createNode(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->nextPointer = nullptr;
            insertToLL(newNode);
            return;
        }
        //------LINKED LIST INSERTION-------
        void insertToLL(Node* newNode)
        {
            if(head==nullptr)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            tail->nextPointer = newNode;
            tail = newNode;
            return;
        }
        //-----PRINT ENTIRE LINKED LIST------
        void printLL()
        {
            Node* iterator = head;
            while(iterator!=nullptr)
            {
                cout<<iterator->data<< "-->";
                iterator = iterator->nextPointer;
            }
            cout<< endl;
            return;
        }
        //------lENGTH OF LINKED LIST------
        int lengthOfLinkedList()
        {
            int count = 0;
            Node* iterator = head;
            while(iterator!=nullptr)
            {
                count++;
                iterator = iterator->nextPointer;
            }
            return count;
        }
        //------BRUTE FORCE: TWO PASS------
        Node* middleNodeBrute()
        {
            int lengthLL = lengthOfLinkedList();
            Node* temp = head;
            for(int it = 0; it<lengthLL/2 ; it++)
            {
                temp = temp->nextPointer;
            }
            return temp;
            
        }
        //------OPTIMAL: TORTOISE(SLOW POINTER) & HARE(FAST POINTER)-------
        Node* middleNodeOptimal()
        {
            Node* slow = head;
            Node* fast = head;
            while(fast!=nullptr && fast->nextPointer!=nullptr)
            {
                slow = slow->nextPointer;
                fast = fast->nextPointer->nextPointer;
            }
            return slow;
            
        }
        

};
int main()
{
    MiddleNode* obj = new MiddleNode();
    int choice = 1;
    int val;
    do
    {
        cout<< "Enter choice to Add Node: 1-Add, 0-Stop Adding: ";
        cin>> choice;
        if(choice==1)
        {
            cout<< "Enter Node value: ";
            cin>> val;
            obj->createNode(val);
        }
    }while(choice);
    obj->printLL();
    Node* middleBrute = obj->middleNodeBrute();
    if(middleBrute!=nullptr)
    {
        cout<< "Finding Middle Node using Brute-Force Approach: "<< middleBrute->data << endl;
    }
    else
    {
        cout<< "Brute Approach : No Middle Node ";
    }
    Node* middleOptimal = obj->middleNodeOptimal();
    if(middleOptimal!=nullptr)
    {
        cout<< "Finding Middle Node using Optimal Approach: "<< middleOptimal->data << endl;
    }
    else
    {
        cout<< "Optimal Approach : No Middle Node";
    }
    delete obj; //after this obj becomes a dangling pointer
    obj= nullptr; //so making obj point to nothing
    
    return 0;
}