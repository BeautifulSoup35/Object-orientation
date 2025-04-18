#include<iostream>
#include<string>
using namespace std;
class monster{
    private:
        int hp;
        int power;
    public:
    monster(){};
    monster(int _hp, int _power);
    void get_demage(int _demage);
    void attack();
    void attack_special();

};


class monster_a : public monster{
    //접근 지정자
    public: 
    void attack_special();

};

class monster_b : public monster{
    //접근 지정자
    public: 
    void attack_special();

};
//함수역시 재구현
void monster_a :: attack_special(){
    cout << "인텡글 공격" <<endl;

}

void monster_b :: attack_special(){
    cout << "아웃택클 공격" <<endl;
    
}


monster :: monster(int _hp, int _power){
    hp = _hp;
    power = _power;

    cout << "monster 가 생성되었습니다 현재 체력은: " << hp<< endl;
}
void monster :: get_demage(int _demage){
    hp -= _demage;

    cout <<"체력이 '"<<_demage<< "' 만큼 깎겼니다"<< endl;
}
void monster :: attack(){
    
}
void monster :: attack_special(){
    
}
int main(){
    monster forst_monster(100, 20);
    forst_monster.get_demage(20);
    monster sea_monster(60, 50);

    monster_a sky_monster;
    sky_monster.attack_special();
    return 0;
}