/**
 * @file VehicleRentalSystem.cpp
 * @brief ���� ��Ż �ý��� ���� �ڵ�
 * @details Vehicle Ŭ������ �⺻���� �Ͽ� Car�� Truck �Ļ� Ŭ������ �����ϰ�,
 *          RentalSystem Ŭ������ ���� ���� ���� ����� �����մϴ�.
 */

 #include <iostream>
 #include <string>
 using namespace std;
 
 /**
  * @class Vehicle
  * @brief ��� ������ �⺻ Ŭ����
  * @details ������ �⺻ ������ ����� �����ϴ� �߻� �⺻ Ŭ�����Դϴ�.
  */
 class Vehicle {
 private:
     string vehicleId;    ///< ���� ���� �ĺ���
     string manufacturer; ///< ������ �̸�
     string model;        ///< ���� �𵨸�
     int year;            ///< �����⵵
     double dailyRate;    ///< ���� �⺻ �뿩 ��� (��)
 
 public:
     /**
      * @brief �⺻ ������
      * @details ��� ��� ������ �⺻������ �ʱ�ȭ�մϴ�.
      */
     Vehicle() : vehicleId(""), manufacturer(""), model(""), year(0), dailyRate(0.0) {
         cout << "Vehicle �⺻ ������ ȣ��" << endl;
     }
 
     /**
      * @brief �Ű������� �ִ� ������
      * @param id ���� ID
      * @param mfr ������
      * @param mdl �𵨸�
      * @param yr �����⵵
      * @param rate ���� �뿩 ���
      */
     Vehicle(string id, string mfr, string mdl, int yr, double rate) 
         : vehicleId(id), manufacturer(mfr), model(mdl), year(yr), dailyRate(rate) {
         cout << "Vehicle �Ű����� ������ ȣ��" << endl;
     }
 
     /**
      * @brief ���� �Ҹ���
      * @details �Ļ� Ŭ������ �Ҹ��ڸ� �ùٸ��� ȣ���ϱ� ���� virtual�� �����մϴ�.
      */
     virtual ~Vehicle() {
         cout << "Vehicle �Ҹ��� ȣ��: " << vehicleId << endl;
     }
 
     // Getter/Setter �Լ���
 
     /**
      * @brief ���� ID ��ȯ
      * @return ���� ID ���ڿ�
      */
     string getVehicleId() const { return vehicleId; }
     
     /**
      * @brief ���� ID ����
      * @param id ������ ���� ID
      */
     void setVehicleId(const string& id) { vehicleId = id; }
     
     /**
      * @brief ������ ��ȯ
      * @return ������ ���ڿ�
      */
     string getManufacturer() const { return manufacturer; }
     
     /**
      * @brief ������ ����
      * @param mfr ������ ������
      */
     void setManufacturer(const string& mfr) { manufacturer = mfr; }
     
     /**
      * @brief �𵨸� ��ȯ
      * @return �𵨸� ���ڿ�
      */
     string getModel() const { return model; }
     
     /**
      * @brief �𵨸� ����
      * @param mdl ������ �𵨸�
      */
     void setModel(const string& mdl) { model = mdl; }
     
     /**
      * @brief �����⵵ ��ȯ
      * @return �����⵵ ������
      */
     int getYear() const { return year; }
     
     /**
      * @brief �����⵵ ����
      * @param yr ������ �����⵵
      */
     void setYear(int yr) { year = yr; }
     
     /**
      * @brief ���� �뿩 ��� ��ȯ
      * @return ���� �뿩 ���
      */
     double getDailyRate() const { return dailyRate; }
     
     /**
      * @brief ���� �뿩 ��� ����
      * @param rate ������ ���� �뿩 ���
      */
     void setDailyRate(double rate) { dailyRate = rate; }
 
     /**
      * @brief ���� ���� ��� ���� �Լ�
      * @details ��� ������ �⺻ ������ ����մϴ�. �Ļ� Ŭ�������� �������̵��� �� �ֽ��ϴ�.
      */
     virtual void displayInfo() const {
         cout << "���� ID: " << vehicleId << endl;
         cout << "������: " << manufacturer << endl;
         cout << "�𵨸�: " << model << endl;
         cout << "�����⵵: " << year << endl;
         cout << "���� �뿩 ���: " << dailyRate << "��" << endl;
     }
 
     /**
      * @brief �뿩 ��� ��� ���� �Լ�
      * @param days �뿩 �ϼ�
      * @return ���� �뿩 ��� (��)
      * @details �⺻ �뿩 ��� ��� ����: ���� ��� * �뿩 �ϼ�
      */
     virtual double calculateRentalCost(int days) const {
         return dailyRate * days;
     }
 };
 
 /**
  * @class Car
  * @brief �¿����� ��Ÿ���� Vehicle �Ļ� Ŭ����
  * @details Vehicle�� ��ӹ޾� �¿����� �߰� �Ӽ��� ����� �����մϴ�.
  */
 class Car : public Vehicle {
 private:
     int numSeats;     ///< �¼� ��
     string fuelType;  ///< ���� Ÿ�� (���ָ�, ����, ���� ��)
 
 public:
     /**
      * @brief �⺻ ������
      * @details �θ� Ŭ���� �����ڸ� ȣ���ϰ� �߰� ��� ������ �ʱ�ȭ�մϴ�.
      */
     Car() : Vehicle(), numSeats(0), fuelType("") {
         cout << "Car �⺻ ������ ȣ��" << endl;
     }
 
     /**
      * @brief �Ű������� �ִ� ������
      * @param id ���� ID
      * @param mfr ������
      * @param mdl �𵨸�
      * @param yr �����⵵
      * @param rate ���� �뿩 ���
      * @param seats �¼� ��
      * @param fuel ���� Ÿ��
      */
     Car(string id, string mfr, string mdl, int yr, double rate, int seats, string fuel)
         : Vehicle(id, mfr, mdl, yr, rate), numSeats(seats), fuelType(fuel) {
         cout << "Car �Ű����� ������ ȣ��" << endl;
     }
 
     /**
      * @brief �Ҹ���
      * @details �ڿ� ���� �� ��ü �Ҹ� �� ȣ��˴ϴ�.
      */
     ~Car() override {
         cout << "Car �Ҹ��� ȣ��: " << getVehicleId() << endl;
     }
 
     /**
      * @brief �¼� �� ��ȯ
      * @return �¼� ��
      */
     int getNumSeats() const { return numSeats; }
     
     /**
      * @brief �¼� �� ����
      * @param seats ������ �¼� ��
      */
     void setNumSeats(int seats) { numSeats = seats; }
     
     /**
      * @brief ���� Ÿ�� ��ȯ
      * @return ���� Ÿ�� ���ڿ�
      */
     string getFuelType() const { return fuelType; }
     
     /**
      * @brief ���� Ÿ�� ����
      * @param fuel ������ ���� Ÿ��
      */
     void setFuelType(const string& fuel) { fuelType = fuel; }
     
     /**
      * @brief ���� ���� ��� �������̵� �Լ�
      * @details �θ� Ŭ������ �⺻ ���� ��� �� �߰� ������ ����մϴ�.
      */
     void displayInfo() const override {
         Vehicle::displayInfo(); // �θ� Ŭ������ displayInfo() ȣ��
         cout << "�¼� ��: " << numSeats << endl;
         cout << "���� Ÿ��: " << fuelType << endl;
     }
 
     /**
      * @brief �뿩 ��� ��� �������̵� �Լ�
      * @param days �뿩 �ϼ�
      * @return ���� �뿩 ��� (��)
      * @details �¿��� �뿩 ��� ��� ����: �⺻ ��� + (�¼��� 1000�� * �¼� �� * �뿩 �ϼ�)
      */
     double calculateRentalCost(int days) const override {
         // �⺻ �뿩 ��뿡 �¼��� 1000��/�� �߰�
         return Vehicle::calculateRentalCost(days) + (numSeats * 1000 * days);
     }
 };
 
 /**
  * @class Truck
  * @brief Ʈ���� ��Ÿ���� Vehicle �Ļ� Ŭ����
  * @details Vehicle�� ��ӹ޾� Ʈ���� �߰� �Ӽ��� ����� �����մϴ�.
  */
 class Truck : public Vehicle {
 private:
     double loadCapacity; ///< ���� �뷮 (��)
     int numAxles;        ///< �� ��
 
 public:
     /**
      * @brief �⺻ ������
      * @details �θ� Ŭ���� �����ڸ� ȣ���ϰ� �߰� ��� ������ �ʱ�ȭ�մϴ�.
      */
     Truck() : Vehicle(), loadCapacity(0.0), numAxles(0) {
         cout << "Truck �⺻ ������ ȣ��" << endl;
     }
 
     /**
      * @brief �Ű������� �ִ� ������
      * @param id ���� ID
      * @param mfr ������
      * @param mdl �𵨸�
      * @param yr �����⵵
      * @param rate ���� �뿩 ���
      * @param capacity ���� �뷮 (��)
      * @param axles �� ��
      */
     Truck(string id, string mfr, string mdl, int yr, double rate, double capacity, int axles)
         : Vehicle(id, mfr, mdl, yr, rate), loadCapacity(capacity), numAxles(axles) {
         cout << "Truck �Ű����� ������ ȣ��" << endl;
     }
 
     /**
      * @brief �Ҹ���
      * @details �ڿ� ���� �� ��ü �Ҹ� �� ȣ��˴ϴ�.
      */
     ~Truck() override {
         cout << "Truck �Ҹ��� ȣ��: " << getVehicleId() << endl;
     }
 
     /**
      * @brief ���� �뷮 ��ȯ
      * @return ���� �뷮 (��)
      */
     double getLoadCapacity() const { return loadCapacity; }
     
     /**
      * @brief ���� �뷮 ����
      * @param capacity ������ ���� �뷮
      */
     void setLoadCapacity(double capacity) { loadCapacity = capacity; }
     
     /**
      * @brief �� �� ��ȯ
      * @return �� ��
      */
     int getNumAxles() const { return numAxles; }
     
     /**
      * @brief �� �� ����
      * @param axles ������ �� ��
      */
     void setNumAxles(int axles) { numAxles = axles; }
     
     /**
      * @brief ���� ���� ��� �������̵� �Լ�
      * @details �θ� Ŭ������ �⺻ ���� ��� �� �߰� ������ ����մϴ�.
      */
     void displayInfo() const override {
         Vehicle::displayInfo(); // �θ� Ŭ������ displayInfo() ȣ��
         cout << "���� �뷮: " << loadCapacity << "��" << endl;
         cout << "�� ��: " << numAxles << endl;
     }
 
     /**
      * @brief �뿩 ��� ��� �������̵� �Լ�
      * @param days �뿩 �ϼ�
      * @return ���� �뿩 ��� (��)
      * @details Ʈ�� �뿩 ��� ��� ����: �⺻ ��� + (��� 5000�� * ���� �뷮 * �뿩 �ϼ�)
      */
     double calculateRentalCost(int days) const override {
         // �⺻ �뿩 ��뿡 ��� 5000��/�� �߰�
         return Vehicle::calculateRentalCost(days) + (loadCapacity * 5000 * days);
     }
 };
 
 /**
  * @class RentalSystem
  * @brief ���� ��Ż �ý��� ���� Ŭ����
  * @details �ִ� 10���� ������ �����ϰ� �뿩 ���� ����� �����մϴ�.
  */
 class RentalSystem {
 private:
     Vehicle* vehicles[10]; ///< ���� ��ü ������ �迭 (�ִ� 10��)
     int numVehicles;       ///< ���� ��ϵ� ���� ��
 
 public:
     /**
      * @brief ������
      * @details ���� ���� 0���� �ʱ�ȭ�ϰ� ������ �迭�� nullptr�� �ʱ�ȭ�մϴ�.
      */
     RentalSystem() : numVehicles(0) {
         cout << "RentalSystem ������ ȣ��" << endl;
         // ������ �迭 �ʱ�ȭ
         for (int i = 0; i < 10; i++) {
             vehicles[i] = nullptr;
         }
     }
 
     /**
      * @brief �Ҹ���
      * @details ��� ���� �Ҵ�� ���� ��ü�� �����մϴ�.
      */
     ~RentalSystem() {
         cout << "RentalSystem �Ҹ��� ȣ��" << endl;
         // ��� ���� �Ҵ�� ���� ��ü ����
         for (int i = 0; i < numVehicles; i++) {
             delete vehicles[i]; // �� ���� ��ü �޸� ����
             vehicles[i] = nullptr;
         }
     }
 
     /**
      * @brief ���� �߰� �Լ�
      * @param vehicle �߰��� ���� ��ü ������
      * @return �߰� ���� ���� (true: ����, false: ����)
      * @details �ִ� 10����� ������ �ý��ۿ� ����մϴ�. �ߺ� ID �˻縦 �����մϴ�.
      */
     bool addVehicle(Vehicle* vehicle) {
         // �ִ� ���� �� Ȯ��
         if (numVehicles >= 10) {
             cout << "���� ��� ����: �ִ� ��� ���� ��(10��)�� �ʰ��߽��ϴ�." << endl;
             return false;
         }
         
         // �ߺ� ID Ȯ��
         for (int i = 0; i < numVehicles; i++) {
             if (vehicles[i]->getVehicleId() == vehicle->getVehicleId()) {
                 cout << "���� ��� ����: �̹� ��ϵ� ID�Դϴ�." << endl;
                 return false;
             }
         }
         
         // ���� �߰�
         vehicles[numVehicles++] = vehicle;
         cout << "���� ��� ����: " << vehicle->getVehicleId() << endl;
         return true;
     }
 
     /**
      * @brief ID�� ���� �˻� �Լ�
      * @param id �˻��� ���� ID
      * @return ã�� ���� ��ü ������ (������ nullptr)
      * @details ��ϵ� ���� �� ID�� ��ġ�ϴ� ������ ã�� ��ȯ�մϴ�.
      */
     Vehicle* findVehicle(const string& id) {
         // ��� ��ϵ� ������ ��ȸ�ϸ� ID �˻�
         for (int i = 0; i < numVehicles; i++) {
             if (vehicles[i]->getVehicleId() == id) {
                 return vehicles[i]; // ��ġ�ϴ� ���� �߰�
             }
         }
         return nullptr; // ������ ã�� ����
     }
 
     /**
      * @brief ��� ���� ���� ��� �Լ�
      * @details �ý��ۿ� ��ϵ� ��� ������ ������ ����մϴ�.
      */
     void displayAllVehicles() const {
         // ��ϵ� ������ ���� ���
         if (numVehicles == 0) {
             cout << "��ϵ� ������ �����ϴ�." << endl;
             return;
         }
         
         // ��� ���� ���� ���
         cout << "===== ��ϵ� ��� ���� ���� =====" << endl;
         for (int i = 0; i < numVehicles; i++) {
             cout << "\n[���� #" << (i + 1) << "]" << endl;
             vehicles[i]->displayInfo(); // �������� Ȱ���� �Լ� ȣ��
             cout << "------------------------" << endl;
         }
     }
 
     /**
      * @brief Ư�� ������ �뿩 ��� ��� �Լ�
      * @param id ���� ID
      * @param days �뿩 �ϼ�
      * @return ���� �뿩 ��� (��), ���� �� -1 ��ȯ
      * @details ������ ID�� ������ ���� �뿩 ����� ����մϴ�.
      */
     double calculateRentalFee(const string& id, int days) {
         // ���� �˻�
         Vehicle* vehicle = findVehicle(id);
         if (vehicle == nullptr) {
             cout << "���� ID�� ã�� �� �����ϴ�: " << id << endl;
             return -1; // ���� �ڵ�
         }
         
         // �������� Ȱ���� �뿩 ��� ���
         return vehicle->calculateRentalCost(days);
     }
 };
 
 /**
  * @brief ���� �Լ�
  * @return ���α׷� ���� ���� �ڵ�
  * @details ���� ��Ż �ý����� �׽�Ʈ�մϴ�.
  */
 int main() {
     // RentalSystem ��ü ����
     RentalSystem rentalSystem;
     
     // ���� ��ü ���� �� �ý��ۿ� �߰� (Car�� Truck ���� 2�� �̻�)
     // ���� �޸� �Ҵ����� ��ü ����
     Car* car1 = new Car("C001", "����", "�ƹݶ�", 2023, 50000, 5, "���ָ�");
     Car* car2 = new Car("C002", "���", "K5", 2024, 70000, 5, "���̺긮��");
     Truck* truck1 = new Truck("T001", "����", "FH16", 2022, 150000, 10.5, 3);
     Truck* truck2 = new Truck("T002", "��ī�Ͼ�", "R730", 2023, 180000, 15.0, 4);
     
     // �ý��ۿ� ���� �߰�
     rentalSystem.addVehicle(car1);
     rentalSystem.addVehicle(car2);
     rentalSystem.addVehicle(truck1);
     rentalSystem.addVehicle(truck2);
     
     // ��� ���� ���� ���
     rentalSystem.displayAllVehicles();
     
     // ����ڷκ��� ���� ID�� �뿩 �ϼ� �Է¹ޱ�
     string vehicleId;
     int rentalDays;
     
     cout << "\n�뿩�� ���� ID�� �Է��ϼ���: ";
     cin >> vehicleId;
     
     cout << "�뿩 �ϼ��� �Է��ϼ���: ";
     cin >> rentalDays;
     
     // �뿩 ��� ��� �� ���
     double rentalFee = rentalSystem.calculateRentalFee(vehicleId, rentalDays);
     if (rentalFee >= 0) { // ������ ���� ��쿡�� ���
         cout << rentalDays << "�� �뿩 ���: " << rentalFee << "��" << endl;
     }
     
     // ������ �׽�Ʈ - �θ� Ŭ���� �����ͷ� �ڽ� Ŭ���� ��ü ����
     cout << "\n===== ������ �׽�Ʈ =====" << endl;
     Vehicle* vehiclePtr = rentalSystem.findVehicle(vehicleId);
     if (vehiclePtr != nullptr) {
         cout << "ã�� ���� ����:" << endl;
         // �������� Ȱ���� �Լ� ȣ��: ���� ��ü Ÿ�Կ� ���� ������ displayInfo() �޼��� ȣ��
         vehiclePtr->displayInfo();
         // �������� Ȱ���� �뿩 ��� ���: ���� ��ü Ÿ�Կ� ���� ������ calculateRentalCost() �޼��� ȣ��
         cout << "�������� ���� �뿩 ��� ���: " << vehiclePtr->calculateRentalCost(rentalDays) << "��" << endl;
     }
     
     // ���α׷� ���� (rentalSystem �Ҹ��ڰ� �ڵ����� ȣ��Ǿ� �޸� ����)
     return 0;
 }