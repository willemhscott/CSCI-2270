#include<iostream>
#include<string>
using namespace std;

/* 
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
    even_size = 0;

    // Count the number of even entries
	for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) { // Determine odd/even-ness
            even_size++;
        }
	}
    // Odd entries will be the difference of the total size and the even entries
	odd_size = size - even_size;

	// Create arrays with newly determined sized
	even_arr = new int[even_size];
	odd_arr = new int[odd_size];

    // Reset counters to 0
    even_size = 0;
    odd_size = 0;

    // Populate arrays with odd and even items
	for (int i = 0; i < size; i++) {
	    if (arr[i] % 2 == 0) {
	        even_arr[even_size] = arr[i];
	        even_size++;
	    } else {
	        odd_arr[odd_size] = arr[i];
	        odd_size++;
	    }
	}
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
	//split();
	int *even_arr, *odd_arr;
	int even_size, odd_size;
    split(arr,even_arr,odd_arr, size, even_size, odd_size);
	// Output
	// If there are even items
	if (even_size != 0) {
	    cout << "even array: ";
        printArray(even_arr, even_size);
    } else {
	    cout << "no even items in array" << endl;
	}
	// If there are odd items
	if (odd_size != 0) {
	    cout << "odd array: ";
        printArray(odd_arr, odd_size);
    } else {
	    cout << "no odd items in array" << endl;
	}
	// Clean up (delete)
	delete[] even_arr;
	delete[] odd_arr;
	delete[] arr;

    return 0;
}
