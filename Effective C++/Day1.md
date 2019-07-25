

## #define 대신 const, enum, inline 사용하기
### 키워드 
`define`, `const`, `enum`, `inline`

\#define을 쓰면 소스 코드가 컴파일러에게 가기 전에 선행처리자가 숫자 상수로 바꿔버리기 때문에 컴파일러가 쓰는 기호 테이블에 들어가지 않는다.

때문에 숫자 상수로 대체된 코드에서 컴파일 에러가 발생하게 되면 에러 메시지에 숫자 상수가 나와버리기 때문에 자신이 작성하지 않은 코드인 경우 큰 혼란을 겪을 수 있다.

#### 상수 포인터를 정의하는 경우
상수 포인터는 보통 헤더 파일에 넣는 것이 상례이다.

포인터와 포인터가 가리키는 대상 모두 `const`로 선언하는 것이 좋다.

```cpp
const char* const Name = "EXAMPLE";
const string Name("EXAMPLE");
```

#### 클래스 멤버로 상수를 정의하는 경우

```cpp
class GamePlayer {
   private:
    static const int NumTurns = 5;  // 상수 부분, 선언 부분, 초기값이 있다.
    int scores[NumTurns];           // 상수 사용 부분
};
```

- 헤더 파일에 둔다. `NumTurns`는 선언되어있고 정의되어 있지 않다.

```cpp
const int GamePlayer::NumTurns; // NumTurns의 정의
```

- 정의 부분은 헤더 파일이 아닌 구현 파일에 둔다. 정의에는 *초기값이 없다*. 

\#define은 `private` 같은 기능이 없기 때문에 캡슐화의 기능이 없다. 그렇기 때문에 `const`를 쓰는 것이 좋다.

오래된 컴파일러에서는 반대의 경우도 있다. 선언 부분에 초기값이 없고 정의 부분에 초기값을 정해준다. 하지만 아래와 같은 예외사항이 있을 수 있다.

```cpp
class CostEstimate {
   private:
    enum { NumTurns = 5 }; // 나열자를 이용.
    int scores[NumTurns];
};
```

- `enum`은 `const`보단 `#define`에 가깝다. `enum`과 `#define`의 주소를 얻어내는 것은 불가능하지만 `const`는 가능하다. 

#### 매크로 함수로 사용하는 경우

```cpp
#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))  // 괄호를 유의하여 작성해야한다.
int a = 5, b = 0;
cout << CALL_WITH_MAX(++a, b);       // a가 2번 증가
cout << CALL_WITH_MAX(++a, b + 10);  // a가 1번 증가
```

```cpp
template <typename T>
inline void callWithMax(const T& a, const T& b) {
    cout << (a > b ? a : b);
}
```

`inline`을 이용해서 함수를 쓰면 진짜 함수이기 떄문에 유효 범위 및 접근 규칙을 적용할 수 있다. 괄호 때문에 생기는 혼란도 없앨수 있다.