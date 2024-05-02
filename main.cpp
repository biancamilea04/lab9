#include <iostream>
#include "Map.h"

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

   // m.print();
    //m.print();
    //std::cout << m.Delete(10)<<std::endl;
   // if (m.Delete(20) == true) {
    //    m.print();
    //}
    //const char* A;
    //std::cout << m.Get(10, A);

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    printf("\n");

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
  
    return 0;
}


