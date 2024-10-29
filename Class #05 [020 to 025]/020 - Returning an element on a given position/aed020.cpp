#include <iostream>

#include "singlyLinkedList.h"

template <typename T>
void print(SinglyLinkedList<T> & lst){
  std::cout << lst.toString() << std::endl;
}

int main(int argc, char const *argv[])
{
    return 0;
}
