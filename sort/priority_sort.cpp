#include <queue>
#include <iostream>
#include <algorithm>



int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::priority_queue<int> ipq(arr, arr+ sizeof(arr) / sizeof(int));

    std::cout << ipq.size() << std::endl;

   // for (int i = 0; i < ipq.size(); i++)
   //     std::cout << ipq.top() << std::endl;
    
    //while(!ipq.empty())
    //{
    //    std::cout << ipq.top() << std::endl;
    //    ipq.pop();
    //}

    //std::cout << std::endl;


    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    std::make_heap(test.begin(), test.end());

    for(auto n : test)
    {
        std::cout << n << std::endl;
    }


}