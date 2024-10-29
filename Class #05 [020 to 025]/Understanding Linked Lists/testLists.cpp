// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Example of how to use a the SinglyLinkedList<T> class
// Last update: 20/10/2024
// -------------------------------------------------------------

#include <iostream>

#include "singlyLinkedList.h"

template <typename T>
void print(SinglyLinkedList<T> & lst){
  std::cout << lst.toString() << std::endl;
}
  

int main(){
  // Create a list of integers
  SinglyLinkedList<char> list;

  // writing the list (at the start it is empty)
  print(list);

  // Checking whether it is empty
  std::cout << "isEmpty? " << list.isEmpty() << std::endl;

  print(list);

  // checking the size of the list
  std::cout << "size = " <<  list.size() << std::endl;

  // Removing the first element
  list.removeFirst();
  print(list);

  // Removing the last element
  list.removeLast();
  print(list);

  // Checking whether it is empty
  std::cout << "isEmpty? " << list.isEmpty() << std::endl;

  // Writing the first and the last elements
  std::cout << "getFirst() = " << list.getFirst() << std::endl;
  std::cout << "getLast() = " <<  list.getLast() << std::endl;

  return 0;
}
