#include <vector>
#include <iostream>



class Crossing
{
    public:
    int turn1;
    int turn2;
    int turn3;
    Crossing(int turn1, int turn2, int turn3)
    {
        this->turn1 = turn1;
        this->turn2 = turn2;
        this->turn3 = turn3;
    }
};



class Maze
{
    private:
    int exit;
    std::vector<Crossing> crossings;
    std::vector<int> result;

public:
    Maze(int exit, std::vector<Crossing> the_crossings)
    {
        this->exit = exit;
        this->crossings = the_crossings;
    }

    bool findMaze(int entrance);
    void getResult();
};

bool Maze::findMaze(int entrance)
{
    if(entrance > 0)
    {
        if(entrance == this->exit)
        {
            //only push when return true
            result.push_back(entrance);
            return true;
        }

        if(findMaze(this->crossings[entrance].turn1))
        {
            result.push_back(entrance);
            return true;
        }

        if(findMaze(this->crossings[entrance].turn2))
        {
            result.push_back(entrance);
            return true;
        }

        if(findMaze(this->crossings[entrance].turn3))
        {
            result.push_back(entrance);
            return true;
        }

    }
    return false;

}

void Maze::getResult()
{
    findMaze(1);

    for(auto n : result)
    {
        std::cout << n << std::endl;
    }
}

int main()
{
    Crossing c1(2, 0, 0);
    Crossing c2(4, 0, 0);
    Crossing c3(0, 0, 0);
    Crossing c4(3, 5, 0);
    Crossing c5(6, 0, 0);
    Crossing c6(7, 0, 0);
    Crossing c7(8, 9, 0);
    Crossing c8(0, 0, 0);
    Crossing c9(10, 0, 0);
    Crossing c0(0, 0, 0);

    std::vector<Crossing> crossing;
    crossing.push_back(c0);
    crossing.push_back(c1);
    crossing.push_back(c2);
    crossing.push_back(c3);
    crossing.push_back(c4);
    crossing.push_back(c5);
    crossing.push_back(c6);
    crossing.push_back(c7);
    crossing.push_back(c8);
    crossing.push_back(c9);

    Maze maze(10, crossing);
    maze.getResult();
    
}