#include <mcpp/io>

using namespace mcpp;

int main()
{
    int x = 0, y =1, z = 0, i;
    io::println("Sucesión de Fibonacci: ");
    for(i=1;i<=13;i++){
            z = y;
            y = y + x;
    io::println(y+", ");
        x = z;
    }
    return 0;
}
