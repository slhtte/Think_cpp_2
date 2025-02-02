#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstring>

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

class DataBase
{
    std::string file_name;
    unsigned short string_count;
public:
	DataBase() :
	    file_name("database.bin"), string_count(0)
	 {
	 	std::ofstream out(file_name, std::ios::binary);
	 	Person p { 123098, "Tver", "Pokrovka", 24 };
	 	out.write(reinterpret_cast<const char *>(&p), sizeof(p));
	 	++string_count;
	 }

	~DataBase()
	{
		system("rm -f database.bin");
	}
	size_t query(size_t ssn);
	Person retrieve(size_t rn);
	void add(const Person &p);
};

size_t DataBase::query(size_t ssn)
{
    size_t s;
    unsigned count = 0;
    std::ifstream db(file_name, std::ios::binary);
    db.seekg(0, std::ios::beg);

	while (db.read(reinterpret_cast<char *>(&s), sizeof(ssn)))
	{
		if (s == ssn)
		{
			return count;
		}

		++count;
	}

	return (size_t)-1;
}

Person DataBase::retrieve(size_t rn)
{
	assert(rn <= string_count);

	std::ifstream db(file_name, std::ios::binary);
	db.seekg(+(sizeof(Person) * rn), std::ios::beg);
	Person p;
	db.read(reinterpret_cast<char *>(&p), sizeof(p));

	return p;
}

void DataBase::add(const Person &p)
{
	std::ofstream db(file_name, std::ios::binary);
	db.seekp(0, std::ios::end);
	db.write(reinterpret_cast<const char *>(&p), sizeof(Person));
	++string_count;
}

int main()
{
	DataBase db;
	const size_t ssn = 123098;
	std::ofstream out("back_up.txt");

	if (db.query(ssn) != (size_t)-1)
	{
		out << db.retrieve(db.query(ssn)) << std::endl;
	}
	Person p { 890321, "Moskow", "Tverskaya", 42 };
	db.add(p);
	if (db.query(890321) != (size_t)-1)
	{
		out << db.retrieve(db.query(890321)) << std::endl;
	}
}