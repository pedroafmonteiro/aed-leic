// AED 2024/2025 [Pedro Ribeiro - DCC/FCUP]
// An example usage of STL maps

#include <iostream>
#include <map>

using namespace std;

int main() {

  map<string, int> m;

  // Insert some elements
  m["John"] = 42;
  m["Sarah"] = 31;
  m["Tom"] = 56;

  // Print the elements of the map: each entry is a pair (key, value)
  for (auto p : m)
    cout << p.first << " -> " << p.second << endl;

  // Checking if a key is on the map
  // find return an iterator to position or end() if not present
  cout << "is Sarah on m? " << (m.find("Sarah")!=m.end()?"yes":"no") << endl;
  cout << "is Bob on m? " << (m.find("Bob")!=m.end()?"yes":"no") << endl;

  // Printing the value of a key
  cout << "Value of Sarah? " << m["Sarah"] << endl;
  // Careful: if the value does not exist, it will be created...
  cout << "Value of Kim? " << m["Kim"] << endl;

  // Showcasing erase and changing a value
  m.erase("Sarah");
  m["Tom"] = 20;
  cout << "After erasing Sarah and changing the value of Tom:" << endl;
  for (auto p : m)
    cout << p.first << " -> " << p.second << endl;
    
  return 0;
}
