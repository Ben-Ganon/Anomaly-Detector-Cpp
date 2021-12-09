/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */
#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "anomaly_detection_util.h"

using namespace std;


// ------------ DO NOT CHANGE -----------

class Circle{
public:
	Point center;
	float radius;
	Circle(Point c,float r):center(c),radius(r){}
    Circle():center(Point(0,0)) {
        this->radius = 0;
    };
};
// --------------------------------------

Circle findMinCircle(Point** points,size_t size);
float dist(const Point &a, const Point &b);
bool point_in_circle(const Circle &c, const Point &p);
Point get_circle_center(float bx, float by, float cx, float cy);
Circle circle_from(const Point &A, const Point &B, const Point &C);
Circle circle_from(const Point &A, const Point &B);
bool is_valid_circle(const Circle &c, const vector<Point> &P);
Circle minCircleTrivial(vector<Point> &P);
Circle minCircleHelper(vector<Point> &P, vector<Point> R, int n);
Circle callMinCircle(const vector<Point> &P);
Circle findMinCircle(Point **points, size_t size);

// you can add here additional methods

#endif /* MINCIRCLE_H_ */
