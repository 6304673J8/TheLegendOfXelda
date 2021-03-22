#ifndef UTILS_H
#define UTILS_H

#include "includes.h"
#include <algorithm>

//#define PI 3.14159265f
#define PI2RAD  (3.14159265f/180.0f)
#define MAX_DIGITS_U32 10

//! Colision entre dos rectángulos
bool C_RectangleCollision(C_Rectangle RectA, C_Rectangle RectB);

//! Colision entre un rectángulo y un triángulo
bool RectangleTriangleCollision(C_Rectangle a_rect, C_Triangle a_tri);

//! Devuelve true si el punto está dentro del rectángulo
bool isPointInRectangle(Point a_point, C_Rectangle a_rect);

//! Devuelve true si el punto está dentro del triángulo
bool isPointInTriangle(Point a_point, C_Triangle a_tri);

//! Given three colinear points p, q, r, the function checks if point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r);

/*!To find orientation of ordered triplet (p, q, r).
 The function returns following values
 0 --> p, q and r are colinear
 1 --> Clockwise
 2 --> Counterclockwise
 */
int orientation(Point p, Point q, Point r);

//! The main function that returns true if line segment 'p1q1' and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2);

//! Mira si dos puntos están a X distancia o menos
bool PointsAtDistance(int x1, int y1, int x2, int y2, int distance);

//!Longitud de un número entero
int integerLength(int value);

//! Checks if a point in a matrix belongs to the respective ellipse curve. Chequea si un punto pertenece a una elipse de tamaño halfWidth*2 x halfHeight*2, dentro del primer cuadrante.
bool checkEllipsePoint(int pointX, int pointY, int halfHeight, int halfWidth);

//! Clamps an integer to the range specified with [a,b]
int intClamp(int v, int a, int b);

//! Returns a point rotated after a pivot
Point rotatePoint(Point pivot, Point a_point, float angle);

//! Converts Integer to String
std::string itos(int number, int num_digits);

//! Returns true if a string is inside another
bool findInString(std::string& aString, std::string to_find);

//! Replaces first occurrence of a substring in a string
void replaceString(std::string& aString, std::string replaced, std::string replacing);

//! Replaces all occurrences of a substring in a string
void replaceAllInString(std::string& aString, std::string replaced, std::string replacing);

//! Splits a string given a character for separation
std::vector<std::string> splitString(std::string aString, char separationCharacter);

bool isStringInVector(std::vector<std::string> &aVector, std::string aString);

bool findPointInVector(Point aPoint, std::vector<Point> &aVector);
bool findPointInVector(Point aPoint, std::vector<Point> &aVector, int &index);

//! Deletes the file in this path
void deleteFile(const char* file_path);

#endif
