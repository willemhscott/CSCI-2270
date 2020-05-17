#include <iostream>
#include <fstream>

using namespace std;


//Uncomment the lines and implement the TODOs in the resizing logic
void resize(int *&arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
	// int newCapacity =
  // cout<<"Resizing from "<<capacity<<" to "<<newCapacity<<endl;

	// TODO dynamically allocate an array of size newCapacity
	// int *newArray =

	// TODO copy all data from oldArray to newArray

	// TODO free the memory associated with oldArray

	//arrayPtr = newArray;
	//capacity = newCapacity;

    int *temp = new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        temp[i] = arrayPtr[i];
    }
    delete[] arrayPtr;
    arrayPtr = temp;
    capacity *= 2;

}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		return -1;
	}
	string filename = argv[1];
	ifstream data;
	data.open(filename.c_str());

	int capacity = 10;
	int *arrayPtr;

	// TODO Dynamically allocate space here for the array
	arrayPtr = new int[capacity];
	int numOfElement = 0;
	string temp;

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			int toBeInsert = stoi(temp);
			if(numOfElement == capacity)
			{
				// Complete this function
				resize(arrayPtr, capacity);
			}
			arrayPtr[numOfElement] = toBeInsert;
			numOfElement++;
		}
		data.close();
	}

	for(int i = 0; i < numOfElement; i++)
	{
		cout << "Num: " << arrayPtr[i] << endl;
	}
	return 0;
}
