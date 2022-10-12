#include "MapEvent.h"

class ExplodeEvent : public MapEvent
{
private:
    uint damage;

protected:
    void pushPlayer(uint distance, Field &field) const;

public:
    ExplodeEvent(uint damage, uint radius);
    ~ExplodeEvent();
    void interact(Player &player) override;
    void interact(Field &field) override;
};
