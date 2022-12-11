#include <vector>

class Field;

using std::vector;
using std::pair;
using uint = unsigned int;

class FieldCorrector {
private:
    void playerPosFix(Field &field) const;

    void VictoryCellFix(Field &field, uint x_pos, uint y_pos) const;

public:
    bool validateField(Field &field);
};

