#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

typedef struct 
{
    int x;
    int y;
    double angle;
    int index;
} Point;

void swap(Point* a, Point* b) 
{
    Point temp = *a;
    *a = *b;
    *b = temp;
}

int orientation(Point p, Point q, Point r) 
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void* vp1, const void* vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    if (p1->angle < p2->angle) return -1;
    if (p1->angle > p2->angle) return 1;
    if (p1->x == p2->x) return (p1->y > p2->y) ? -1 : 1;
    return (p1->x < p2->x) ? -1 : 1;
}

int main() 
{
    int n, i;
    scanf("%d", &n);
    Point points[n];
    for (i = 0; i < n; i++) 
    {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].index = i + 1;
    }
    
    int miny_index = 0;
    for (i = 1; i < n; i++) 
    {
        if (points[i].y < points[miny_index].y || (points[i].y == points[miny_index].y && points[i].x < points[miny_index].x))
            miny_index = i;
    }
    for (i = 0; i < n; i++) 
    {
        if (points[i].y == points[miny_index].y && points[i].x < points[miny_index].x)
            miny_index = i;
    }
    swap(&points[0], &points[miny_index]);
    printf("%d\n", points[0].index); 
    
    for (i = 1; i < n; i++) 
    {
        points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x) * 180 / PI;
        if (points[i].angle < 0)
            points[i].angle += 360;
    }
    qsort(&points[1], n - 1, sizeof(Point), compare);
    for (i = 1; i < n; i++) 
    { 
        printf("%d ", points[i].index);
    }
    printf("\n");
    return 0;
}
