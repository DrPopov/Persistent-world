#pragma once
#include <algorithm>
#include <set>
#include <string>
#include <vector>

class Planet
{
private:
    int id;
    std::set<int> portals_to;
public:
    Planet()
    {
        id = 0;
    }

    Planet(int id)
    {
        this->portals_to = std::set<int>();
        this->id = id;
    }

    void add_portal(int planet_id)
    {
        if (portals_to.find(planet_id) == portals_to.end()) 
        {
            std::cout << "Connecting planet id='" << planet_id << "' to planet id='" << id << "'" << std::endl;
            portals_to.insert(planet_id);
        }
    }
};

