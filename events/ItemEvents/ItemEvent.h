#include "../Event.h"
#include "../../models/Player.h"

class ItemEvent : public Event
{
public:
    virtual ~ItemEvent() = 0;
    virtual void interact(Player& player) = 0;
    void interact(Field& field) override;
};

