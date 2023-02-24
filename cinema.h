#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//support structure
struct Date
{
    int day, month, year;
    Date (){
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }
    Date (int day, int minute, int year){
        this->day = day;
        this->month = minute;
        this->year = year;
    }
};
std::ostream& operator << (std::ostream &os, const Date &d)
{
    return os << d.day << ' '  << d.month << ' ' << d.year;
}
bool operator == (Date d1, Date d2)
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
//support strucrute
struct Time
{
    int minute, hour;
    Time(){
        this->minute = 0;
        this->hour = 0;
    }
    Time(int hour, int minute){
        this->minute = minute;
        this->hour = hour;
    }
};
std::ostream& operator << (std::ostream &os, const Time &t)
{
    return os << t.hour << ' '  << t.minute;
}

//base structure
struct Cinema
{
    std::string cinema_name;
    std::string film_name;
    Date date_film;
    Time time_of_start;
    float cost;

    Cinema(){
        this->cinema_name = "";
        this->film_name = "";
        this->date_film = Date();
        this->time_of_start = Time();
        this->cost = 0;
    }

    Cinema (std::string cinema_name, std::string film_name, Date date_film, Time time_of_start, float cost){
        this->cinema_name = cinema_name;
        this->film_name = film_name;
        this->date_film = date_film;
        this->time_of_start = time_of_start;
        this->cost = cost;
    }
    //create new note
    Cinema create_film(){
        std::string cinema_name, film_name;
        float cost;
        int day, month, year, minute, hour;
        std::cout << "Input cinema name(without space): ";
        std::cin >> cinema_name;
        std::cout << "Input film name(without space): ";
        std::cin >> film_name;
        std::cout << "Input date(format day month year): ";
        std::cin >> day >> month >> year;
        std::cout << "Input time(format hour Minute): ";
        std::cin >> hour >> minute;
        std::cout << "Input cost of film: ";
        std::cin >> cost;
        return Cinema(cinema_name, film_name, Date(day, month, year), Time(hour, minute), cost);
    }
    //show info about object
    void show_info(){ 
        if (cinema_name == "") return;
        std::cout << "Name of cinema: " << cinema_name << "\nName of film: " << film_name;
        std::cout << "\nDate is: " << date_film << "\nTime is: " << time_of_start;
        std::cout << "\nCost of film is: " << cost << '\n';
    }
};
//structure for keeping note, using static array
struct City_cinema
{
    int current_len;
    int max_len;
    Cinema lst_cinema[100];

    City_cinema(){
        this->current_len = 0;
        this->max_len = 100;
    }
    //insert cinema object before first entry in array
    void insert(Cinema c){ 
        int tmp;
        for (int i = 0; i <= current_len; ++i){
            if (c.cinema_name == lst_cinema[i].cinema_name){
                tmp = i;
                break;
            }
        }
        std::cout << tmp << '\n';
        if (tmp < max_len){
            for (int i = current_len; i >= tmp; --i)    lst_cinema[i] = lst_cinema[i - 1];  //отдебагать
            lst_cinema[tmp] = c;
            ++current_len;
        }   else{
            throw "Index out of range";
        }
    }
    //delete all note with that date
    void delete_cinema(Date d){ 
        int k = 0, j = 0;
        for (int i = 0; i < current_len; ++i){
            if (lst_cinema[i].date_film == d){
                k = (k == 0) ? i : k;
                j = i;
            }
        }
        --j;
        for (int p = k; p <= j; ++p) lst_cinema[p] = lst_cinema[p + 1];
        current_len -= (j - k);
    }
    //output all note with that name
    void find_cinema(std::string name_film){ 
        for (int i = 0; i < current_len; ++i){
            if (lst_cinema[i].film_name == name_film)   std::cout << lst_cinema[i].cinema_name << ' ';
        }
    }
    void show_all(){
        for (int i = 0; i < this->current_len; ++i) lst_cinema[i].show_info();
    }
        
};
//structure for keeping note, dinamic array
struct City_cinema_d
{
    int cur_len;
    int max_len;
    Cinema *lst_cinema;

    City_cinema_d(){
        this->cur_len = 0;
        this->max_len = 100;
        this->lst_cinema = new Cinema[100];
    }
    //insert cinema object before first entry in array
    void insert(Cinema c){ 
        int tmp;
        if (cur_len == max_len){
            Cinema *new_cinema = new Cinema[max_len*2];
            max_len *= 2;
            for (int i = 0; i < cur_len; ++i){
                new_cinema[i] = lst_cinema[i];
            }
            lst_cinema = new_cinema;
        }
        for (int i = 0; i < cur_len; ++i){
            if (c.cinema_name == lst_cinema[i].cinema_name){
                tmp = i;
                break;
            }
        }
        for (int i = cur_len; i >= tmp; --i)    lst_cinema[i] = lst_cinema[i - 1];
        lst_cinema[tmp] = c;
        ++cur_len;
        
    }
    //delete all note with that date
    void delete_cinema(Date d){ 
        int k = 0, j = 0;
        for (int i = 0; i < cur_len; ++i){
            if (lst_cinema[i].date_film == d){
                k = (k == 0) ? i : k;
                j = i;
            }
        }
        --j;
        for (int p = k; p <= j; ++p) lst_cinema[p] = lst_cinema[p + 1];
        cur_len -= (j - k);
    }
    //output all note with that name of film
    void find_cinema(std::string name_film){    
        for (int i = 0; i < cur_len; ++i){
            if (lst_cinema[i].film_name == name_film)   std::cout << lst_cinema[i].cinema_name << ' ';
        }
    }
};
bool equel_name_film(Cinema a, Cinema b){
    return a.cinema_name == b.cinema_name;
}

bool equel_date(Cinema a, Cinema b){
    return a.date_film == b.date_film;
}
//structure for keeping note, using vector
struct City_cinema_vector
{
    std::vector <Cinema> cinema_city;
    //insert cinema object before first entry in array
    void insert(Cinema c){  
        auto it = lower_bound(cinema_city.begin(), cinema_city.end(), c, equel_name_film);
        cinema_city.insert(it, c);
    }
    //delete all note with that date
    void delete_cinema(Date d){ 
        Cinema c;
        c.date_film = d;
        auto it = lower_bound(cinema_city.begin(), cinema_city.end(), c, equel_date);
        while (it != cinema_city.end()){
            cinema_city.erase(it);
            it = lower_bound(cinema_city.begin(), cinema_city.end(), c, equel_date);
        }  
    }
    //show all note with that cinema name
    void show_cinema_name(std::string s){
        for (auto a: cinema_city){
            if (a.film_name == s){
                a.show_info();
            }
        }
    }
    //support method, show all note in vector
    void show(){    
        for (auto a : cinema_city){
            a.show_info();
        }
    }
};