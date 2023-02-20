#include "cinema.h"

int main(){
    Cinema c;
    c = c.create_film();
    c.show_info();
    City_cinema test;
    test.insert(c);
    test.find_cinema("Avatar");
    return 0;
}