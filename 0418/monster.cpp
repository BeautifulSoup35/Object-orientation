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
    virtual void attack_special();//overriding ����

};


class monster_a : public monster{
    //���� ������
    public: 
    virtual void attack_special() override;

};

class monster_b : public monster{
    //���� ������
    public: 
    virtual void attack_special() override;

};
//�Լ����� �籸��
void monster_a :: attack_special(){
    cout << "���ޱ� ����" <<endl;

}

void monster_b :: attack_special(){
    cout << "�ƿ���Ŭ ����" <<endl;
    
}


monster :: monster(int _hp, int _power){
    hp = _hp;
    power = _power;

    cout << "monster �� �����Ǿ����ϴ� ���� ü����: " << hp<< endl;
}
void monster :: get_demage(int _demage){
    hp -= _demage;

    cout <<"ü���� '"<<_demage<< "' ��ŭ ���ϴ�"<< endl;
}
void monster :: attack(){
    
}
void monster :: attack_special(){
    
}
int main(){
  
    monster forst_monster(100, 20);
    // forst_monster.get_demage(20);
    // monster sea_monster(60, 50);

    
    monster_a sky_monster;
    // sky_monster.attack_special();
    // forst_monster.attack_special();


    monster *p = &forst_monster;
    p-> attack_special();//���ޱ� ����
    p = &sky_monster;
    p->attack_special();//���ޱ� ���� ??
    return 0;
}
    