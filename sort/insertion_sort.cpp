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

//similar  to  the stl implementation version
/*
    gcc version implementation:
    bits/stl_algo.h

  template<typename _RandomAccessIterator, typename _Compare>
    void
    __insertion_sort(_RandomAccessIterator __first,
		     _RandomAccessIterator __last, _Compare __comp)
    {
      if (__first == __last) return;

      for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i)
	{
    
      //key value is less than the first element of the sorted sub array
      //then move all the element one postion to the left

	  if (__comp(__i, __first))
	    {
	      typename iterator_traits<_RandomAccessIterator>::value_type
		__val = _GLIBCXX_MOVE(*__i);
	      _GLIBCXX_MOVE_BACKWARD3(__first, __i, __i + 1);
	      *__first = _GLIBCXX_MOVE(__val);
	    }
	  else
	    std::__unguarded_linear_insert(__i,
				__gnu_cxx::__ops::__val_comp_iter(__comp));
	}
}
*/


//final version
void insertionSort(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++) 
    {
        int  key, j;
        j = i - 1;
        key = arr[i];


        //arr[0] is the smallest
        //in sorted array, then move
        //all sorted array one position
        //to the left, no other operations
        if(key < arr[0])
        {
            while(j >= 0)
                arr[j + 1] = arr[j--];

            arr[0] = key;
            displayArr(arr);
            continue;
        }


        //if not, we do the regular insertion_sort
        while(j >=0 && key <= arr[j])
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
        displayArr(arr);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    //time complexity  O(n^2)
    insertionSort(test);
}