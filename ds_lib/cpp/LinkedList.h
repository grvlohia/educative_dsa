#include <iostream>

template <typename T>
class Node {
  public: 
    Node* next;
    Node* prev;
    T data;

    Node() {
      this->next = nullptr;
      this->prev = nullptr;
    }
  
    Node(T data) {
      this->next = nullptr;
      this->prev = nullptr;
      this->data = data;
    }
};

template <typename U>
class LinkedList {
  private:
    Node<U>* head;
    Node<U>* tail;
    int len;
  
  public:
    LinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
      this->len = 0;
    }

    // O(1)
    void insertAtEnd(U data) {
      Node<U>* newNode = new Node<U>(data);
      if (this->isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
        this->len += 1;
        return;
      }

      this->tail->next = newNode;
      this->tail = newNode;
      this->len += 1;
    }

    // O(1)
    void insertAtHead(U data) {
      Node<U>* newNode = new Node<U>(data);

      if (this->isEmpty()) {
        head = newNode;
        tail = newNode;
        len += 1;
        return;
      }

      newNode->next = head;
      head = newNode;
      len += 1;
    }

    void deleteAtHead() {
      if (this->isEmpty()) {
        std::cout << "Cannot delete. Linked list is empty" << std::endl;
        return; 
      }

      Node<U>* temp = head;
      if (head == tail) {
        head = nullptr;
        tail = nullptr;
        delete temp;
        len -= 1;
        return;
      }

      head = head->next;
      delete temp;
      len -= 1;
    }

    void deleteAtEnd() {
      if (tail == nullptr) {
        std::cout << "Cannot delete. Linked list is empty" << std::endl;
        return; 
      }

      Node<U>* curr = head;
      if (head == tail) {
        head = nullptr;
        tail = nullptr;
        delete curr;
        len -= 1;
        return;
      }

      Node<U>* prev = nullptr;
      while(curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
      }

      prev->next = nullptr;
      tail = prev;
      delete curr;
      len -= 1;
    }

    void remove(U data) {
      if (head == nullptr) {
        std::cout << "Cannot delete. Linked list is empty" << std::endl;
        return; 
      }

      Node<U>* curr = head;
      Node<U>* prev = nullptr;
      while(curr != nullptr) {
        if (curr->data == data) {
          if (curr == head) {
            deleteAtHead();
            return;
          } else if (curr == tail) {
            deleteAtEnd();
            return;
          } else {
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
            len -= 1;
            return;
          }
        }

        prev = curr;
        curr = curr->next;
      }

      std::cout << "Node with data: " << data << " not found in the list." << std::endl;
    }
    
    Node<U>* search(U data) {
      Node<U>* curr = head;
      while(curr != nullptr) {
        if (curr->data == data) {
          return curr;
        }

        curr = curr->next;
      }

      return nullptr;
    }

    bool isEmpty() {
      return head == nullptr;
    }

    std::string toString() {
      std::string res = "";
      Node<U>* curr = head;
      while(curr != nullptr) {
        if (curr == tail) {
          res = res + curr->data;
        } else {
          res = res + curr->data + "->";
        }

        curr = curr->next;
      }

      return res;
    }

    int size() {
      return this->len;
    }
};
