#pragma once

#include <SFML/System/Time.hpp>

namespace Engine
{
    class State
    {
    public:
        State() {};
        virtual ~State() {};

        virtual void Init() = 0;//all setting sprites...
        virtual void ProcessInput() = 0;//key,kliks
        virtual void Update(sf::Time deltaTime) = 0;//time laps,same FPS vezde
        virtual void Draw() = 0;

        virtual void Pause() {};
        virtual void Start() {};
    };
}