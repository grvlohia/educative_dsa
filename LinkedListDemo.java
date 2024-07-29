import ds_lib.java.CustomLinkedList;

public class LinkedListDemo {
  public static void main(String[] args) {
    CustomLinkedList<String> myLL = new CustomLinkedList<>();

    myLL.insertAtEnd("ball");
    myLL.insertAtEnd("cat");
    myLL.insertAtEnd("dog");
    myLL.insertAtEnd("elephant");
    myLL.insertAtEnd("fish");
    myLL.insertAtHead("apple");

    System.out.println(myLL.toString());

    myLL.remove("fish");
    System.out.println(myLL.size());
    System.out.println(myLL.toString());
  }
}
