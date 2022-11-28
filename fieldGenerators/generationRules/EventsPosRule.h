#pragma once
#include <random>
#include "../../models/Field.h"
#include "../../models/Cell.h"

template <uint num, EventType event_type>
class EventsPosRule
{
public:
    void operator()(Field &field)
    {
        const size_t max_iter = (field.getHeight() * field.getWidth());
        for (size_t i = 0, event_num = 0; i < max_iter && event_num < num; i++)
        {
            int x = rand() % (field.getWidth() - 1);
            int y = rand() % (field.getHeight() - 1);
            Cell &curr_cell = field.getCell(y, x);
            if (!curr_cell.getEvent() && !curr_cell.hasPlayer() && curr_cell.getType() == Cell::Objects::GROUND)
            {
                curr_cell.setEvent(EventsRegister::getReg().getEvent(event_type));
                event_num++;
            }
        }
    }
};
