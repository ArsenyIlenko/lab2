#pragma once
#include <string>
#include <iostream>


namespace vehicle {

	enum VehicleKinds { 
		Car = 1,
		Freight,
		Motorbike
	};

	class Vehicle { 

	private:

		VehicleKinds _model; 
		std::string _name;
		float _v;
		float _t; 

	public:

		std::string get_model() const;
		std::string get_name() const;
		float get_v() const;
		float get_t() const;
		Vehicle(VehicleKinds model, std::string name, float _v);
		Vehicle(VehicleKinds model, std::string name, float _v, float _t);
		Vehicle();
		float calc(float s);
	};

	std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle);

	class VehicleList {

	private:

		Vehicle** _vehicle;
		int _size;

	public:

		VehicleList(const VehicleList& copy);
		VehicleList();
		~VehicleList();
		Vehicle& operator[](int index);
		VehicleList& operator=(VehicleList copy);
		int size() const;
		const Vehicle& operator[](int index) const;
		void replace(Vehicle vehicle, int index);
		void insert(Vehicle vehicle, int index);
		void add(Vehicle vehicle);
		void remove(int index);
		void swap(VehicleList& shr) noexcept;
		void clear();
		const Vehicle& get_vehicle(int index) const;

	};

	int maximal (VehicleList& vehicle, float s);
	std::ostream& operator<<(std::ostream& stream, const VehicleList& vehicles);
}