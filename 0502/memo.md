```
Vehicle() : vehicleId(""), manufacturer(""), model(""), year(0), dailyRate(0.0) {
         cout << "Vehicle 기본 생성자 호출" << endl;
     }

```

생성자 초기화

```
@brief
@details
```

가상 소멸자 호출 필수: 파생 클래스의 소멸자를 올바르게 호출하기 위해

```
string getVehicleId() const { return vehicleId; }
```

const 오류방지 이 함수에서 변경 못하도록

파생 클래스

```
 ~Car() override
```

override가 없더라도 상관없음

추상 함수로 선언 안하게 되면

```
A *p = new AA();
    p->print();// a 가 나온다
```

```
    virtual void print()//a
    virtual void print() override//aa
    void print()//ab
```

AA.print()
AB역시 그냥 나온다 묵시적으로 변환해준다 하지만 코드상 오류가 있을수 있다
하지만 override 필수로 해야한다
why?
??컴파일러는 가상함수임을 그냥 안다 권장사항일뿐

**_업캐스팅_** run 타임에서 결정정

```
A *p = new AA();//추상클래스 AA 허용안됨
```

**_순수 가상함수_**란 : 몸통이없어서 인스턴스가 만들어지지 않는 함수입니다 파생클래스를 만들기 위해 존재합니다

```
virtual void print() = 0;
```

**_가상 소멸자_**

```

 ~A(){cout << "A 가상 소멸자"<<endl;}
 A a; //오류
 A *p = new AA();// A가 작동

 virtual ~A(){};//가상 소멸자
    A *p = new AA();
    delete p;//AA가 작동된다
```

가상 소멸자는 업캐스팅 되지 않으면 객체에서 정의한 소멸자 부모클래스 소멸자 호출된다
업캐스팅되면 업캐스팅 된 객체의 소멸자만 생성

##가상 소멸자 out
~AA
~A

##그냥 소멸자
~A

동적할당 하는방법
int count = 10;
int \* arr = new int[count];

**_동적할당 오류 _**

```
    string *real = new string[100];
    string *event = new cahr[100];
    *real = "jdkskdsl @jkl.com";
    *event = "qwer@fjkd.com";
```

```
    A a1;
    a1.add_one();
    a1.print();

    A a2;
    a2.add_one();
    a2.print();
```

결과값 1 1

```
A( ):no(0){};//초기화 불가능 static
    static int no;

    int A :: no = 0; 선언 클래스 외부에서 초기화를 해야한다
```

결과값 1 2
A라고 하는 클래스에 된다라는 점에서 다르다 A라는 클래스를 몇개 생성되는지 확인가능

static >> 인스턴스 없어도 호출가능하다

**_왜 오류가 날까_**

```
int cnt = 0;
static void print_info(){cout << cnt << endl;}
```

만들어지지 않은 스테틱 함수를 참조해라는 뜻이 된다 즉 static 변수만 접근 가능하다
정적맴버는 클래스다 한 번 메모리에 할당

**_static 예시_**

```
static int add(int no1, int no2) {return no1+ no2;}
cout << A::add(1, 2);
```

**_메모리값이 헤제된게 맞는지 확인하기_**

```
staticbool check(){
if (cnt >0)return false;
else return true;

    }
```
