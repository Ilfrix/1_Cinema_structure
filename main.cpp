#include "cinema.h"

int main(){
    /*
    Cinema c;
    c = c.create_film();
    c.show_info();
    City_cinema test;
    test.insert(c);
    test.find_cinema("Avatar");
    */
    Cinema c;
    c = c.create_film();
    City_cinema_vector tmp;
    tmp.insert(c);
    tmp.show();
    return 0;
}