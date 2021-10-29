#include "StateMan.hpp"

Engine::StateMan::StateMan() : m_add(false), m_replace(false), m_remove(false)
{
}

Engine::StateMan::~StateMan()
{
}

void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool replace)
{
    m_add = true;
    m_newState = std::move(toAdd);//unic pointer move dlya pereda4i

    m_replace = replace;//obnovlenine mesta
}

void Engine::StateMan::PopCurrent()
{
    m_remove = true;
}

void Engine::StateMan::ProcessStateChange()
{
    if (m_remove && (!m_stateStack.empty()))//proverka na pystoty
    {
        m_stateStack.pop();

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Start();
        }

        m_remove = false;//ina4e on budet vse ydalyat'
    }

    if (m_add)//proverka na add
    {
        if (m_replace && (!m_stateStack.empty()))//pop current state do add new one
        {
            m_stateStack.pop();
            m_replace = false;
        }

        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Pause();
        }

        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Start();
        m_add = false;
    }
}

std::unique_ptr<Engine::State>& Engine::StateMan::GetCurrent()
{
    return m_stateStack.top();//vozvroshyaem vverhnie sost stack
}