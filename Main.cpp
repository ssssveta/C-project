#include<bits/stdc++.h>
#include "Main_algo.cpp"
using namespace std;

int main() {
//������ �������
    Planes first("Su-57", 10000, 5000);
    Planes second("Mig-29", 9000, 4500);
    vector<Planes> vec_planes;
    vec_planes.push_back(first);
    vec_planes.push_back(second);
//������� ��������
    Airports vnukovo("Vnukovo", "Moscow", 1.00, 2.000, 1);
    Airports monaco("Monaco", "Monaco", 12.00, 22.000, 1);
// ����������� ������� �������� ���� ����� �������� ���� � �������
    destination_airport = where_we_go(vnukovo.latitude, vnukovo.longitude, first);
//����������� ��������� ������ � ������ ������ ������� �������� ����������
    while (���� �����) {
        if (currently_weather_in_destination != 0) {
            fly(vnukovo, first, destination_airport);
        } else {
            destination_airport = where_we_go(currently_lat, currently_lon, plane); // ��� ����������
        }
    }

//���� ������ �����, �� ����������� ����������
//����� ����������� ��������� ������ ������������ �� ��� ��� ���� ������ �� �������
    return 0;
}
