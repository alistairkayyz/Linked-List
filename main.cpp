//C++ Linked List Code
#include <iostream>

using namespace std;

class myList{
private:
    typedef struct node{
        int data;
        node* next;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;
public:
    myList();
    void addNode(int addData);
    void deleteNode(int delData);
    void sortList();
    void printList();
};
//constructor initalizes the values to zero
//when the object is created
myList::myList(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

//method to add a node
void myList::addNode(int addData){
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    } else{
        head = n;
    }
}

//method to delete a node
void myList::deleteNode(int delData){
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while(curr != NULL && curr->data != delData){
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout<<delData<<" was not in the list\n";
        delete delPtr;
    } else{
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head){
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout<<"The value "<<delData<<" was deleted\n";
    }
}
//method to sort the list
void myList::sortList(){
    curr = head;
    temp = head;
    while(curr->next != NULL){
        temp = curr->next;
        while(temp != NULL){
            if(temp->data < curr->data){
                int t = temp->data;
                temp->data = curr->data;
                curr->data = t;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}
//method to display the list
void myList::printList(){
    curr = head;
    cout << "\nLIST OUTPUT: ";
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout<<endl<<endl;
}
char menu(){
    char choice;
    cout << "MAIN MENU.\n";
    cout << "1. Add\n";
    cout << "2. remove\n";
    cout << "3. display list\n";
    cout << "4. Exit\n";
    cin >> choice;
    return choice;
}

int main()
{
    myList object;
    char choice;
    int data;
    do{
        choice= menu();

        switch(choice){
        case '1' : cout <<"enter a value to insert:";
        cin >> data;
        object.addNode(data);
        object.sortList();
        break;

        case '2': cout <<"enter a value to delete:";
        cin >> data;
        object.deleteNode(data);
        break;
        case '3' : object.printList();
        break;
        default : cout << "System exit\n";
        }
    }while(choice !='4');
    return 0;
}
