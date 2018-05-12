#include <vector>
#include <iostream>
#include <algorithm>


void printArr(std::vector<int> &arr)
{
    for(auto n : arr)
        std::cout << n << " ";
    std::cout << std::endl;
}

int partition(std::vector<int> &arr, int low, int height, int pivot)
{
    int key = arr[pivot];
    while(low <= height)
    {
        while(arr[low] <= key)
            low++;
        while(arr[height] >= key)
            height--;
        
        if(low <= height)
        {
            std::swap(arr[low], arr[height]);
            //int temp = arr[low];
            //arr[low] = arr[height];
            //arr[height] = temp;
            low++;
            height--;
        }
    }
    return low;
}

void quickSort(std::vector<int> &arr, int low, int height)
{
    if(low >= height) return;
    int pivot = (low + height) / 2;
    int index = partition(arr, low, height, pivot);
    printArr(arr);
    quickSort(arr, low, index - 1);
    quickSort(arr, index, height);
}

void quickSort(std::vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}






int parition1(std::vector<int> &arr, int low, int height)
{
    int pivot_index = low;
    int key = arr[pivot_index];
    while(low <= height)
    {
        //while(arr[low] <= key)
        //cant write <= 
        //otherwise we mind sikp
        //the pivot and continue
        //move to the right
        //pivot = arr[0]
        //arr = {13, 12, 3, 4, 6, 7}
        //>= makes low stops and 7
        //> makes low stops and 13
        //which is what we want
        while(arr[low] < key)
            low++;
        
        //while(arr[height] >= key)
        while(arr[height] > key)
            height--;
        
        //if(arr[low] > arr[height])
        // we nned to stop at low = height
        // if we write code like arr[low] > arr[height]
        // the program will continue to execute
        // even when low > height
        if(low <= height)
            std::swap(arr[low++], arr[height--]);
    }
    return low;
}
void quickSort1(std::vector<int> &arr, int low, int height)
{
    // arr will always = 19
    //if(arr.size() <= 1) return;
    if(low >= height) return;
    int index = parition1(arr, low, height);
    printArr(arr);
    quickSort1(arr, low, index - 1);
    quickSort1(arr, index, height);
}

void quickSort1(std::vector<int> &arr)
{
    quickSort1(arr, 0, arr.size() - 1);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    quickSort1(test);
    printArr(test);
}