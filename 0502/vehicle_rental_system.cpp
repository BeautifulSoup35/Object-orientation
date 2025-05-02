/**
 * @file VehicleRentalSystem.cpp
 * @brief 차량 렌탈 시스템 구현 코드
 * @details Vehicle 클래스를 기본으로 하여 Car와 Truck 파생 클래스를 구현하고,
 *          RentalSystem 클래스를 통해 차량 관리 기능을 제공합니다.
 */

 #include <iostream>
 #include <string>
 using namespace std;
 
 /**
  * @class Vehicle
  * @brief 모든 차량의 기본 클래스
  * @details 차량의 기본 정보와 기능을 포함하는 추상 기본 클래스입니다.
  */
 class Vehicle {
 private:
     string vehicleId;    ///< 차량 고유 식별자
     string manufacturer; ///< 제조사 이름
     string model;        ///< 차량 모델명
     int year;            ///< 제조년도
     double dailyRate;    ///< 일일 기본 대여 요금 (원)
 
 public:
     /**
      * @brief 기본 생성자
      * @details 모든 멤버 변수를 기본값으로 초기화합니다.
      */
     Vehicle() : vehicleId(""), manufacturer(""), model(""), year(0), dailyRate(0.0) {
         cout << "Vehicle 기본 생성자 호출" << endl;
     }
 
     /**
      * @brief 매개변수가 있는 생성자
      * @param id 차량 ID
      * @param mfr 제조사
      * @param mdl 모델명
      * @param yr 제조년도
      * @param rate 일일 대여 요금
      */
     Vehicle(string id, string mfr, string mdl, int yr, double rate) 
         : vehicleId(id), manufacturer(mfr), model(mdl), year(yr), dailyRate(rate) {
         cout << "Vehicle 매개변수 생성자 호출" << endl;
     }
 
     /**
      * @brief 가상 소멸자
      * @details 파생 클래스의 소멸자를 올바르게 호출하기 위해 virtual로 선언합니다.
      */
     virtual ~Vehicle() {
         cout << "Vehicle 소멸자 호출: " << vehicleId << endl;
     }
 
     // Getter/Setter 함수들
 
     /**
      * @brief 차량 ID 반환
      * @return 차량 ID 문자열
      */
     string getVehicleId() const { return vehicleId; }
     
     /**
      * @brief 차량 ID 설정
      * @param id 설정할 차량 ID
      */
     void setVehicleId(const string& id) { vehicleId = id; }
     
     /**
      * @brief 제조사 반환
      * @return 제조사 문자열
      */
     string getManufacturer() const { return manufacturer; }
     
     /**
      * @brief 제조사 설정
      * @param mfr 설정할 제조사
      */
     void setManufacturer(const string& mfr) { manufacturer = mfr; }
     
     /**
      * @brief 모델명 반환
      * @return 모델명 문자열
      */
     string getModel() const { return model; }
     
     /**
      * @brief 모델명 설정
      * @param mdl 설정할 모델명
      */
     void setModel(const string& mdl) { model = mdl; }
     
     /**
      * @brief 제조년도 반환
      * @return 제조년도 정수값
      */
     int getYear() const { return year; }
     
     /**
      * @brief 제조년도 설정
      * @param yr 설정할 제조년도
      */
     void setYear(int yr) { year = yr; }
     
     /**
      * @brief 일일 대여 요금 반환
      * @return 일일 대여 요금
      */
     double getDailyRate() const { return dailyRate; }
     
     /**
      * @brief 일일 대여 요금 설정
      * @param rate 설정할 일일 대여 요금
      */
     void setDailyRate(double rate) { dailyRate = rate; }
 
     /**
      * @brief 차량 정보 출력 가상 함수
      * @details 모든 차량의 기본 정보를 출력합니다. 파생 클래스에서 오버라이딩할 수 있습니다.
      */
     virtual void displayInfo() const {
         cout << "차량 ID: " << vehicleId << endl;
         cout << "제조사: " << manufacturer << endl;
         cout << "모델명: " << model << endl;
         cout << "제조년도: " << year << endl;
         cout << "일일 대여 요금: " << dailyRate << "원" << endl;
     }
 
     /**
      * @brief 대여 비용 계산 가상 함수
      * @param days 대여 일수
      * @return 계산된 대여 비용 (원)
      * @details 기본 대여 비용 계산 공식: 일일 요금 * 대여 일수
      */
     virtual double calculateRentalCost(int days) const {
         return dailyRate * days;
     }
 };
 
 /**
  * @class Car
  * @brief 승용차를 나타내는 Vehicle 파생 클래스
  * @details Vehicle을 상속받아 승용차의 추가 속성과 기능을 구현합니다.
  */
 class Car : public Vehicle {
 private:
     int numSeats;     ///< 좌석 수
     string fuelType;  ///< 연료 타입 (가솔린, 디젤, 전기 등)
 
 public:
     /**
      * @brief 기본 생성자
      * @details 부모 클래스 생성자를 호출하고 추가 멤버 변수를 초기화합니다.
      */
     Car() : Vehicle(), numSeats(0), fuelType("") {
         cout << "Car 기본 생성자 호출" << endl;
     }
 
     /**
      * @brief 매개변수가 있는 생성자
      * @param id 차량 ID
      * @param mfr 제조사
      * @param mdl 모델명
      * @param yr 제조년도
      * @param rate 일일 대여 요금
      * @param seats 좌석 수
      * @param fuel 연료 타입
      */
     Car(string id, string mfr, string mdl, int yr, double rate, int seats, string fuel)
         : Vehicle(id, mfr, mdl, yr, rate), numSeats(seats), fuelType(fuel) {
         cout << "Car 매개변수 생성자 호출" << endl;
     }
 
     /**
      * @brief 소멸자
      * @details 자원 정리 및 객체 소멸 시 호출됩니다.
      */
     ~Car() override {
         cout << "Car 소멸자 호출: " << getVehicleId() << endl;
     }
 
     /**
      * @brief 좌석 수 반환
      * @return 좌석 수
      */
     int getNumSeats() const { return numSeats; }
     
     /**
      * @brief 좌석 수 설정
      * @param seats 설정할 좌석 수
      */
     void setNumSeats(int seats) { numSeats = seats; }
     
     /**
      * @brief 연료 타입 반환
      * @return 연료 타입 문자열
      */
     string getFuelType() const { return fuelType; }
     
     /**
      * @brief 연료 타입 설정
      * @param fuel 설정할 연료 타입
      */
     void setFuelType(const string& fuel) { fuelType = fuel; }
     
     /**
      * @brief 차량 정보 출력 오버라이딩 함수
      * @details 부모 클래스의 기본 정보 출력 후 추가 정보를 출력합니다.
      */
     void displayInfo() const override {
         Vehicle::displayInfo(); // 부모 클래스의 displayInfo() 호출
         cout << "좌석 수: " << numSeats << endl;
         cout << "연료 타입: " << fuelType << endl;
     }
 
     /**
      * @brief 대여 비용 계산 오버라이딩 함수
      * @param days 대여 일수
      * @return 계산된 대여 비용 (원)
      * @details 승용차 대여 비용 계산 공식: 기본 요금 + (좌석당 1000원 * 좌석 수 * 대여 일수)
      */
     double calculateRentalCost(int days) const override {
         // 기본 대여 비용에 좌석당 1000원/일 추가
         return Vehicle::calculateRentalCost(days) + (numSeats * 1000 * days);
     }
 };
 
 /**
  * @class Truck
  * @brief 트럭을 나타내는 Vehicle 파생 클래스
  * @details Vehicle을 상속받아 트럭의 추가 속성과 기능을 구현합니다.
  */
 class Truck : public Vehicle {
 private:
     double loadCapacity; ///< 적재 용량 (톤)
     int numAxles;        ///< 축 수
 
 public:
     /**
      * @brief 기본 생성자
      * @details 부모 클래스 생성자를 호출하고 추가 멤버 변수를 초기화합니다.
      */
     Truck() : Vehicle(), loadCapacity(0.0), numAxles(0) {
         cout << "Truck 기본 생성자 호출" << endl;
     }
 
     /**
      * @brief 매개변수가 있는 생성자
      * @param id 차량 ID
      * @param mfr 제조사
      * @param mdl 모델명
      * @param yr 제조년도
      * @param rate 일일 대여 요금
      * @param capacity 적재 용량 (톤)
      * @param axles 축 수
      */
     Truck(string id, string mfr, string mdl, int yr, double rate, double capacity, int axles)
         : Vehicle(id, mfr, mdl, yr, rate), loadCapacity(capacity), numAxles(axles) {
         cout << "Truck 매개변수 생성자 호출" << endl;
     }
 
     /**
      * @brief 소멸자
      * @details 자원 정리 및 객체 소멸 시 호출됩니다.
      */
     ~Truck() override {
         cout << "Truck 소멸자 호출: " << getVehicleId() << endl;
     }
 
     /**
      * @brief 적재 용량 반환
      * @return 적재 용량 (톤)
      */
     double getLoadCapacity() const { return loadCapacity; }
     
     /**
      * @brief 적재 용량 설정
      * @param capacity 설정할 적재 용량
      */
     void setLoadCapacity(double capacity) { loadCapacity = capacity; }
     
     /**
      * @brief 축 수 반환
      * @return 축 수
      */
     int getNumAxles() const { return numAxles; }
     
     /**
      * @brief 축 수 설정
      * @param axles 설정할 축 수
      */
     void setNumAxles(int axles) { numAxles = axles; }
     
     /**
      * @brief 차량 정보 출력 오버라이딩 함수
      * @details 부모 클래스의 기본 정보 출력 후 추가 정보를 출력합니다.
      */
     void displayInfo() const override {
         Vehicle::displayInfo(); // 부모 클래스의 displayInfo() 호출
         cout << "적재 용량: " << loadCapacity << "톤" << endl;
         cout << "축 수: " << numAxles << endl;
     }
 
     /**
      * @brief 대여 비용 계산 오버라이딩 함수
      * @param days 대여 일수
      * @return 계산된 대여 비용 (원)
      * @details 트럭 대여 비용 계산 공식: 기본 요금 + (톤당 5000원 * 적재 용량 * 대여 일수)
      */
     double calculateRentalCost(int days) const override {
         // 기본 대여 비용에 톤당 5000원/일 추가
         return Vehicle::calculateRentalCost(days) + (loadCapacity * 5000 * days);
     }
 };
 
 /**
  * @class RentalSystem
  * @brief 차량 렌탈 시스템 관리 클래스
  * @details 최대 10대의 차량을 관리하고 대여 관련 기능을 제공합니다.
  */
 class RentalSystem {
 private:
     Vehicle* vehicles[10]; ///< 차량 객체 포인터 배열 (최대 10대)
     int numVehicles;       ///< 현재 등록된 차량 수
 
 public:
     /**
      * @brief 생성자
      * @details 차량 수를 0으로 초기화하고 포인터 배열을 nullptr로 초기화합니다.
      */
     RentalSystem() : numVehicles(0) {
         cout << "RentalSystem 생성자 호출" << endl;
         // 포인터 배열 초기화
         for (int i = 0; i < 10; i++) {
             vehicles[i] = nullptr;
         }
     }
 
     /**
      * @brief 소멸자
      * @details 모든 동적 할당된 차량 객체를 해제합니다.
      */
     ~RentalSystem() {
         cout << "RentalSystem 소멸자 호출" << endl;
         // 모든 동적 할당된 차량 객체 삭제
         for (int i = 0; i < numVehicles; i++) {
             delete vehicles[i]; // 각 차량 객체 메모리 해제
             vehicles[i] = nullptr;
         }
     }
 
     /**
      * @brief 차량 추가 함수
      * @param vehicle 추가할 차량 객체 포인터
      * @return 추가 성공 여부 (true: 성공, false: 실패)
      * @details 최대 10대까지 차량을 시스템에 등록합니다. 중복 ID 검사를 수행합니다.
      */
     bool addVehicle(Vehicle* vehicle) {
         // 최대 차량 수 확인
         if (numVehicles >= 10) {
             cout << "차량 등록 실패: 최대 등록 가능 수(10대)를 초과했습니다." << endl;
             return false;
         }
         
         // 중복 ID 확인
         for (int i = 0; i < numVehicles; i++) {
             if (vehicles[i]->getVehicleId() == vehicle->getVehicleId()) {
                 cout << "차량 등록 실패: 이미 등록된 ID입니다." << endl;
                 return false;
             }
         }
         
         // 차량 추가
         vehicles[numVehicles++] = vehicle;
         cout << "차량 등록 성공: " << vehicle->getVehicleId() << endl;
         return true;
     }
 
     /**
      * @brief ID로 차량 검색 함수
      * @param id 검색할 차량 ID
      * @return 찾은 차량 객체 포인터 (없으면 nullptr)
      * @details 등록된 차량 중 ID가 일치하는 차량을 찾아 반환합니다.
      */
     Vehicle* findVehicle(const string& id) {
         // 모든 등록된 차량을 순회하며 ID 검사
         for (int i = 0; i < numVehicles; i++) {
             if (vehicles[i]->getVehicleId() == id) {
                 return vehicles[i]; // 일치하는 차량 발견
             }
         }
         return nullptr; // 차량을 찾지 못함
     }
 
     /**
      * @brief 모든 차량 정보 출력 함수
      * @details 시스템에 등록된 모든 차량의 정보를 출력합니다.
      */
     void displayAllVehicles() const {
         // 등록된 차량이 없는 경우
         if (numVehicles == 0) {
             cout << "등록된 차량이 없습니다." << endl;
             return;
         }
         
         // 모든 차량 정보 출력
         cout << "===== 등록된 모든 차량 정보 =====" << endl;
         for (int i = 0; i < numVehicles; i++) {
             cout << "\n[차량 #" << (i + 1) << "]" << endl;
             vehicles[i]->displayInfo(); // 다형성을 활용한 함수 호출
             cout << "------------------------" << endl;
         }
     }
 
     /**
      * @brief 특정 차량의 대여 비용 계산 함수
      * @param id 차량 ID
      * @param days 대여 일수
      * @return 계산된 대여 비용 (원), 오류 시 -1 반환
      * @details 지정된 ID의 차량에 대한 대여 비용을 계산합니다.
      */
     double calculateRentalFee(const string& id, int days) {
         // 차량 검색
         Vehicle* vehicle = findVehicle(id);
         if (vehicle == nullptr) {
             cout << "차량 ID를 찾을 수 없습니다: " << id << endl;
             return -1; // 오류 코드
         }
         
         // 다형성을 활용한 대여 비용 계산
         return vehicle->calculateRentalCost(days);
     }
 };
 
 /**
  * @brief 메인 함수
  * @return 프로그램 종료 상태 코드
  * @details 차량 렌탈 시스템을 테스트합니다.
  */
 int main() {
     // RentalSystem 객체 생성
     RentalSystem rentalSystem;
     
     // 차량 객체 생성 및 시스템에 추가 (Car와 Truck 각각 2대 이상)
     // 동적 메모리 할당으로 객체 생성
     Car* car1 = new Car("C001", "현대", "아반떼", 2023, 50000, 5, "가솔린");
     Car* car2 = new Car("C002", "기아", "K5", 2024, 70000, 5, "하이브리드");
     Truck* truck1 = new Truck("T001", "볼보", "FH16", 2022, 150000, 10.5, 3);
     Truck* truck2 = new Truck("T002", "스카니아", "R730", 2023, 180000, 15.0, 4);
     
     // 시스템에 차량 추가
     rentalSystem.addVehicle(car1);
     rentalSystem.addVehicle(car2);
     rentalSystem.addVehicle(truck1);
     rentalSystem.addVehicle(truck2);
     
     // 모든 차량 정보 출력
     rentalSystem.displayAllVehicles();
     
     // 사용자로부터 차량 ID와 대여 일수 입력받기
     string vehicleId;
     int rentalDays;
     
     cout << "\n대여할 차량 ID를 입력하세요: ";
     cin >> vehicleId;
     
     cout << "대여 일수를 입력하세요: ";
     cin >> rentalDays;
     
     // 대여 비용 계산 및 출력
     double rentalFee = rentalSystem.calculateRentalFee(vehicleId, rentalDays);
     if (rentalFee >= 0) { // 오류가 없는 경우에만 출력
         cout << rentalDays << "일 대여 비용: " << rentalFee << "원" << endl;
     }
     
     // 다형성 테스트 - 부모 클래스 포인터로 자식 클래스 객체 접근
     cout << "\n===== 다형성 테스트 =====" << endl;
     Vehicle* vehiclePtr = rentalSystem.findVehicle(vehicleId);
     if (vehiclePtr != nullptr) {
         cout << "찾은 차량 정보:" << endl;
         // 다형성을 활용한 함수 호출: 실제 객체 타입에 따라 적절한 displayInfo() 메서드 호출
         vehiclePtr->displayInfo();
         // 다형성을 활용한 대여 비용 계산: 실제 객체 타입에 따라 적절한 calculateRentalCost() 메서드 호출
         cout << "다형성을 통한 대여 비용 계산: " << vehiclePtr->calculateRentalCost(rentalDays) << "원" << endl;
     }
     
     // 프로그램 종료 (rentalSystem 소멸자가 자동으로 호출되어 메모리 정리)
     return 0;
 }