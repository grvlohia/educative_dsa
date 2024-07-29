package ds_lib.java;

public class CustomLinkedList<T> {
  public class Node {
    Node next;
    Node prev;
    T data;

    Node() {
      next = null;
      prev = null;
    }

    Node(T data) {
      this.data = data;
      next = null;
      prev = null;
    }
  }

  private Node head;
  private Node tail;
  private int length;

  public CustomLinkedList() {
    head = null;
    tail = null;
    length = 0;
  }

  public boolean isEmpty() {
    return head == null;
  }

  public void insertAtHead(T data) {
    Node newNode = new Node(data);
    if (this.isEmpty()) {
      head = newNode;
      tail = newNode;
      length += 1;
      return;
    }

    newNode.next = head;
    head = newNode;
    length += 1;
  }

  public void insertAtEnd(T data) {
    Node newNode = new Node(data);
    if (this.isEmpty()) {
      head = newNode;
      tail = newNode;
      length += 1;
      return;
    }

    tail.next = newNode;
    tail = newNode;
    length += 1;
  }

  public void deleteAtHead() {
    if (isEmpty()) {
      System.out.println("Cannot delete. Linked list is empty");
      return;
    }
    // == compares to see if the two references are to the EXACT SAME OBJECT.
    // equals compares to see if the two references are to objects which have
    // matching properties, based on the class-specific criteria in the class's
    // equals implementation.
    if (head == tail) {
      head = null;
      tail = null;
      length -= 1;
      return;
    }

    head = head.next;
    length -= 1;
  }

  public void deleteAtEnd() {
    if (isEmpty()) {
      System.out.println("Cannot delete. Linked list is empty");
      return;
    }

    Node curr = head;
    if (head == tail) {
      head = null;
      tail = null;
      length -= 1;
      return;
    }

    Node prev = null;
    while (curr.next != null) {
      prev = curr;
      curr = curr.next;
    }
    prev.next = null;
    tail = prev;
    length -= 1;
  }

  public void remove(T key) {
    if (isEmpty()) {
      System.out.println("Cannot delete. Linked list is empty");
      return;
    }

    Node curr = head;
    Node prev = null;
    while (curr != null) {
      if (curr.data == key) {
        if (curr == head) {
          deleteAtHead();
          return;
        } else if (curr == tail) {
          deleteAtEnd();
          return;
        } else {
          prev.next = curr.next;
          curr.next = null;
          length -= 1;
          return;
        }
      }

      prev = curr;
      curr = curr.next;
    }

    System.out.println(String.format("Node with data: %s not found in the list.", key.toString()));
  }

  public Node search(T key) {
    Node curr = head;
    while (curr != null) {
      if (curr.data == key) {
        return curr;
      }

      curr = curr.next;
    }

    return null;
  }

  @Override
  public String toString() {
    String res = "";

    if (isEmpty()) {
      return res;
    }
    
    Node curr = head;
    while (curr != null) {
      res = res + curr.data.toString() + "->";

      curr = curr.next;
    }

    res += "null";

    return res;
  }

  public int size() {
    return length;
  }
}