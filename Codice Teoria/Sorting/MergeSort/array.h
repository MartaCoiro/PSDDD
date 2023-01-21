void selectionSort(int *a, const int n);
int minimo(int *a, const int n);
void inputArray(int *arr, const int n);
void insertionSort(int *arr, int n);
void insertSortedArray(int *arr, int val, int *n);
void outputArray(int *a, int n);
int bubbleSort (int *a, int n);
int adaptiveBubbleSort (int *a, int n);
void deletePos(int* a,int *n,int pos);
int searchSort(int *a,int n,int ele);
int searchBin(int *a,int n,int ele);
/**
 * @param a array a
 * @param n taglia dell'array
 */
void mergeSort(int *a,int n);
/**

 * @param a1 primo sottoarrayy
 * @param a2 secondo sottoarray
 * @param n1 taglia di a1
 * @param n2 taglia di a2
 * @param a array contentente a1+a2
 */
void merge(int *a1,int *a2,int n1,int n2,int *a);
