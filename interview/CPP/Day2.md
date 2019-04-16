## const의 활용

### const와 포인터

class EXAMPLE{ int ex; }; // 예제 클래스
const EXAMPLE * ep; // 위와 아래의 코드는 같은 의미이다.
EXAMPLE const * ep; // *과 const의 위치를 보고 판단하자.

char ex[] = "Hello"

char * p = ex; // 포인터와 데이터 모두 변수.
const char * p = ex; // 포인터는 변수, 데이터는 상수. const T * 
char * const p = ex; // 포인터는 상수, 데이터는 변수. T * const
const char * const p = ex; // 포인터와 데이터 모두 상수.

### STL iterator에서의 const
using namespace std;
vector<int> v;
const vector<int>::iterator iter = v.begin(); // T * const와 대응
*iter = 10; // 데이터는 변경 가능.
++iter; // 반복자는 다른 대상을 가리킬 수 없다.

vector<int>::const_iterator const_iter = v.begin(); // const T * 과 대응.
*const_iter = 10; // 데이터 변경 불가능
++const_iter; // 반복자는 다른 대상을 가리킬 수 있다.

### 함수에서의 const

- return Type이 const인 경우.

const EXAMPLE operator*(const EXAMPLE& a, const EXAMPLE& b);

EXAMPLE a, b, c;
if(a+b = c)와 같은 원치 않았던 오류를 막을 수 있다.

### 상수 멤버 함수
