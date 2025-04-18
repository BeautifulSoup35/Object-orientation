```
class bank{
    privat:
    public:
      생성자 생성하
};

int main(){
    return 0;
}
bank my_bank; 인스턴스 할당
```

    추상 클래스 : 추상 메서드가 하나 이상인 클래스
    추상 메서드 : 선언만 있고, 구현은 없는 메서드

super키워드 상속?

캡슐화: 은닉화 변수와 함수를 클래스로 감싼다 
• 클래스 내부의 세부 로직을 알 필요가 없음 → 클래스 변경이 외부 로직에 영향을 주지않음


변수 -> private
함수에서만 접근할수있


생성자 : main에서 자동으로 불러진다

class안에서 부르는 함수들은 구현할때 그 class안을 불러와서 생성한

```
class bank{
  private:
  public:
    void use_counter(int _in, int _out);
};

void bank :: use_counter(int _in, int _out){
    safe += _in;
    safe -= _out;

    cout << "입금: "<< _in<<endl;
    cout << "출금: "<< _out<<endl;
    cout << "금고: "<< safe<<endl;
}
```

main에서 즉 밖에서 그냥접근안되고 class의 객체를 통해서 접근한 
```
 bank my_bank;//객체 선언 인스턴스 할당
my_bank.use_counter(100, 20);
```





