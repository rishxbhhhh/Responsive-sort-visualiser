// Sorting programs used:
// 1->Selection sort
// 2->Bubble sort
// 3->Insertion sort
// 4->Quicksort
// 5->Merge sort
// 6->Radix sort
// 7->Count sort

#include <iostream>
#include <chrono>  /// for calculating time duration of algos
#include <iomanip> /// for setting a decent looking output
#define max 1000000
using namespace std::chrono;
using namespace std;

void fill(int X1[], int X2[], int X3[], int X4[], int X5[], int X6[], int X7[], int n)
{
    for (int t = 0; t < n; t++)
    {
        X1[t] = rand() % max + 1;
        X2[t] = X1[t];
        X3[t] = X1[t];
        X4[t] = X1[t];
        X5[t] = X1[t];
        X6[t] = X1[t];
        X7[t] = X1[t];
    }
}

void display(string name, int X[], int n)
{
    cout << endl
         << "After " << name << " sort -->";
    for (int t = 0; t < n; t++)
    {
        if (t % 10 == 0)
            cout << endl;
        cout << setw(10) << setfill(' ') << X[t] << "  ";
    }
    cout << endl;
}

//------------------------------------------------------------------------------------------------------------------------BUBBLE SORT
void bubblesort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------SELECTION SORT
void selectionsort(int A[], int n)
{
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(A[min], A[i]);
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------INSERTION SORT
void insertionsort(int A[], int n)
{
    int i = 0, j = 0, key = 0, keyindex = 0;
    for (j = 1; j < n; j++)
    {
        key = A[j];
        keyindex = j;
        i = j - 1;
        while ((i >= 0) && (A[i] > key))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        if (keyindex != i + 1)
        {
            A[i + 1] = key;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------QUICK SORT
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void quicksort(int A[], int p, int r)
{
    if (p < r)
    {
        int q;
        q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

//------------------------------------------------------------------------------------------------------------------------MERGE SORT
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        int div = begin + (end - begin) / 2;
        mergesort(arr, begin, div);
        mergesort(arr, div + 1, end);
        merge(arr, begin, div, end);
    }
}

//------------------------------------------------------------------------------------------------------------------------RADIX SORT
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countforradixsort(int array[], int size, int place)
{
    const int maxl = 10;
    int output[size];
    int count[maxl];

    for (int i = 0; i < maxl; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < maxl; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int array[], int size)
{
    // Get maximum element
    int maxv = getMax(array, size);

    for (int place = 1; maxv / place > 0; place *= 10)
        countforradixsort(array, size, place);
}

//------------------------------------------------------------------------------------------------------------------------COUNT SORT
int max_el(int *a, int n)
{
    int m = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m + 1;
}

void countsort(int *a, int n)
{
    int maxim = max_el(a, n);
    int tally[maxim], temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
    for (int i = 0; i < maxim; i++)
    {
        tally[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        tally[temp[i] % maxim]++;
    }
    int sum = 0;
    for (int i = 0; i < maxim; i++)
    {
        sum += tally[i];
        tally[i] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        a[--tally[temp[i]]] = temp[i];
    }
}

int main()
{
    cout << "Sorting Analysis _>" << endl;

    int n = 0;
    cout << "-------------------\nInput n_> ";
    cin >> n;
    int a[n], b[n], c[n], d[n], e[n], f[n], g[n];
    fill(a, b, c, d, e, f, g, n);

    time_point<steady_clock>
        start[7], stop[7];

    start[0] = steady_clock::now();
    selectionsort(a, n);
    stop[0] = steady_clock::now();

    start[1] = steady_clock::now();
    bubblesort(b, n);
    stop[1] = steady_clock::now();

    start[2] = steady_clock::now();
    insertionsort(c, n);
    stop[2] = steady_clock::now();

    start[3] = steady_clock::now();
    quicksort(d, 0, n - 1);
    stop[3] = steady_clock::now();

    start[4] = steady_clock::now();
    mergesort(e, 0, n - 1);
    stop[4] = steady_clock::now();

    start[5] = steady_clock::now();
    radixsort(f, n);
    stop[5] = steady_clock::now();

    start[6] = steady_clock::now();
    countsort(g, n);
    stop[6] = steady_clock::now();

    auto duration1 = duration_cast<microseconds>(stop[0] - start[0]);
    auto duration2 = duration_cast<microseconds>(stop[1] - start[1]);
    auto duration3 = duration_cast<microseconds>(stop[2] - start[2]);
    auto duration4 = duration_cast<microseconds>(stop[3] - start[3]);
    auto duration5 = duration_cast<microseconds>(stop[4] - start[4]);
    auto duration6 = duration_cast<microseconds>(stop[5] - start[5]);
    auto duration7 = duration_cast<microseconds>(stop[6] - start[6]);

    //display(" ", c, n);
    cout << endl
         << endl
         << "Selection Sort "
         << "Duration_> " << setw(10) << setfill(' ') << duration1.count() << " micro s" << endl
         << "Bubble Sort    "
         << "Duration_> " << setw(10) << setfill(' ') << duration2.count() << " micro s" << endl
         << "Insertion Sort "
         << "Duration_> " << setw(10) << setfill(' ') << duration3.count() << " micro s" << endl
         << "Quick Sort     "
         << "Duration_> " << setw(10) << setfill(' ') << duration4.count() << " micro s" << endl
         << "Merge Sort     "
         << "Duration_> " << setw(10) << setfill(' ') << duration5.count() << " micro s" << endl
         << "Radix Sort     "
         << "Duration_> " << setw(10) << setfill(' ') << duration6.count() << " micro s" << endl
         << "Count Sort     "
         << "Duration_> " << setw(10) << setfill(' ') << duration7.count() << " micro s" << endl;

    //system("pause");
    return 0;
}