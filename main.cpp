/*Write a program that dynamically resize an array to a bigger size. The program creates 
an array of an arbitrary size (specified by the user). Then the user may extend the array 
to a bigger size (this involves creating a temporary array with larger size, copying the 
values of the elements, and adding new values into the extension cells). Print the new 
array to the user to confirm the functionality.*/

#include <iostream>

// Function to resize the array dynamically
int* resizeArray(int* oldArray, int oldSize, int newSize) {
    // Allocate memory for the new array with the specified newSize
    int *newArray = new int[newSize];
   
    // Copy elements from the old array to the new array
    for (int i = 0; i < oldSize; ++i) {
        newArray[i] = oldArray[i];
    }

    // Initialize new elements in the extended part of the array
    for (int i = oldSize; i < newSize; ++i) {
        std::cout << "Enter a new value for element " << i << ": ";
        std::cin >> newArray[i];
    }

    // Deallocate memory for the old array
    delete[] oldArray;

    return newArray;
}

int main() {
    int* array = nullptr;
    int size, newSize;

    // Prompt the user to enter the initial size of the array
    std::cout << "Enter the initial size of the array: ";
    std::cin >> size;

    // Allocate memory for the initial array with the size inputted by the user
    array = new int[size];

    // Prompt the user to enter values for the initial array
    std::cout << "Enter values for the initial array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": ";
        std::cin >> array[i];
    }

    // Prompt the user to enter the new size of the array
    std::cout << "Enter the new size of the array (must be greater than the current size): ";
    std::cin >> newSize;

    if (newSize <= size) {
        std::cout << "New size must be greater than the current size." << std::endl;
    } else {
        // Call the resizeArray function to resize the array
        int* resizedArray = resizeArray(array, size, newSize);

        // Print the resized array
        std::cout << "Array after resizing to size " << newSize << ":" << std::endl;
        for (int i = 0; i < newSize; ++i) {
            std::cout << "Element " << i << ": " << resizedArray[i] << std::endl;
        }

        // Deallocate memory for the resized array
        delete[] resizedArray;
    }

    return 0;
}