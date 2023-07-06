#include <cstdlib>  // For dynamic memory management

class CVector
{
private:
    void** m_pVect;             // Pointer to the buffer
    int m_nCount;               // Control how many elements are actually used
    int m_nMax;                 // Control the number of allocated elements
    int m_nDelta;               // To control the growing
    int m_nElemSize;            // Element size
    int (*m_lpfnCompare)(void*, void*); // Pointer to the function to compare

    void Init(int delta);       // Init our private variables, etc
    void Resize();              // Resize the vector when an overflow occurs

public:
    CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta = 10); // Constructor
    ~CVector();                 // Destructor
    void Insert(void* elem);    // Insert a new element
    // More methods go here
};

CVector::CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta)
{
    m_lpfnCompare = lpfnCompare;
    m_nElemSize = nElemSize;
    m_nDelta = delta;

    Init(delta);
}

CVector::~CVector()
{
    for (int i = 0; i < m_nCount; i++)
    {
        free(m_pVect[i]); // Free individual elements
    }

    free(m_pVect); // Free the buffer
}

void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;

    // Allocate memory for the buffer
    m_pVect = (void**)malloc(m_nMax * sizeof(void*));
}

void CVector::Resize()
{
    m_nMax += m_nDelta;
    m_pVect = (void**)realloc(m_pVect, m_nMax * sizeof(void*));
}

void CVector::Insert(void* elem)
{
    // Check if the buffer needs to be resized
    if (m_nCount == m_nMax)
    {
        Resize();
    }

    // Allocate memory for the new element
    m_pVect[m_nCount] = malloc(m_nElemSize);

    // Copy the element to the buffer
    memcpy(m_pVect[m_nCount], elem, m_nElemSize);

    m_nCount++;
}

// More method implementations can be added here

int main()
{
    // Example usage of the CVector class

    // Comparison function
    int CompareInts(void* a, void* b)
    {
        int* pa = (int*)a;
        int* pb = (int*)b;

        return (*pa - *pb);
    }

    CVector intVector(CompareInts, sizeof(int));

    int a = 10;
    int b = 20;
    int c = 30;

    intVector.Insert(&a);
    intVector.Insert(&b);
    intVector.Insert(&c);

    return 0;
}
