#include"͹������.h"
using namespace std;


int main()
{
    int i, size = 4;
    double px, py;
    cout << "������������: ";
    cin >> size;
    mpoint* points;
    int miny_point_id;
    double* mcos;
    points = new mpoint[size];
    mcos = new double[size];
    for (i = 0; i < size; i++) {
        cout << "�������"<<i+1<<"�������"  << endl;
        cin >> px;
        cin >> py;
        points[i].x = px;
        points[i].y = py;
    }
    mpoint m;
    miny_point_id = m.get_miny_point_id(points, size);
    m.get_cos(points, mcos, miny_point_id, size);
    m.sort_points(points, mcos, size);
    m.get_outpoint(points, size);
}
  