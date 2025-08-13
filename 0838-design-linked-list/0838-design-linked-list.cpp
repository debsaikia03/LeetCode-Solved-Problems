class Node{

public:
    int data;
    Node* next;

    Node(int data){

        this->data = data;
        this->next = nullptr;
    }
};

class MyLinkedList {

private:
   Node* head;
   int size;

public:
    MyLinkedList() {
        
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {

        if(index < 0 || index >= size) return -1;

        Node* curr = head;

        int i = 0;
        while(i < index){

            curr = curr->next;
            i++;
        }

        return curr->data;    
    }
    
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {

        Node* newNode = new Node(val);
        newNode->next = nullptr;

        if(!head){
            
            head = newNode;
            size++;
            return;
        }

        Node *curr = head;

        while(curr->next != nullptr){

            curr = curr->next;
        }

        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) return;

        Node* newNode = new Node(val);
        newNode->next = nullptr;
        
        if(index == 0){

            addAtHead(val);
            return;
        }

        if(index == size){

            addAtTail(val);
            return;
        }

        Node* curr = head;

        int i = 0; 
        while(i < index - 1){

            curr = curr->next;
            i++;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) return;

        if(index == 0){

            head = head->next;
            size--;
            return;
        }
        
        Node* curr = head;

        int i = 0; 
        while(i < index-1){

            curr = curr->next;
            i++;
        }

        curr->next = curr->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */