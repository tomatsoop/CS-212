/*
CS 212 - Project2J Sabrina Zhang
Structs and Pointers
https://www.w3schools.com/c/c_structs_pointers.php
*/
#include <stdio.h>

/* Place your struct definitions for Circle, Triangle, and Rectangle here */
typedef struct Circle
{
    double radius, originX, originY;

} Circle;

typedef struct Rectangle
{
    double minX, maxX, minY, maxY;

} Rectangle;

typedef struct Triangle
{
    double pt1X, pt2X, minY, maxY;

} Triangle;



/* Define these 9 functions */
void InitializeCircle(Circle *c, double radius, double originX, double originY)
{   
    (*c).radius = radius;
    (*c).originX = originX;
    (*c).originY = originY;
};

void InitializeRectangle(Rectangle *r, double minX, double maxX, double minY, double maxY)
{
    (*r).minX = minX;
    (*r).maxX = maxX;
    (*r).minY = minY;
    (*r).maxY = maxY;
};

void InitializeTriangle(Triangle *t, double pt1X, double pt2X, double minY, double maxY)
{
    (*t).pt1X = pt1X;
    (*t).pt2X = pt2X;
    (*t).minY =  minY;
    (*t).maxY = maxY;
};


double GetCircleArea(Circle *c)
{
    return ((*c).radius * (*c).radius * 3.14159);
};

double GetRectangleArea(Rectangle *r)
{
     // Its area is (maxX-minX)*(maxY-minY). 
   return ((*r).maxX - (*r).minX) * ((*r).maxY - (*r).minY);
};

double GetTriangleArea(Triangle *t)
{
    return (( ((*t).pt2X - (*t).pt1X) * ((*t).maxY - (*t).minY))/2);
};


void GetCircleBoundingBox(Circle *c, double *bbox)
{
    bbox[0] = (*c).originX - (*c).radius;
    bbox[1] = (*c).originX + (*c).radius;
    bbox[2] = (*c).originY - (*c).radius;
    bbox[3] = (*c).originY + (*c).radius;

};

void GetRectangleBoundingBox(Rectangle *r, double *bbox)
{
   
    bbox[0] = (*r).minX;
    bbox[1] = (*r).maxX;
    bbox[2] = (*r).minY;
    bbox[3] = (*r).maxY;
    
};

void GetTriangleBoundingBox(Triangle *t, double *bbox)
{
    bbox[0] = (*t).pt1X;
    bbox[1] = (*t).pt2X;
    bbox[2] = (*t).minY;
    bbox[3] = (*t).maxY;
};


/* DO NOT MODIFY AFTER THIS POINT */


void
PrintTriangle(Triangle *t)
{
    double bbox[4];
    double area;
    area = GetTriangleArea(t);
    GetTriangleBoundingBox(t, bbox);
    printf("Triangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

void
PrintRectangle(Rectangle *r)
{
    double bbox[4];
    double area;
    area = GetRectangleArea(r);
    GetRectangleBoundingBox(r, bbox);
    printf("Rectangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}


void
PrintCircle(Circle *c)
{
    double bbox[4];
    double area;
    area = GetCircleArea(c);
    GetCircleBoundingBox(c, bbox);
    printf("Circle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

int main()
{
    Circle c;
    Triangle t;
    Rectangle r;
  

    InitializeCircle(&c, 1, 0, 0);
    PrintCircle(&c);
    InitializeCircle(&c, 1.5, 6, 8);
    PrintCircle(&c);
    InitializeCircle(&c, 0.5, -3, 4);
    PrintCircle(&c);

    InitializeRectangle(&r, 0, 1, 0, 1);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1, 1.1, 10, 20);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1.5, 3.5, 10, 12);
    PrintRectangle(&r);

    InitializeTriangle(&t, 0, 1, 0, 1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 1, 0, 0.1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 10, 0, 50);
    PrintTriangle(&t);

}



