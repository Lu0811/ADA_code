#include <cstdlib>
#include <cstring>

class CVector {
private:
    void** m_pVect;                 // Pointer to the buffer
    int m_nCount;                   // Control how many elements are actually used
    int m_nMax;                     // Control the number of allocated elements
    int m_nDelta;                   // To control the growing
    int m_nElemSize;                // Element size
    int (*m_lpfnCompare)(void*, void*); // Pointer to the function to compare

    void Init(int delta);           // Init our private variables, etc
    void Resize();                  // Resize the vector when an overflow occurs
    void* DupBlock(void* pElem);    // Duplicate the memory block for user types

public:
    CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta = 10); // Constructor
    ~CVector();                     // Destructor
    void Insert(void* pElem);       // Insert a new element
    // More methods go here
};

CVector::CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta) {
    Init(delta);
    m_lpfnCompare = lpfnCompare;
    m_nElemSize = nElemSize;
}

CVector::~CVector() {
    for (int i = 0; i < m_nCount; i++) {
        delete[] static_cast<char*>(m_pVect[i]); // Free individual elements
    }
    free(m_pVect); // Free the buffer
}

void CVector::Init(int delta) {
    m_nCount = 0;
    m_nMax = delta;
    // Allocate memory for the buffer
    m_pVect = static_cast<void**>(malloc(m_nMax * sizeof(void*)));
}

void CVector::Resize() {
    m_nMax += m_nDelta;
    m_pVect = static_cast<void**>(realloc(m_pVect, m_nMax * sizeof(void*)));
}

void* CVector::DupBlock(void* pElem) {
    void* p = new char[m_nElemSize];
    return memcpy(p, pElem, m_nElemSize);
}

void CVector::Insert(void* pElem) {
    // Check if the buffer needs to be resized
    if (m_nCount == m_nMax) {
        Resize();
    }
    // Duplicate the memory block for the user type
    m_pVect[m_nCount++] = DupBlock(pElem);
}

// More method implementations can be added here

int main() {
    // Example usage of the CVector class

    // Comparison function for strings
    int CompareStrings(void* a, void* b) {
        char* pa = static_cast<char*>(a);
        char* pb = static_cast<char*>(b);
        return strcmp(pa, pb);
    }

    CVector strVector(CompareStrings, sizeof(char*));

    char* str1 = "Hello";
    char* str2 = "World";
    char* str3 = "C++";

    strVector.Insert(&str1);
    strVector.Insert(&str2);
    strVector.Insert(&str3);

    return 0;
}
