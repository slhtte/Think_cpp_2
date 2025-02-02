#ifndef _TOWN_H_
#define _TOWN_H_

#include <string>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

struct Town_t
{
    std::string name;
    unsigned quantity;
    unsigned short high;
    enum weather_e : unsigned short
    {
    	RAINY = 0,
    	SNOWY,
    	CLOUDY,
    	CLEAR
    } weather;

    Town_t(const std::string &n = "abcdefg", const unsigned q = 0, const unsigned short h = 0, const weather_e w = RAINY)
        : name(n), quantity(q), high(h), weather(w) {}

    /*
    bool operator<(const Town_t &right) const
    {
        return quantity < right.quantity;
    }
    */

    bool operator<(const Town_t &right) const
    {
        return high < right.high;
    }

    bool find_high() const
    {
        if (high >= 2500 && high <= 3500)
        {
            return true;
        }

        return false;
    }

    std::string weather_as_string() const
    {
    	switch (weather)
    	{
    	case RAINY: return "RAINY";
    	case SNOWY : return "SNOWY";
    	case CLOUDY : return "CLOUDY";
    	case CLEAR : return "CLEAR";
    	default: return "RAINY";
    	}
    }

    static weather_e string_as_weather(const std::string &s)
    {
        if (s ==  "RAINY") return RAINY;
        if (s ==  "SNOWY") return SNOWY;
        if (s ==  "CLOUDY") return CLOUDY;
        if (s ==  "CLEAR") return CLEAR;

        return RAINY;
    }

    friend std::istream& operator>>(std::istream &in, Town_t &town)
    {
        in >> town.name;
        in >> town.quantity;
        in >> town.high;
        std::string s;
        in >> s;
        town.weather = Town_t::string_as_weather(s);

        return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const Town_t &t)
    {
        out << t.name << " " << t.quantity << " " << t.high << " " << t.weather_as_string();

        return out;
    }
};

bool less(const Town_t &left, const Town_t &right)
{
    return left < right;
}

#endif