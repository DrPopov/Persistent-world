#pragma once


class SerializationHelper
{
private:
    std::string path_to_save = "saved_game.json";

public:
    SerializationHelper() {}

    void SerializeAndSave(GameController game_controller)
    {
        auto ser = nop::Serializer<GameController>();
        auto res = ser.Write(game_controller);
    }
};

