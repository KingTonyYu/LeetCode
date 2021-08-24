class Solution {
private:
    const int obstacle_value_ = -1;
    const int unknown_value_ = numeric_limits<int>::max();
    const int gate_value_ = 0;
    const vector<pair<int, int>> direction_ = 
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        queue<pair<int, int>> active_loc;
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == gate_value_)
                {
                    active_loc.emplace(i, j);
                }
            }
        }

        int counter = 1;

        while (!active_loc.empty())
        {
            for (size_t num = active_loc.size(); num > 0; num--)
            {
                auto loc = active_loc.front();
                active_loc.pop();

                
                for (const auto& direct : direction_)
                {
                    int i = loc.first + direct.first;
                    int j = loc.second + direct.second;

                    if (isValid(i, j, m, n) && !isObstacle(i, j, rooms) && !isVisited(i, j, rooms))
                    {
                        rooms[i][j] = counter;
                        active_loc.emplace(i, j);
                    }
                }
            }
            counter++;
        }
                        
    }

    inline bool isValid(int i, int j, int m, int n) const
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    inline bool isObstacle(int i, int j, vector<vector<int>>& rooms) const
    {
        return rooms[i][j] == obstacle_value_;
    }  
    inline bool isVisited(int i, int j, vector<vector<int>>& rooms) const
    {
        return rooms[i][j] != unknown_value_;
    }  
};