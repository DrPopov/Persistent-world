#include <iostream>

#include "Planet.h"
#include "GameController.h"
#include "SerializationHelper.h"

GameController game_controller;
SerializationHelper serializer;

int main()
{
    serializer = SerializationHelper();
    game_controller = GameController();

    std::cout << "Hello! Starting application..." << std::endl;
    std::cout << "Searching for saved game in .json ..." << std::endl;

    // add deserialization

    std::cout << "Did not find saved game. Starting new!" << std::endl;

    game_controller.travel_infinitely();

    std::cout << "Exited game. Saving world..." << std::endl;

    // add serialization
    serializer.SerializeAndSave(game_controller);
}
