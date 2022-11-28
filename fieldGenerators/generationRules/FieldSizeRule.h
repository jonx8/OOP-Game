#pragma once
#include "../../models/Field.h"

template <uint H, uint W>
class FieldSizeRule
{
public:
    void operator()(Field &field)
    {
        if (H >= 10 && W >= 10)
        {
            field = Field(H, W);
            auto [x, y] = field.getPlayerCoords();
            field.setPlayerCoord(x, y);
        }
    }
};
