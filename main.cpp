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
    City_cinema all_cinema;
    while (true){
        int choice;
        std::cout << "Enter number of your choice:\n";
        std::cout << "1 - Enter one movie poster by keyboard\n";
        std::cout << "2 - Insert poster in table\n";
        std::cout << "3 - Delete all posters with date\n";
        std::cout << "4 - Show posters with film\n";
        std::cout << "5 - Show all movie posters in table(support)\n";
        std::cout << "0 - Finish program\n";
        std::cin >> choice;
        if (choice == 1){
            c = c.create_film();
        }
        else if (choice == 2){
            all_cinema.insert(c);
            std::cout << "End of word 2\n";
        }
        else if (choice == 3){
            Date d;
            int day, month, year;
            std::cout << "Enter day month year separated spaces or enters: ";
            std::cin >> day >> month >> year; 
            all_cinema.delete_cinema(Date(day, month, year));
        }
        else if (choice == 4){
            std::string name_film;
            std::cout << "Enter name of film: ";
            std::cin >> name_film;
            all_cinema.find_cinema(name_film);
        }
        else if (choice == 5){
            all_cinema.show_all();
        }
        else if (choice == 0){
            break;
        }
        
        City_cinema_vector tmp;
        tmp.insert(c);
        tmp.show();
    }
    return 0;
}