#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

template <typename M > M myMax(M Num1, M Num2)
{
    return (Num1 > Num2) ? Num1 : Num2;
}
int main()
{

    /*while (Trials)
    {
        clsLoginScreen::ShowLoginScreen();
    }*/
    
    cout << myMax <int> (1, 3) << endl;
    cout << myMax <double>(5.5, 6.7) << endl;
    cout << myMax <char>('a', 'b') << endl;





    return 0;
}