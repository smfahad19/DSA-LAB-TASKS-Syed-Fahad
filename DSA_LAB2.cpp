// Lab 2 - Big O Notation (Loops and Arrays)

#include <iostream>
using namespace std;

void findMax(int arr[], int size) {  
    int maxVal = arr[0];  
    for (int i = 1; i < size; i++) {  
        if (arr[i] > maxVal) {  
            maxVal = arr[i];  
        }  
    }  
    cout << "maximum value " << maxVal << endl;  
}

int main() {  
    int arr[5] = {3, 4, 6, 8, 5};  
    int size = 5;  

    findMax(arr, size);  

    return 0;  
}

// Time Complexity:
    // The time complexity of this program is O(n)
    //The program checks each number in the array once. If there are n numbers, the loop runs n times. In Big O, we ignore small details example: constant- 1, so it's O(n) because the time grows with the array size: