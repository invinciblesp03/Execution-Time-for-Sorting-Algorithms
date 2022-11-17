#include<iostream>
#include<ctime>
#include <iomanip>

using namespace std;

//structure with swaps and comparisons
struct keeptrack {
    long long swaps;
    long long comparisons;
};


//Function prototypes for the sorting algorithms 
int insertionSort(int, int, keeptrack);


//initializing the comparisons and swaps to zero
void StructIni(keeptrack& Shree) {
    Shree.comparisons = 0;
    Shree.swaps = 0;
}

// insertion sort algorithm
int insertionSort(int duplicateary, int numary, keeptrack& Shree) {
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap

    for (i = 1; i < duplicateary; ++i) {
        j = i;

        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position

        while (j > 0 && duplicateary[j] < numary[j - 1]) {
            Shree.comparisons++;
            // Swap numbers[j] and numbers[j - 1]
            Shree.swaps++;
            temp = numary[j];
            duplicateary[j] = duplicateary[j - 1];
            duplicateary[j - 1] = temp;
            --j;
        }
    }
}

// Declaration of the global constants
const int SIZE = 100000;
const int GAP_SIZE = 20;


int main() {

    int numary;                   // number elements to be sorted int he array
    int numGaps = 0;
    int temp;
    int count = 0;
    int numarray[SIZE];          // master array
    int duplicateAry[SIZE];      // Duplicate array that is going to be sorted
    int gaparrayOne[GAP_SIZE];   // Gap array that holds the value for gaps with n/2
    int gapArrayTwo[GAP_SIZE];   // Gap array that holds the value for gaps with  2^K -1
    double start, End, Time;  
    keeptrack Shree;

    
    cout << "SIZE" << endl;  // asking user for the size of the array
    cin >> numary; 
    for (int i = 0; i < numary; i++) {    // loop that generates and stores the random numer for the given  size
    numarray[i] = rand();
    duplicateAry[i] = numarray[i];
    }
    temp = numary;
   
                                       

    do {                                     //first gap value when divided by two as an array of gaparrayone[]
    temp = temp / 2;
    gaparrayOne[count] = temp;
    count++;
    // cout << gaparrayOne[count] << " ";
    // cout << temp<<" ";
    } while ((count < 20) && (temp > 1));

    cout << setw(13) << left << "Sort" << setw(13) << left << "Time" << setw(13) << left << "Comps" << setw(13) << left << "Swaps" << endl;
    cout << "Divide by two       has "<<count<<" gaps :" << endl;
 
    for (int i = 0; i < count; i++) {
    cout << gaparrayOne[i] << " ";      // Pritning out the gap array one
    }
    //second gap value with (2^k -1) as an array of gaparraytwo[]
    cout << endl;
    
    count = 0;
   temp = 1;
   while ((count < 20) && (temp * 2 < numary)) {  // second gap value with 2^k -1
       
    temp = 2 * temp;
    gapArrayTwo[count] = temp - 1;
    count++;            
    } 
    
    for (int i = 0; i < count/2; i++)
    {
     temp = gapArrayTwo[i];
     gapArrayTwo[i] = gapArrayTwo[count -1 -i];
     gapArrayTwo[count - 1 - i] = temp;
    }
    cout << " 2^k -1 has " << count << " gaps" << endl;

  
    for (int i = 0; i < count; i++) {       // Printing out out the gap array two
    cout << gapArrayTwo[i] << " ";
    }
    cout << endl;
    
    //output the table header with correct format
    
    StructIni(Shree);
    start = clock();
    insertionSort(duplicateAry, numary, Shree);
    End = clock();
    Time = (End - start) / CLOCKS_PER_SEC * 1.0;
     
    cout << setw(13) << left << "Sort" << setw(13) << left << "Time" << setw(13) << left << "Comps" << setw(13) << left << "Swaps" << endl;
    //output with format

    //initialize everythin
    //call sort
    //calculate values
    //print outpout with format


    //initialize everythin
    //call sort
    //calculate values
    //print outpout with format



    return 0;
}

