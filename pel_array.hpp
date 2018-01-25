/*
   pel_array.hpp
   --------------------------------------------------
   UEM | PEL 2017/2018
*/

#ifndef PEL_arrayHPP_INCLUDED
#define PEL_arrayHPP_INCLUDED

#include <cstdlib>
#include <stdexcept>

namespace pel {

template<typename T, std::size_t N>
struct Array {
   T array[N];

   // -------------------------------------------------------------------------
   // acceso:

   T&       operator[](std::size_t idx)       { return array[idx]; }
   T const& operator[](std::size_t idx) const { return array[idx]; }

   T*       begin()       { return &array[0]; }
   T const* begin() const { return &array[0]; }

   T*       end()       { return &array[N]; }
   T const* end() const { return &array[N]; }

   T& at(std::size_t idx) // control de acceso (puede emitir std::out_of_range)
   {
      boundsChecking(idx);
      return array[idx];
   }

   T const& at(std::size_t idx) const
   {
      boundsChecking(idx);
      return array[idx];
   }

   T&       front()       { return array[0]; }
   T const& front() const { return array[0]; }

   T&       back()       {return array[N-1]; }
   T const& back() const {return array[N-1]; }

   // -------------------------------------------------------------------------
   // capacidad:

   std::size_t size() const { return N; }
   bool       empty() const { return (N==0); }

private:
   void boundsChecking(std::size_t idx) const
   {
       if (idx >= N)
          throw std::out_of_range{"Invalid index"};
   }
};

} // pel NAMESPACE

#endif // PEL_arrayHPP_INCLUDED
