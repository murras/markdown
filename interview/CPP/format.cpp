#include <iostream>
using namespace std;

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
