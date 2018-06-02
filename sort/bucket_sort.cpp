#include <vector>
#include <iostream>
#include <algorithm>








void insertion_sort(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int j = i - 1;
        int key = arr[i];
        while(j >=0 && key <= arr[j])
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
       // for(int j = 0; j < i; j++)
       // {
       //     if(arr[i] < arr[j])
       //     {
       //         int temp = arr[i];
       //         for(int k = j; k < i; k++)
       //         {
       //             arr[k+1] = arr[k];
       //         }
       //         arr[j] = temp;
       //         break;
       //     }
       // }
    }
}

void bucket_sort(std::vector<int> &arr)
{
    int n = arr.size();
    int max = *std::max_element(arr.begin(), arr.end());
    std::vector<std::vector<int> > buckets(n);
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] / (float) max * (n - 1);
        buckets.at(index).push_back(arr[i]);
    }

    for(int i = 0; i < buckets.size(); i++)
        insertion_sort(buckets[i]);

    arr.clear();

    for(int i = 0; i < buckets.size(); i++)
    {
        if(buckets[i].empty())
            continue;
        
        for(int j = 0; j < buckets[i].size(); j++)
            arr.push_back(buckets[i][j]);
    }


    
}

void print_arr(const std::vector<int> &arr)
{
    for(auto n : arr)
        std::cout << n << " ";
    std::cout << std::endl;
}
int main()
{
    int test[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::vector<int> arr(test, test + sizeof(test) / sizeof(int));
    bucket_sort(arr);
    print_arr(arr);
}