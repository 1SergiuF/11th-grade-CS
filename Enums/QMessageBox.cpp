/*
  Enumerari
  CU ajutorul cuvintelor cheie (keywords) :
  class, struct, union, enum se creaza in C++
  noi tipuri de date

*/

#include <iostream>
using namespace std;

namespace Qt {

    class QMessageBox {
        public:
            enum Icon {
                Question = 4,
                Information = 1,
                Warning = 2
            };
    };
}

// :: Scope Resolution Operator (operator de rezolvare a domeniului)
int main()
{
    Qt::QMessageBox::Icon icon;
    icon = Qt::QMessageBox::Question;

    std::cout << icon;
}