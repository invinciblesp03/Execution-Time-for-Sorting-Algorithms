/**************************************************************
* Programmer Name:Shree Prakash Shah
* File Name: Execution
* Date of Last Modification: 11/11/2022 A.D.
* Description: It is a complete C++ program that analyzes the selection, insertion,
shell sort(with two different gap values)and quick sorts by keeping track of how long
they the take to sort arrays of ints of size 5000, 10000, and 100000, as well as the 
number of swaps and comparisons they take in doingso.
*
**************************************************************/

#include<iostream>
#include<ctime>
#include <iomanip>

using namespace std;
// structure with the swaps and comparisons
struct keeptrack {
    long long swaps;
    long long comparisons;
};
// funstion parameters
void insertionSort(int[], int, keeptrack&);
void selectionSort(int[], int, keeptrack&);
void InsertionSortInterleaved(int[], int, int, int, keeptrack&);
void shellSort(int[], int, int[], int, keeptrack&);
void Zero(keeptrack&);
int partition(int[], int, int, keeptrack&);
void quicksort(int[], int, int, keeptrack&);
// global constants
const int SIZE = 100000;
const int GAP_SIZE = 20;
const int SIZE2 = 100000;


// main function
int main() {

    int size;                   // number elements to be sorted int he array
    int numGaps = 0;
    int count = 0;
    int count2 = 0;
    int temp;
    int numarray[SIZE];              // master array
    int duplicateary[SIZE2];      // Duplicate array that is going to be sorted
    int gaparrayOne[GAP_SIZE];   // Gap array that holds the value for gaps with n/2
    int gapArrayTwo[GAP_SIZE];   // Gap array that holds the value for gaps with  2^K -1
    double start, End, Time;

    keeptrack forinsert;
    keeptrack forselection;
    keeptrack forshell1;
    keeptrack forshell2;
    keeptrack forquicksort;
    
    cout << "SIZE" << endl;  // asking user for the size of the array
    cin >> size;
    while (size <= 0 && size>100000) {
        cout << "SIZE" << endl;  // asking user for the size of the array
        cin >> size;
    }


    Zero(forinsert);
    Zero(forselection);
    Zero(forshell1);
    Zero(forshell2);
    Zero(forquicksort);
    for (int i = 0; i < size; i++) {    // loop that generates and stores the random numer for the given  size
        numarray[i] = rand();
        duplicateary[i] = numarray[i];
    }
    temp = size;

    do {
        temp = temp / 2;
        gaparrayOne[count] = temp;
        count++;
    }
    while ((count < 20) && (temp > 1));


    
    cout << "Divide by two has " << count << " gaps :" << endl;

    for (int i = 0; i < count; i++) {
    cout << gaparrayOne[i] << " ";      
    }
    cout << endl;


    
    temp = 1;
    while (temp < size ) {   // second gap value with 2^k -1
    temp = 2 * temp;
    gapArrayTwo[count2] = temp - 1;
    count2++;
    }

    for (int i = 0; i < count2 / 2; i++)
    {
    temp = gapArrayTwo[i];
    gapArrayTwo[i] = gapArrayTwo[count2 - 1 - i];
    gapArrayTwo[count2 - 1 - i] = temp;
    }
    cout << " 2^k -1 has " << count2 << " gaps" << endl;


    for (int i = 0; i < count2; i++) {       
        cout << gapArrayTwo[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < size; i++) {
        numarray[i] = duplicateary[i];
    }
    cout << setw(13) << left << "Sort" << setw(13) << left << "Time" << setw(13) << left << "Comps" << setw(13) << left << "Swaps" << endl;
   
    start = clock();
    insertionSort(duplicateary, size, forinsert);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC;
    cout << setw(13) << left << "Insertion" << setw(13) << left << Time << setw(13) << left << forinsert.comparisons << setw(13) << left << forinsert.swaps << endl;


    for (int i = 0; i < size; i++) {
        numarray[i] = duplicateary[i];
    }
    start = clock();
    selectionSort(duplicateary, size, forselection);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC;
    cout << setw(13) << left << "Selection" << setw(13) << left << Time << setw(13) << left << forselection.comparisons << setw(13) << left << forselection.swaps << endl;
    
    for (int i = 0; i < size; i++) {
        numarray[i] = duplicateary[i];
    }
    start = clock();
    shellSort( duplicateary, size, gaparrayOne,count, forshell1);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC;
    cout << setw(13) << left << "Shellsort1" << setw(13) << left << Time << setw(13) << left << forshell1.comparisons << setw(13) << left << forshell1.swaps << endl;

    for (int i = 0; i < size; i++) {
        numarray[i] = duplicateary[i];
    }
    start = clock();
    shellSort(duplicateary, size, gapArrayTwo, count2, forshell2);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC;
    cout << setw(13) << left << "Shellsort2" << setw(13) << left << Time << setw(13) << left << forshell2.comparisons << setw(13) << left << forshell2.swaps << endl;

    for (int i = 0; i < size; i++) {
        numarray[i] = duplicateary[i];
    }
    start = clock();
    quicksort(duplicateary, 0, size-1, forquicksort);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC;
    cout << setw(13) << left << "Quicksort" << setw(13) << left << Time << setw(13) << left << forquicksort.comparisons << setw(13) << left << forquicksort.swaps << endl;


    
    return 0;
}



void Zero(keeptrack& tracks) {
    tracks.comparisons = 0;
    tracks.swaps = 0;
}

void insertionSort(int duplicateary[], int numary, keeptrack& track) {
    int i = 0;
    int j = 0;
    int temp = 0; 
    for (i = 1; i < numary; ++i) {
        j = i;

        track.comparisons++;
        while (j > 0 && duplicateary[j] < duplicateary[j - 1]) {
            track.comparisons++;
            temp = duplicateary[j];
            duplicateary[j] = duplicateary[j - 1];
            duplicateary[j - 1] = temp;
            --j;
            track.swaps++;
        }
    }
}


void selectionSort(int duplicateary[], int numbersSize, keeptrack& track) {
    int     indexSmallest = 0;
    int  temp = 0;// Temporary variable for swap
    for (int i = 0; i <numbersSize-1; ++i) {
        // Find index of smallest remaining element
        indexSmallest = i;
        for (int j = i + 1; j < numbersSize; ++j) {
            track.comparisons++;
            if (duplicateary[j] < duplicateary[indexSmallest]) {
                
                indexSmallest = j;
                
            }
        }
        // Swap numbers[i] and numbers[indexSmallest]
        temp = duplicateary[i];
        duplicateary[i] = duplicateary[indexSmallest];
        duplicateary[indexSmallest] = temp;
        track.swaps++;
    }
}

void InsertionSortInterleaved(int duplicateary[], int  numbersSize, int startIndex, int gap, keeptrack& track) {
    int  i = 0;
    int  j = 0;
    int  temp = 0; // Temporary variable for swap

    for (i = startIndex + gap; i < numbersSize; i = i + gap) {
        j = i;
        track.comparisons++;
        while (j - gap >= startIndex && duplicateary[j] < duplicateary[j - gap]) {
            temp = duplicateary[j];
            duplicateary[j] = duplicateary[j - gap];
            duplicateary[j - gap] = temp;
            j = j - gap;
            track.swaps++;
        }
    }
}


void shellSort(int duplicateary[], int  numbersSize, int gapArr[], int gapSize, keeptrack& track) {
    int  gapValue;
    for (int i = 0; i < gapSize; ++i) {
        gapValue = gapArr[i];
        for (int j = 0; j < gapValue; j++) {
            InsertionSortInterleaved(duplicateary, numbersSize, j, gapValue, track);
        }
    }
}

int partition(int duplicateary[], int lowIndex, int highIndex, keeptrack& track) {

    int midPoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = duplicateary[midPoint];

    bool done = false;

    while (!done) {
        // Increment lowIndex while numbers[lowIndex] < pivot
        while (duplicateary[lowIndex] < pivot) {
             track.comparisons++;
            lowIndex += 1;
        }

        // Decrement highIndex while pivot < numbers[highIndex]
        while (pivot < duplicateary[highIndex]) {
            track.comparisons++;
            highIndex -= 1;
        }

        // If zero or one elements remain, then all numbers are
        // partitioned and return highIndex
        if (lowIndex >= highIndex) {
            track.comparisons++;
            done = true;
        }
        else {

            // Swap numbers[lowIndex] and numbers[highIndex]
            int temp = duplicateary[lowIndex];
            duplicateary[lowIndex] = duplicateary[highIndex];
            duplicateary[highIndex] = temp;
            track.swaps++;
            lowIndex += 1; // Increment lowIndex pointer
            highIndex -= 1; // Increment highIndex pointer
        }

    }

    return highIndex;
}

/*
The Function that calls partition function recursively and sorts the input array
*/
void quicksort(int duplicateary[], int lowIndex, int highIndex, keeptrack& track) {
    // Base Case: If partition size is zero or 1 elements, then the partition is already sorted
    if (lowIndex >= highIndex) {
        return;
    }
    else {

        // Partition the input array around pivot
        int pivot = partition(duplicateary, lowIndex, highIndex,track);


        // Recursively call quickSort on left half and right half
        quicksort(duplicateary, lowIndex, pivot, track);
        quicksort(duplicateary, pivot + 1, highIndex,track);
    }
}
