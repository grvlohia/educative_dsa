#include "./ds_lib/cpp/LinkedList.h"
#include <iostream>

using namespace std;

int main() {
  LinkedList<char>* myLL = new LinkedList<char>();

  myLL->insertAtHead('b');
  myLL->insertAtEnd('c');
  myLL->insertAtEnd('d');
  myLL->insertAtEnd('e');
  myLL->insertAtEnd('f');
  myLL->insertAtHead('a');
  
  cout << myLL->toString() << endl;

  myLL->deleteAtEnd();
  myLL->remove('b');
  myLL->remove('z');
  myLL->deleteAtHead();
  Node<char>* found = myLL->search('c');

  cout << found->data << endl;
  
  cout << myLL->toString() << endl; // expected output: c->d->e
  cout << myLL->size() << endl;
}