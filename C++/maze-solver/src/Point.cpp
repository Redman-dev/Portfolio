#include "Point.h"

bool operator==(const Point &point1, const Point &point2) {
    return ((point1.m_x_position == point2.m_x_position) && (point1.m_y_position == point2.m_y_position));
}

bool operator!=(const Point &point1, const Point &point2) {
    return !((point1.m_x_position == point2.m_x_position) && (point1.m_y_position == point2.m_y_position));
}