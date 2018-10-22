#include <mcpp/io>
#include <mcpp/rng>
#include <array>
int main()
{
 using namespace std;
 using namespace mcpp;
 array<int, 10> numbers = {1, -5, 0, 11, 7, 8, 5, 12, -1, 2};
 rng::sort(numbers, greater<>{});
 auto en_intervalo = [](int i){ return i > 2 && i < 10; };
 auto por_dos = [](int i){ return i *= 2; };
 for (int i : numbers | rng::view::filter(en_intervalo)
 | rng::view::transform(por_dos))
 io::print("{} ", i);
}
