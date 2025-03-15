/**
 * @brief Updates the Point_v2 interface with a slope function.
 * 
 */
 #pragma once
 #include "NumberDouble.h"

 /**
  * @brief Numerical tolerance equality calculations
  * 
  */
 #define TOLERANCE 10e-4
 
 /**
  * @brief Two-dimensional Point data type
  * consisting of an x and y coordinate.
  * 
  */
 typedef struct {
     Number x; 
     Number y;
 } Point;
 
 /**
  * @brief Calculates the euclidean distance
  * between two points.
  * 
  * @param p point
  * @param q point
  * @return double
  */
 double POINTdistance(Point p, Point q);
 
 /**
  * @brief Calculates the slope between
  * two points.
  * 
  * @param p point
  * @param q point
  * @return double 
  */
 double POINTslope(Point p, Point q);
 
 /**
  * @brief Determines if three points are collinear
  * to within a tolerance factor.
  * 
  * @param p point
  * @param q point
  * @param r point
  * @return true if collinear else
  * @return false 
  * 
  * @see TOLERANCE
  */
 bool POINTisCollinear(Point p, Point q, Point r);