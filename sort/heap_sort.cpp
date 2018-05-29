#include <algorithm>
#include <iostream>
#include <vector>

class MaxHeap
{
    //helper function for heap sort
    inline int get_lchild_index(int parent_index)
    {
        //return (parent_index << 1) + 1;
        return parent_index * 2 + 1;
    }

    //helper function for heap sort
    inline int get_rchild_index(int parent_index)
    {
        //return parent_index + 1 << 1;
        return parent_index * 2 + 2;
    }

    //helper function for heap sort
    inline int get_parent_index(int child_index)
    {
        //return (child_index - 1) >> 1;
        return (child_index - 1) / 2;
    }

    //helper function for heap sort
    inline bool has_lchild(int index)
    {
        return get_lchild_index(index) < arr.size();
    }

    //helper function for heap sort
    inline bool has_rchild(int index)
    {
        return get_rchild_index(index) < arr.size();
    }

    //helper function for heap sort
    inline bool has_parent(int index)
    {
        return get_parent_index(index) >= 0;
    }

    //helper function for heap sort
    inline int get_lchild(int index)
    {
        return arr[get_lchild_index(index)];
    }

    //helper function for heap sort
    inline int get_rchild(int index)
    {
        return arr[get_rchild_index(index)];
    }

    //helper function for heap sort
    inline int get_parent(int index)
    {
        return arr[get_parent_index(index)];
    }


    std::vector<int> arr;

    //bubble the last element up
    void percolate_up()
    {
        int index = arr.size() - 1;
        while(has_parent(index))
        {
            int p_index = get_parent_index(index);
            if(arr[p_index] < arr[index])
            {
                std::swap(arr[p_index], arr[index]);
                index = p_index;
                continue;
            }
            return;
        }
    }

    //bubble the element down
    //not necessarily the root element
    void percolate_down(int hole)
    {
        //if a node doesnt have lchild
        //certainly wont have rchild
        while(has_lchild(hole))
        {
            //hole has 2 children
            if(has_rchild(hole))
            {
                int lchild_index = get_lchild_index(hole);
                int rchild_index = get_rchild_index(hole);
                int max_index = hole;

                if(arr[lchild_index] > arr[max_index])
                    max_index = lchild_index;

                if(arr[rchild_index] > arr[max_index])
                    max_index = rchild_index;

                if(max_index != hole)
                {
                    std::swap(arr[max_index], arr[hole]);
                    hole = max_index;
                    continue;
                }
                return;
            }
            //hole only has left child
            else
            {
                int lchild_index = get_lchild_index(hole);
                if (arr[lchild_index] > arr[hole])
                {
                    std::swap(arr[lchild_index], arr[hole]);  
                    hole = lchild_index;
                    continue;
                } 
                return;
            }
        }
    }

    void build_heap()
    {
        for(int i = arr.size() / 2 - 1; i >= 0; i--)
            percolate_down(i);
    }

public:

    MaxHeap(std::vector<int> &arr):arr(arr)
    {
        build_heap();
    }

    void printArr()
    {
        int index = 0;
        int row_num = 1;
        while (index < arr.size())
        {
            for (int i = 0; i < row_num; i++)
            {
                if (i + row_num >= arr.size())
                {
                    std::cout << std::endl;
                    return;
                }
                std::cout << arr[index + i] << " ";
            }
            std::cout << std::endl;
            index += row_num;
            row_num <<= 1;
        }
    }

    int delete_max()
    {
        if(arr.empty()) throw std::overflow_error("arr is empty");
        int max = arr.front();
        std::swap(arr.front(), arr.back());
        arr.pop_back();
        percolate_down(0);
        return max;
    }

    void insert(int value)
    {
        arr.push_back(value);
        int index = arr.size() - 1;
        //percolate up
        percolate_up();
    }

    void sort()
    {
        std::vector<int> temp(arr.size());
        for(int i = 0; i < temp.size(); i++)
            temp[i] = delete_max();
        arr = temp;
    }
};

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::vector<int> maxheap(arr, arr + sizeof(arr) / sizeof(int));
    MaxHeap maxH(maxheap);
    maxH.sort();
    maxH.printArr();
}