#include<bits/stdc++.h>
#include "Airports.cpp"
#include "where_we_go.cpp"
using namespace std;
void fly(Planes plane, Aiports destination) {
    // �������� ������� ���������

    // ������� ������� ������ ������. ���� ������ bad �� �������� void recalculation
    if (currently_weather_in_destination == 0) {
        recalculation(currently_lat, currently_lon);
    }
    // ������� ������ ������� ���������
}
void recalculation(float currently_lat, float currently_lon, Planes plane) {
    destination_airport = where_we_go(currently_lat, currently_lon, plane);
    fly(plane, destination_airport);
}
