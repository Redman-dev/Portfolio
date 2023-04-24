#ifndef ASSIGNMENT_2_POINT_H
#define ASSIGNMENT_2_POINT_H


struct Point {
    int m_x_position{0};
    int m_y_position{0};

    friend bool operator==(const Point &point1, const Point &point2);

    friend bool operator!=(const Point &point1, const Point &point2);
};


#endif //ASSIGNMENT_2_POINT_H
