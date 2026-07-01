//DETECT CYCLE IN LINKED LIST
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* nextPointer;
};

class DetectCycle
{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        //CONSTRUCTOR
        DetectCycle() = default;
        
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
        //------NODE CREATION------
        void createNode(int val,int Position)  
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->nextPointer = nullptr;
            insertToLL(newNode, Position);
            return;
        }
        //------LINKED LIST INSERTION-------
        void insertToLL(Node* newNode, int cycleFormPosition)
        {
            //cycleFormPosition -1(No cycle), anyother Number indicates, 
            //create a node and make newNode->next point to "cycleFormPosition"th Node of the Linkedlist
            //if "cycleFormPosition" is greater than the actual length of the linkedlist, or lesser than 1, don't make a cycle
            //simply return cycle cannot be formed. The index "cycleFormPosition" is either greater than LL length or below 1
            if(head==nullptr)
            {
                head = newNode;
                tail = newNode;
                if(cycleFormPosition==-1)
                {
                    cout<<"Node Cycle Position not Specified" << endl;
                }
                else if(cycleFormPosition==1)
                {
                    newNode->nextPointer = newNode; //SELF LOOP
                }
                else
                {
                    cout<<"There is no node in specfied"<<cycleFormPosition<< "index/position of LinkedList" << endl;
                }
                return;
            }
            tail->nextPointer = newNode;
            tail = newNode;
            if(cycleFormPosition==-1)
            {
                cout<<"Node Cycle Position not Specified" << endl;
                return;
            }
            if(cycleFormPosition<1 || cycleFormPosition>lengthOfLinkedList())
            {
                cout<<"There is no node in specfied"<<cycleFormPosition<< "index/position of LinkedList" << endl;
                return;
            }
            //find 'cycleFormInd-1'th position
            Node* temp = head;
            int iterator = 0;
            while(iterator<cycleFormPosition && temp!=nullptr)
            {
                iterator++;
                temp = temp->nextPointer;
            }
            newNode->nextPointer = temp;
            return;
        }
        //-----PRINT ENTIRE LINKED LIST------
        void printLL()
        {
            //A CYCLE DETECTED LINKED LIST CANNOT BE PRINTED NORMALLY
            if(head==nullptr)
            {
                cout<< "Empty List" << endl;
                return;
            }
            Node* iterator = head;
            unordered_set<Node*> VisitedNode;
            while(iterator!=nullptr && (VisitedNode.find(iterator)==VisitedNode.end()))
            {
                cout<< iterator->data << "-->";
                VisitedNode.insert(iterator);
                iterator = iterator->nextPointer;
            }
            cout<<iterator->data<<endl;
            return;
        }
        //------BRUTE FORCE: HASH SET TRACKING------
        bool hasCycleBrute()
        {
            unordered_set<Node*> visited;
            Node* currNode = head;
            while(currNode!=nullptr)
            {
                if(visited.find(currNode)!=visited.end())
                {
                    return true;
                }
                visited.insert(currNode);
                currNode = currNode->nextPointer;
            }
            return false;
        }
        //------OPTIMAL: FLOYD'S CYCLE FINDING-------
        bool hasCycleOptimal()
        {
            Node* slow = head;
            Node* fast = head;
            while(fast!=nullptr && fast->nextPointer!=nullptr)
            {
                slow = slow->nextPointer;
                fast = fast->nextPointer->nextPointer;
                if(slow==fast)
                {
                    return true;
                }
            }
            return false;
            
        }
        

};
int main()
{
    DetectCycle* obj = new DetectCycle();
    int choice = 1;
    int val;
    int position;
    do
    {
        cout<< "Enter choice to Add Node: 1-Add, 0-Stop Adding: ";
        cin>> choice;
        if(choice==1)
        {
            cout<< "Enter Node value: ";
            cin>> val;
            cout<< "Enter Cycle Position: either -1(No cycle Needed) or Any Node position: ";
            cin>> position;
            obj->createNode(val,position);
        }
    }while(choice);
    obj->printLL();
    bool bruteCycle = obj->hasCycleBrute();
    bool optimalCycle = obj->hasCycleOptimal();
    if(bruteCycle||optimalCycle)
    {
        cout<< "Cycle detected";
    }
    else
    {
        cout<< "No cycle detected";
    }
    delete obj;
    obj = nullptr;
    return 0;
}
