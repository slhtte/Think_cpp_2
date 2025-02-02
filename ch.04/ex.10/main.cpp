#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

struct Addr
{
	static const short SIZE = 50;

	char  sity[SIZE];
	char  street[SIZE];
	short house;

    std::string str() const
    {
    	return std::string(sity) + " " + std::string(street) + " " + std::to_string(house);
    }

    Addr() : 
        house(0)
     {
     	memset(sity, '\0', SIZE);
     	memset(street, '\0', SIZE);
     }

     Addr(const std::string &ssity, const std::string &sstreet, const short hhouse) :
         house(hhouse)
     {
     	memcpy(sity, ssity.c_str(), ssity.size());
     	memcpy(street, sstreet.c_str(), sstreet.size());
     }
};

struct Person
{
	size_t ssn;
	Addr   addr;

	Person() {}
	Person(const size_t &s, const std::string &ssity, const std::string &sstreet, const short hhouse) :
	    ssn(s), addr(ssity, sstreet, hhouse) {}
};

std::ostream& operator<<(std::ostream &os, const Person &p)
{
	return os << p.ssn << " " << p.addr.str();
}

int main()
{
	std::ifstream in("back_up.txt");
	std::ofstream out("database.bin", std::ios::binary);
    std::string tmp, ssity, sstreet;
    size_t ssn;
    short hhouse;
    

    while (getline(in, tmp))
    {
    	std::stringstream ss;
    	ss << tmp;
    	ss >> ssn >> ssity >> sstreet >> hhouse;
    	Person p{ ssn, ssity, sstreet, hhouse };
    	std::cout << p << std::endl;
    	out.write(reinterpret_cast<const char *>(&p), sizeof(p));
    }

    std::cout << std::endl;

    Person pp;

    while (out.read(reinterpret_cast<char *>(&pp), sizeof(pp)))
    {
    	std::cout << pp << std::endl;
    }
}