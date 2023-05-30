#include <functions/functions.h>
#include <stdexcept>
#include <string>
#include <cmath>


using namespace vehicle;
using namespace std;

Vehicle::Vehicle() :_model(Car), _name(""), _v(0), _t(0) {}
Vehicle::Vehicle(VehicleKinds model, string name, float v):_model(model), _name(name), _v(v){}
Vehicle::Vehicle(VehicleKinds model, string name, float v, float t) :_model(model), _name(name), _v(v), _t(t) {}
VehicleList::VehicleList() :_vehicle(nullptr), _size(0) {}

string Vehicle::get_name() const { return _name; }
float Vehicle::get_v() const { return _v; }
float Vehicle::get_t() const { return _t; }

std::string Vehicle::get_model() const {
    switch (_model)
    {
    case VehicleKinds::Car:
        return "Car";
    case VehicleKinds::Freight:
        return "Freight";
    case VehicleKinds::Motorbike:
        return "Motorbike";
    default:
        throw runtime_error("Unknown kind");
    }
}

float Vehicle::calc(float s) {

    switch (_model) {

    case Car:

        return s * _v;

    case Freight:

        return s * _v * (_t / 2 + 1);

    case Motorbike:

        return 0.3 * s * _v;

    }

}




int vehicle::maximal(VehicleList& vehicles, float s) {

    int sz = vehicles.size();
    int index = 0;
    float max_tax = vehicles[0].calc(s);

    for (int i = 1; i < sz; i++) {

        const float tax = vehicles[i].calc(s);

        if (tax > max_tax) {

            max_tax = tax;
            index = i;

        }

    }

    return index;

}

std::ostream& vehicle::operator<<(std::ostream& stream, const Vehicle& vehicle) {
    if (vehicle.get_model() == "Car")
        stream << "Vehicle Model : " << vehicle.get_model() << "\n" << "     Vehicle Name: " << vehicle.get_name() << "\n" << "     Engine capacity: " << vehicle.get_v() << "\n";
    else if (vehicle.get_model() == "Freight")
        stream << "Vehicle Model : " << vehicle.get_model() << "\n" << "     Vehicle Name: " << vehicle.get_name() << "\n" << "     Engine capacity: " << vehicle.get_v() << "\n" << "     Tonnage: " << vehicle.get_t() << "\n";
    else if (vehicle.get_model() == "Motorbike")
        stream << "Vehicle Model : " << vehicle.get_model() << "\n" << "     Vehicle Name: " << vehicle.get_name() << "\n" << "     Engine capacity: " << vehicle.get_v() << "\n";
    return stream;
}

Vehicle& VehicleList::operator[](int index){

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    return *_vehicle[index];

}

const Vehicle& VehicleList::operator[](int index) const {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    return *_vehicle[index];

}

void VehicleList::replace(Vehicle vehicle, int index) {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    *_vehicle[index] = vehicle;

}

void VehicleList::insert(Vehicle vehicle, int index) {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    auto vehicles = new Vehicle* [_size + 1];

    for (int i = 0; i < _size; i++) {
        vehicles[i] = _vehicle[i];
    }

    for (int i = _size - 1; i >= index; --i) {

        vehicles[i] = vehicles[i - 1];

    }

    vehicles[index] = new Vehicle(vehicle);
    delete[] _vehicle;
    _vehicle = vehicles;
    _size++;

}

void VehicleList::add(Vehicle vehicle) {

    auto vehicles = new Vehicle* [_size + 1];

    for (int i = 0; i < _size; i++) {

        vehicles[i] = _vehicle[i];

    }

    vehicles[_size] = new Vehicle(vehicle);
    delete[] _vehicle;
    _vehicle = vehicles;
    _size++;

}

void VehicleList::remove(int index) {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    delete _vehicle[index];

    for (int i = index; i < _size - 1; i++) {

        _vehicle[i] = _vehicle[i + 1];

    }

    _size--;
}

VehicleList::VehicleList(const VehicleList& copy) :

    _vehicle(new Vehicle* [copy._size]),
    _size(copy._size)

{

    for (int i = 0; i < _size; i++)
        _vehicle[i] = new Vehicle(*copy._vehicle[i]);

}

void VehicleList::swap(VehicleList& shr) noexcept {

    std::swap(_size, shr._size);
    std::swap(_vehicle, shr._vehicle);

}

VehicleList& VehicleList::operator = (VehicleList copy){

    swap(copy);
    return *this;

}

VehicleList::~VehicleList() {

    clear();

}

void VehicleList::clear() {

    if (_vehicle == nullptr)
        return;

    for (int i = 0; i < _size; i++)
        delete _vehicle[i];

    _size = 0;
    delete[] _vehicle;
    _vehicle = nullptr;

}

int VehicleList::size() const {

    return _size;

}

const Vehicle& VehicleList::get_vehicle(int index) const {

    if (index < 0 or index >= _size)
        throw runtime_error("Error");

    return *_vehicle[index];

}

std::ostream& vehicle::operator<<(std::ostream& stream, const VehicleList& vehicles) {

    stream << vehicles.size() << " Vehicles: " << endl;

    for (int i = 0; i < vehicles.size(); i++) {

        cout << "  " << i + 1 << ") " << vehicles.get_vehicle(i);
        return stream;
    }
}