## const의 활용

### const와 포인터

```cpp
class EXAMPLE {int ex; }; // 예제 클래스
const EXAMPLE* ep;  // 위와 아래의 코드는 같은 의미이다.
EXAMPLE const* ep;  // *과 const의 위치를 보고 판단하자.
```

```cpp
char ex[] = "Hello";

char* p = ex;              // 포인터와 데이터 모두 변수.
const char* p = ex;        // 포인터는 변수, 데이터는 상수. const T *
char* const p = ex;        // 포인터는 상수, 데이터는 변수. T * const
const char* const p = ex;  // 포인터와 데이터 모두 상수.
```


### STL iterator에서의 const
```cpp
using namespace std;
vector<int> v;
const vector<int>::iterator iter = v.begin();  // T * const와 대응
*iter = 10;  // 데이터는 변경 가능.
++iter;      // 반복자는 다른 대상을 가리킬 수 없다.

vector<int>::const_iterator const_iter = v.begin();  // const T * 과 대응.
*const_iter = 10;  // 데이터 변경 불가능
++const_iter;      // 반복자는 다른 대상을 가리킬 수 있다.
```


### 함수에서의 const

- return Type이 const인 경우.

```cpp
const EXAMPLE operator*(const EXAMPLE& a, const EXAMPLE& b);
EXAMPLE a, b, c;
```

`if(a+b = c)`와 같은 원치 않았던 오류를 막을 수 있다.

### 상수 멤버 함수

함수 내에서 클래스의 멤버를 변경할 수 없다.

아래 코드를 보면 `const`의 유무로 오버로딩이 가능하다는 것을 알 수 있다.

```cpp
class EXAMPLE {
   private:
    string text;

   public:
    EXAMPLE(string s) : text(s){};
    const char& operator[](int position) const {
        cout << "const - const ";
        return text[position];
    }
    char& operator[](int position) {
        cout << "var ";
        return text[position];
    }
};

int main() {
    EXAMPLE e("var");           // 변수
    const EXAMPLE ce("const");  // 상수

    cout << e[0] << '\n';   // 출력 : var v
    cout << ce[0] << '\n';  // 출력 : const - const c
}
```

#### 비트 수준 상수성과 논리적 상수성

상수 멤버 함수여도 주솟값을 통해 값이 바뀔 수 있다. 이런 경우에 비트 수준 상수성은 갖기 때문에 컴파일러에서 알아챌수가 없다.

상수 멤버 함수에서도 멤버 변수를 수정할 수 있게 `mutable`을 사용할 수 있다.

```cpp
class EXAMPLE {
   private:
    mutable bool valid;
    mutable int len;
    string text;

   public:
    int text_length() const {
        valid = true;
        len = text.length(); // valid와 len을 수정할 수 있다.
        return len;
    }
}
```

상수 멤버 함수와 비상수 멤버함수가 기능적으로는 동일하게 구현되어 있다면 코드 중복을 피하기 위해 `const_cast`와 `static_cast`를 이용한다. 

이때 비상수 멤버함수가 상수 멤버함수를 호출하게끔 한다. 반대의 경우에는 상수 멤버 함수가 의미와는 다르게 비상수 멤버함수를 호출함으로써 클래스 내부를 변경할 수 있기 때문이다.