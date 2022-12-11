#pragma once

#include "../../models/Field.h"
#include "../../models/Cell.h"

using int_vector2D = std::vector<std::vector<int>>;

enum BuildingType {
    LABIRINT,
    HUT,
    FORTRESS,
};

template<BuildingType buildingT, int x0, int y0>
class MainBuildingRule {
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
            {0, 0, 0, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1},
    };

    int_vector2D hut_map = {
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 1, 1},
            {1, 1, 1, 1},
    };

    int_vector2D fortress_map = {

            {1, 1, 3, 3, 3, 3, 3, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {3, 1, 0, 0, 0, 0, 0, 1, 3},
            {3, 1, 0, 1, 1, 1, 3, 1, 3},
            {3, 1, 0, 1, 0, 1, 3, 3, 3},
            {3, 1, 0, 1, 1, 1, 3, 1, 3},
            {3, 1, 0, 0, 0, 0, 3, 1, 3},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 3, 3, 3, 3, 3, 1, 1},
    };

    void build(Field &field, int_vector2D &map) {
        // height and width of map
        int h = static_cast<int>(map.size());
        int w = static_cast<int>(map.front().size());
        if (map.size() > field.getHeight() or map.front().size() > field.getWidth())
        {
            return;
        }

        // Distance from the (y0, x0) to the edges of the building
        int y_radius = h / 2 + h % 2;
        int x_radius = w / 2 + w % 2;

        int player_x = field.getPlayerCoords().first;
        int player_y = field.getPlayerCoords().second;

        const bool playerInYRadius = player_y >= (y0 - y_radius) && player_y <= (y0 + y_radius);
        const bool playerInXRadius = player_x >= (x0 - x_radius) && player_x <= (x0 + x_radius);

        if (playerInYRadius && playerInXRadius) {
            return;
        }

        // yd, xd - counters for a map; y, x - for a field
        for (int y = y0 - y_radius, yd = 0; yd < h; y++, yd++) {
            for (int x = x0 - x_radius, xd = 0; xd < h; x++, xd++) {
                // if the coordinate goes out of the field, then it goes out on the other side
                int y_n = (y + field.getHeight()) % field.getHeight();
                int x_n = (x + field.getWidth()) % field.getWidth();
                if (!field.getCell(y_n, x_n).getEvent()) {
                    field.getCell(y_n, x_n).setType(static_cast<Cell::Objects>(map[yd][xd]));
                }
            }
        }


    }

public:

    void operator()(Field &field) {
        switch (buildingT) {
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
