#include "numbermodulo.h"

NumberModulo::NumberModulo()
{

}

void NumberModulo::set_num(long long input)
{
    num = input;
}

long long NumberModulo::get_num()
{
    return num;
}

void NumberModulo::set_modulo(long long input) {
    if (input < 1) throw "Modulo is less than 1";
    modulo = input;
}
long long NumberModulo::get_modulo() {
    return modulo;
}
