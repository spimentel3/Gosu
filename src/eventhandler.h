#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

class EventHandler
{
    private:
        EventHandler();
        EventHandler(const EventHandler &);
        const EventHandler &operator=(const EventHandler &);

        static EventHandler *m_instance;
    public:
        static EventHandler *instance();
};

#endif
