#include "ItemEvent.h"

class ArmorEvent : public ItemEvent
{
public:
    ArmorEvent();
    ~ArmorEvent();
    void interact(Player &player) override;
    void interact(Field& field) override;
    Event *clone() const override;
};