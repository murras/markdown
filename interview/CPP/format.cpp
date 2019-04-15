#include <iostream>
using namespace std;

class CostEstimate {
   private:
    enum { NumTurns = 5 };
    int scores[NumTurns];
};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))  // 괄호를 유의하여 작성해야한다.
template <typename T>
inline void callWithMax(const T& a, const T& b) {
    cout << (a > b ? a : b);
}
int main() {
    int a = 5, b = 0;
    int f =
    cout << f << CALL_WITH_MAX(++a, b);       // a가 2번 증가
    cout << CALL_WITH_MAX(++a, b + 10);  // a가 1번 증가
    callWithMax(a, b);
}