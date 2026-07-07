// CHECK LINKED LIST AS PALINDROME - (LC 234)
// Palindrome : Call anything Palindrome if itself(Actual) and it's reverse are same
// EX: MALAYALAM
// The Pointers are assigned with "nullptr" and not "NULL". why?
// PalindromeCheck.cpp
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* nextPointer;
};

class Linkedlist
{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
    //getter function
    Node* getHead()
    {
       return this->head; 
    }
        //CONSTRUCTOR (what type of constructor)
        Linkedlist()= default;
        //------NODE CREATION------
        void createNode(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->nextPointer = nullptr;
            insertToLL(newNode);
            return;
        }
        //------LINKED LIST INSERTION------
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
        //------PRINT LINKED LIST------
        void printLL()
        {
            if(head==nullptr)
            {
                cout<< "Empty List" <<endl;
                return;
            }
            Node* iterator = head;
            while(iterator!=nullptr)
            {
                cout<< iterator->data <<"-->";
                iterator = iterator->nextPointer;
            }
            cout<<" NULL"<<endl;
            return;
        }
    
};
class Palindrome
{
    public:
    //constructor
    Palindrome()=default;
    bool isPalindromeBrute(Node* head) //obj.head
    {
        // Using Auxiliary Vector Copy
        vector<int> copyVector;
        Node* iterator = head;
        while(iterator!=nullptr)
        {
            copyVector.push_back(iterator->data);
            iterator = iterator->nextPointer;
        }
        int left = 0 , right = copyVector.size()-1;
        while(left<right)
        {
            if(copyVector[left]!=copyVector[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindromeOptimal(Node* head)
    {
        // In-Place Midpoint Reversal
        if(head==nullptr || head->nextPointer==nullptr)
        {
            return true;
        }
        //find the middle of Linkedlist
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->nextPointer!=nullptr)
        {
            slow = slow->nextPointer;
            fast = fast->nextPointer->nextPointer;
        }
        //slow is holding the middle node
        // |  1  |---->|  2  |---->|  2  |---->|  1  |
        //                          slow
        //Reverse the list Nodes from the Node, in which slow is pointing to
        //Reversing logic
        Node* prev = nullptr;
        Node* curr = slow;
        Node* next = nullptr;
        while(curr!=nullptr)
        {
            next = curr->nextPointer;
            curr->nextPointer = prev;
            prev = curr;
            curr = next;
        }
        Node* left = head; //head1
        Node* right = prev;//head2
        while(right!=nullptr)
        {
            if(left->data!=right->data)
            {
                return false;
            }
            left = left->nextPointer;
            right = right->nextPointer;
        }
        return true;
    }         
} ;
int main()
{
    Linkedlist *obj1 = new Linkedlist();
    Palindrome *obj2 = new Palindrome();
    int choice;
    do
    {
        cout<<"Enter Choice: 1(Add), 0(stop adding):";
        cin>>choice;
        if(choice==1)
        {
            int val;
            cout<<"Enter Node val:";
            cin>>val;
            obj1->createNode(val);
        }
    }while(choice);
    obj1->printLL();
    bool isPalBrute = obj2->isPalindromeBrute(obj1->getHead());
    bool isPalOpt = obj2->isPalindromeOptimal(obj1->getHead());
    if(isPalBrute || isPalOpt)
    {
        cout<< "Palindrome";
    }
    else
    {
        cout<<" Not Palindrome";
    }
    return 0;
}