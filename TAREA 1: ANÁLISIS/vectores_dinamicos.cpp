#include <iostream>
#include <vector>

using namespace std;

// vector dinámico
int *dynamicArray = nullptr;
int elementCount = 0;
int maxSize = 0;

void resizeArray() {
    const int delta = 10;
    
    int *tempArray, i;
    tempArray = new int[maxSize + delta];
    for (i = 0; i < maxSize; i++)
        tempArray[i] = dynamicArray[i];
    delete [] dynamicArray;
    dynamicArray = tempArray;

    maxSize += delta;
}

void insertElement(int elem) {
    if (elementCount == maxSize)
        resizeArray();
    dynamicArray[elementCount++] = elem;
}


int main() {

    insertElement(6);
    insertElement(7);

    for (int i = 0; i < elementCount; i++) {
        cout << dynamicArray[i] << " ";
    }

    return 0;
}
