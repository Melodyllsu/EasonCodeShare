#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
  ifstream istr;
  int temp;

  istr.open(fileName.c_str());
  if (istr.fail()) {
    // We failed to open the file: throw an exception
    throw invalid_argument("");
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
    throw runtime_error("");
  }
}

int main()
{
  vector<int> myInts;
  const string fileName = "IntegerFile.txt";

  try {
    readIntegerFile(fileName, myInts);
  } catch (const invalid_argument& e) {
    cerr << "Unable to open file " << fileName << endl;
    return 1;
  } catch (const runtime_error& e) {
    cerr << "Error reading file " << fileName << endl;
    return 1;
  }

  for (size_t i = 0; i < myInts.size(); i++) {
    cout << myInts[i] << " ";
  }
  cout << endl;

  return 0;
}
