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

함수 오버라이딩딩
