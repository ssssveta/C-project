#include<bits/stdc++.h>
using namespace std;
class Planes {
public:
    string name;
    float amount_of_petrol; // � �����������
    float fuel_consumption; // � ����/ ���
    float fuel_left; // � ��
    float speed; // � ��/���
    Planes();
    Planes(string arg_name, int arg_amount_of_petrol, int arg_fuel_consumption) {
        amount_of_petrol = arg_amount_of_petrol;
        name = arg_name;
        fuel_consumption = arg_fuel_consumption;
    }
    void print(){
        cout << "name: " << name << '\n' << "amount of petrol: " << amount_of_petrol
        << '\n' << "fuel consumption per hour: " << fuel_consumption << '\n';
    }
};

