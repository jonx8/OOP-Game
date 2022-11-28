#pragma once
#include "../../models/Field.h"
#include "../../models/Cell.h"
using int_vector2D = std::vector<std::vector<int>>;

enum BuildingType
{
    LABIRINT,
    HUT,
    FORTRESS,
};

template <BuildingType buildingT, EventType EventT, uint x0, uint y0>
class MainBuildingRule
{
private:
    // Correspondence between field cell and schema
    // 0 - Ground
    // 1 - Wall
    // 2 - Event
    // 3 - Water
    int_vector2D labirint_map = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 3, 3, 3, 3, 0, 1},
        {1, 1, 3, 1, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 2, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };

    int_vector2D hut_map = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 2, 1},
        {1, 1, 1, 1},
    };

    int_vector2D fortress_map = {

        {1, 1, 3, 3, 3, 3, 3, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {3, 1, 0, 0, 0, 0, 0, 1, 3},
        {3, 1, 0, 1, 1, 1, 3, 1, 3},
        {3, 1, 0, 1, 2, 1, 3, 3, 3},
        {3, 1, 0, 1, 1, 1, 3, 1, 3},
        {3, 1, 0, 0, 0, 0, 3, 1, 3},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 3, 3, 3, 3, 3, 1, 1},
    };

    void build(Field &field, int_vector2D &map)
    {
        // height and width of map
        int h = map.size();
        int w = map.front().size();

        // Distance from the (y0, x0) to the edges of the building
        uint y_radius = h / 2 + h % 2; //
        uint x_radius = w / 2 + w % 2;

        // yd, xd - counters for a map; y, x - for a field
        for (int y = y0 - y_radius, yd = 0; yd < h; y++, yd++)
        {
            for (int x = x0 - x_radius, xd = 0; xd < h; x++, xd++)
            {
                // if the coordinate goes out of the field, then it goes out on the other side
                int y_n = (y + field.getHeight()) % field.getHeight();
                int x_n = (x + field.getWidth()) % field.getWidth();
                if (map[yd][xd] == 2)
                {
                    field.getCell(y_n, x_n).setEvent(EventsRegister::getReg().getEvent(EventT));
                }
                field.getCell(y_n, x_n).setType(static_cast<Cell::Objects>(map[yd][xd]));
            }
        }
    }

public:
    void operator()(Field &field)
    {
        switch (buildingT)
        {
        case LABIRINT:
            build(field, labirint_map);
            break;
        case HUT:
            build(field, hut_map);
            break;
        case FORTRESS:
            build(field, fortress_map);
            break;
        default:
            break;
        }
    }
};
