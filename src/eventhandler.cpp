#include"eventhandler.h"
EventHandler::EventHandler()
{
}

/* static */ EventHandler *EventHandler::m_instance = 0;


/* static */ EventHandler * EventHandler::instance()
{
    if (m_instance == 0){
        m_instance = new EventHandler();
    }
    return m_instance;
}
