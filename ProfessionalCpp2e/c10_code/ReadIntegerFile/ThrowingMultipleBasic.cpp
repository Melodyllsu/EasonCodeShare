#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
  ifstream istr;
  int temp;

  istr.open(fileName.c_str());
  if (istr.fail()) {
    // We failed to open the file: throw an exception
    throw exception();
  }

  // Read the integers one-by-one and add them to the vector
  while (istr >> temp) {
    dest.push_back(temp);
  }

  if (istr.eof()) {
    // We reached the end-of-file.
    istr.close();
  } else {
    // Some other error. Throw an exception
    istr.close();
    throw exception();
  }
}

int main()
{
  vector<int> myInts;
  const string fileName = "IntegerFile.txt";

  try {
    readIntegerFile(fileName, myInts);
  } catch (const exception& e) {
    cerr << "Unable either to open or to read " << fileName << endl;
    return 1;
  }

  for (size_t i = 0; i < myInts.size(); i++) {
    cout << myInts[i] << " ";
  }
  cout << endl;

  return 0;
}


