
#include <gtest/gtest.h>
#include <functions/functions.h>


using namespace vehicle;
using namespace std;


TEST(GetTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 3, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	
	EXPECT_EQ(vehicle[0].get_model(), "Car");
	EXPECT_EQ(vehicle[2].get_name(), "Harley");
	EXPECT_EQ(vehicle[0].get_v(), 2);
	EXPECT_EQ(vehicle[1].get_t(), 20);
	
}

TEST(CarCalcTest, Test) {

	auto veh1 = Vehicle(VehicleKinds::Car, "LADA Granta", 2);
	auto tax1 = veh1.calc(10);

	EXPECT_EQ(tax1, 20);

}

TEST(FreightCalcTest, Test) {

	auto veh2 = Vehicle(VehicleKinds::Freight, "вџурї", 3, 26);
	auto tax2 = veh2.calc(10);

	EXPECT_EQ(tax2, 420);

}

TEST(MotorbikeCalcTest, Test) {

	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 3);
	auto tax3 = veh3.calc(10);

	EXPECT_EQ(tax3, 9);

}

TEST(SizeTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta", 4);
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї", 4, 10);
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	auto s = vehicle.size();

	EXPECT_EQ(s, 6);

}

TEST(ReplaceTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta", 4);
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї", 4, 10);
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	int sz = vehicle.size();
	
	EXPECT_EQ(vehicle[3].get_model(), "Car");
	EXPECT_EQ(vehicle[3].get_name(), "LADA Granta");
	EXPECT_EQ(sz, 6); 

	vehicle[3] = veh3;

	EXPECT_EQ(vehicle[3].get_model(), "Motorbike");
	EXPECT_EQ(vehicle[3].get_name(), "Harley");
	EXPECT_EQ(sz, 6);
	
}


TEST(OperatorTestThrow, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta", 4);
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї", 4, 10);
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	EXPECT_ANY_THROW(vehicle.operator[](6));
}

TEST(InsertTestThrow, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);

	vehicle.add(veh1);
	vehicle.add(veh2);

	EXPECT_ANY_THROW(vehicle.insert(veh3, 2));

}

TEST(RemoveTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta", 4);
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї", 4, 10);
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	auto sizebef = vehicle.size();
	vehicle.remove(5);
	vehicle.remove(4);
	auto sizeaft = vehicle.size();
	auto maxim = maximal(vehicle, 4);

	EXPECT_EQ(sizebef, 6);
	EXPECT_EQ(sizeaft, 4);
	EXPECT_EQ(maxim, 1);

}

TEST(MaximTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen", 2);
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры", 2, 20);
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley", 2);
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta", 4);
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї", 4, 10);
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha", 4);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	auto maxim = maximal(vehicle, 4);
	
	EXPECT_EQ(maxim, 4);

}