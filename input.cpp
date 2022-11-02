#include <fstream>
#include <iostream>

using namespace std;

int main () {
  char line[128];
  int count = 0;
  
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( myfile.getline (line, 128) )
    {
      cout << count++ << ":" << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}