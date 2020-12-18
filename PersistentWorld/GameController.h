#pragma once
#include <map>

class GameController
{
private:
    std::map<int, Planet> planets;
    int current_planet_id;
    int world_capacity;

    int get_number_in_range(int low = 1, int high = 10)
    {
        return low + (std::rand() % (high - low + 1));
    }

public:

    // init new game here
    GameController()
    {
        planets = std::map<int, Planet>();
        current_planet_id = 1;
        world_capacity = 1;

        planets.insert(std::pair<int, Planet>(current_planet_id, Planet(current_planet_id)));
    }

    void travel_infinitely()
    {
        int number_of_travels = 1;
        char key;

        while (true)
        {
            // moving crew between planets
            move_to_another_planet();

            if (number_of_travels++ % 5 == 0)
            {
                // tmp
                break;

                std::cout << "Already " << number_of_travels << " travels were made in this game. Want to stop travelling? [Y]" << std::endl;
                std::cin >> key;

                if (key == 'y' || key == 'Y')
                {
                    break;
                }
            }
        }
    }

    void move_to_another_planet()
    {
        int destination = get_number_in_range();
        while (destination == current_planet_id)
        {
            destination = get_number_in_range();
        }

        if (destination > world_capacity) // new planet generated
        {
            std::cout << "Generating new planet with id '" << world_capacity + 1 << "'!" << std::endl;

            planets[current_planet_id].add_portal(world_capacity + 1);

            world_capacity++;
            planets.insert(std::pair<int, Planet>(world_capacity, Planet(world_capacity)));

            current_planet_id = world_capacity;
        }
        else // moving to existed planet
        {
            planets[current_planet_id].add_portal(destination);
            current_planet_id = destination;

            std::cout << "Moved to planet '" << current_planet_id << "'!" << std::endl;
        }
    }
};

