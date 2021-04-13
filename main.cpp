// string constructor
#include <iostream>
#include "String.h"

int main () {
    String s0 ("Initial string");

    // constructors used in the same order as described above:
    String s1;
    String s2 (s0);
    String s3 (s0, 8, 3);
    String s4 ("A character sequence");
    String s5 ("Another character sequence", 12);
    String s6 (10, 'x');
    //String s6b (10, 42);      // 42 is the ASCII code for '*'
    String s7 = s3 + s4;
    String s8 = "iheuehi";
    s8 += s0;
    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6;
    std::cout << "\ns7: " << s7 << "\ns8: " << s8 << '\n';
    return 0;
}