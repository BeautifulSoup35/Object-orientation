#상속/다향성

```
class monster_a : monster{

};

class monster_a : public monster // private빼고 다 가져옴

class monster_a : private monster // 모든걸 private으로
```

monster에서 상속받은 monster_a class 작성성

```


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
```

재정의 된 void attack_special() 함수
상속 클래슨 자식이 불릴때 부모 클래스를 먼저 호출하고 해야함함

```
    monster(){}; 부모의 기본 생상자? 기본 클래스?
```

함수 오버라이딩

단일상속 -> 하나의 부모로 부터 물려받는 성질
다중상속 -> 여러개 성질을 물려받는다 : 자바는 다중 상속을 허용하지 않는다

#생성자
객체가 생성되기위해 호출되는 함수
"ex) monster(){};"

````
class A{

};

int main(){
    A a;
    return 0;
}
```
작동됨 -> 자동으로 생성자는 만들어지니까

##클래스에 값 추가 (함수, 변수수)##
```
private:
        int data;
    public:
        A(){data = 0;}
```
부모 생성자를 먼저 호출하는 경우 부모 클래스가 두 개일때는?
```
class AA : public A{
    public:
        AA(){
            cout << "aa부름"<<endl;
            A();
        };
};
```

이런 형태일때 super 메서드 사용한다

```
int main(){
    A j(500);
    j.printInfo();
    AA a;//부모인 A클래스 다음에 AA클래스 불러짐짐
    a.printInfo();
    return 0;
}
````

A의 j라는 객체를 만듬 ->

다중상속 방법

```
class monster : public monsterm, charcter{

}
```

예전의 인스턴스를 가져와야할때 복사 인스턴스스

포인터로 선언시 이러진 부분이 공유되어 얕은 복사만 된다
그럴때엔 그 주소에 있는 값을 일일이 복사를 해서 가져와야한다
단 원본 A 의 값은 회손되면 안된다 CONST

```
 p = new int[100];
    for(int i =0; i , 100; i++){
        p[i] = ref.p[i];
    }
```

construct
기본생상자 = 기본으로 만들어준다
어떤 데이터를 초기화하고 싶을때 만들어서 코딩한다

자식클래스 -> 기본 생성자 역시 무엇을? 따로 안적어도 컴파일러가 알아서

복사 생성자도 억지로 넣지 않으면 알아서 넣어준다 포인트가 있을땐 카피를 명시적으로 해줘야한다

free를 안해도 되는이유 -> 소멸자
우리가 의도적으로 동적할당시키면 소멸자가 암묵적으로 작동못해서 명시적으로 해줘야함
~A();
