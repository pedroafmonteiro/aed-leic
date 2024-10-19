// An example solution for the exercise: [AED000] this is not a problem!

#include <iostream>

using namespace std;

int main()
{

  int q;
  cin >> q;

  int count = 0;
  for (int i = 0; i < q; i++)
  {
    int n;
    cin >> n;
    if (n == 42)
      count++;
  }

  cout << count << endl;
  return 0;
}
