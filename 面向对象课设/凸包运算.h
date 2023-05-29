#include <iostream>
#include <vector>
#include <math.h>
#include<cmath>
using namespace std;

class mpoint {                       //class point(x, y)
public:
    double x;
    double y;
    mpoint(double xx = 0, double yy = 0) {
        x = xx;
        y = yy;
    }
    int get_miny_point_id(mpoint* points, int size);
    void get_cos(mpoint* points, double* mcos, int id, int size);
    void sort_points(mpoint* points, double* mcos, int size);
    int ccw(mpoint a, mpoint b, mpoint c);
    void get_outpoint(mpoint* points, int size);
};

int mpoint:: get_miny_point_id(mpoint* points, int size) { //get the point with min_y
    int i, min_id = 0;
    double miny = 10000;
    for (i = 0; i < size; i++) {
        if (points[i].y < miny) {
            miny = points[i].y;
            min_id = i;
        }
    }
    return min_id;
}

void mpoint::get_cos(mpoint* points, double* mcos, int id, int size) {  //get point's cos
    int i;
    double coss;
    for (i = 0; i < size; i++) {
        if (i == id) {
            mcos[i] = 2;
        }
        else {
            coss = (points[i].x - points[id].x) / sqrt((points[i].x - points[id].x) * (points[i].x - points[id].x) + (points[i].y - points[id].y) * (points[i].y - points[id].y));
            mcos[i] = coss;
        }
    }
}

void mpoint:: sort_points(mpoint* points, double* mcos, int size) {   //sort the points
    int i, j;
    double temp_cos;
    mpoint temp_point;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {      //bubble sorting
            if (mcos[j] < mcos[j + 1]) {
                temp_cos = mcos[j];
                mcos[j] = mcos[j + 1];
                mcos[j + 1] = temp_cos;

                temp_point = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp_point;
            }
        }
    }
}

int mpoint:: ccw(mpoint a, mpoint b, mpoint c) {          //judge if it is couter-colockwise
    double area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area2 < 0) {
        return -1;          // clockwise
    }
    else {
        if (area2 > 0) return 1;    // counter-clockwise
        else return 0;              // collinear
    }

}

void mpoint:: get_outpoint(mpoint* points, int size) {    //get points in stack
    int i, k;
    vector <mpoint>outpoint;
    outpoint.push_back(points[0]);
    outpoint.push_back(points[1]);
    i = 2;
    while (true) {
        if (i == size) {
            break;
        }
        if (ccw(outpoint[outpoint.size() - 2], outpoint[outpoint.size() - 1], points[i]) > 0) {
            outpoint.push_back(points[i]);
            i = i + 1;
        }
        else {
            outpoint.pop_back();
        }
    }
    cout << "The outpoints are: " << endl;
    for (k = 0; k < outpoint.size(); k++) {
        cout << outpoint[k].x << " " << outpoint[k].y << endl;
    }
}
