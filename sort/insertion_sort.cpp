#include <vector>
#include <iostream>

//sort array ascending

void displayArr(const std::vector<int> &arr)
{
    for(auto n : arr)
        std::cout << n << " ";
    std::cout << std::endl;  
}

//first version
void insertionSort1(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        //compare ith element with
        //sorted partial arr one by one
        
        //improve:
        //we dont need to compare elements 
        //one by one, just simply move elements
        //which is less or greater than arr[i]
        //to right by one position
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

/*
template< class BidirIt1, class BidirIt2 >
BidirIt2 move_backward(BidirIt1 first,
                                     BidirIt1 last,
                                     BidirIt2 d_last)
{
    while (first != last) {
        *(--d_last) = std::move(*(--last));
    }
    return d_last;
}
*/

void insertionSort2(std::vector<int> &arr)
{
   for(int i = 0; i < arr.size(); i++)  
   {
       for(int j = 0; j < i; j++)
       {
           if(arr[i] < arr[j])
           {
               //cpp standard library implementaiton
               //*****
               int temp = arr[i];
               int d_last = j + 1;
               int first = j;
               while(j != i)
                   arr[d_last++] = arr[j++];
                
                arr[first] = temp;
               //******
                break;

           }
       }
           displayArr(arr);
   }
}

void insertionSort(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++) 
    {
        int  key, j;
        j = i - 1;
        key = arr[i];

        while(j >=0 && key <= arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        displayArr(arr);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77};
    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    //time complexity  O(n^2)
    insertionSort(test);
}