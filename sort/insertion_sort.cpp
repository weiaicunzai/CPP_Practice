#include <vector>
#include <iostream>

//sort array ascending

void displayArr(const std::vector<int> &arr)
{
    for(auto n : arr)
        std::cout << n << " ";
    std::cout << std::endl;  
}

void insertionSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        //compare ith element with
        //sorted partial arr one by one
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                //insert arr[i] in front of arr[j]
                //then move all remain element to right
                int temp = arr[i];
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
                break;
            }
        }
        displayArr(arr);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77};
    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    insertionSort(test);
}