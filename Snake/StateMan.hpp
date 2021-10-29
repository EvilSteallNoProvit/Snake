#pragma once

#include <stack>//The std::stack class is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure
#include<memory>//This header defines general utilities to manage dynamic memory:

#include <memory>

#include "State.hpp"

namespace Engine
{
    class StateMan
    {
    private:
        std::stack<std::unique_ptr<State>> m_stateStack;//Manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers (depending on the deleter used)
        std::unique_ptr<State> m_newState;//obnovlenie stack (state stack modified at start of next upd cycle
		//add and pok

        bool m_add;
        bool m_replace;
        bool m_remove;

    public:
        StateMan();
        ~StateMan();

        void Add(std::unique_ptr<State> toAdd, bool replace = false);
        void PopCurrent();//remove current state from state stack
        void ProcessStateChange();//main izmenenie stack
        std::unique_ptr<State>& GetCurrent();//vezvroshenie unic ukaz na sost
    };
}