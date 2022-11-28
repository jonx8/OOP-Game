#include "ItemEvent.h"

class ArmorEvent : public ItemEvent
{
public:
    ArmorEvent() = default;
    ArmorEvent(const ArmorEvent &obj);
    ~ArmorEvent() override = default;
    void interact(Player &player, Field &field) override;
    [[nodiscard]] Event *clone() const override;
};