#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

class Vanya
{
public:
	Vanya(const std::string& name)
		: m_name(name)
	{
	}

	void SetName(const std::string& name)
	{
		m_name = name;
		throw std::runtime_error("Vanya: exception after changing name");
	}

	void Print() const
	{
		std::cout << "Vanya: " << m_name << std::endl;
	}

private:
	std::string m_name;
};

class Petya
{
public:
	Petya(const std::string& name, int birthYear)
		: m_name(name)
		, m_birthYear(birthYear)
	{
	}

	void SetName(const std::string& name, int birthYear)
	{
		m_name = name;

		if (birthYear < 1900 || birthYear > 2026)
		{
			throw std::runtime_error("Petya: invalid birth year");
		}

		m_birthYear = birthYear;
	}

	void Print() const
	{
		std::cout << "Petya: " << m_name << ", " << m_birthYear << std::endl;
	}

private:
	std::string m_name;
	int m_birthYear;
};

class Masha
{
public:
	Masha(const std::string& name, int birthYear)
		: m_name(name)
		, m_birthYear(birthYear)
	{
	}

	void SetName(const std::string& name, int birthYear)
	{
		if (birthYear < 1900 || birthYear > 2026)
		{
			throw std::runtime_error("Masha: invalid birth year");
		}

		std::string newName = name;
		int newBirthYear = birthYear;

		m_name = newName;
		m_birthYear = newBirthYear;
	}

	void Print() const
	{
		std::cout << "Masha: " << m_name << ", " << m_birthYear << std::endl;
	}

private:
	std::string m_name;
	int m_birthYear;
};

class AlexeyMalov
{
public:
	AlexeyMalov(const char* name) noexcept
	{
		SetName(name);
	}

	void SetName(const char* name) noexcept
	{
		std::strncpy(m_name, name, sizeof(m_name) - 1);
		m_name[sizeof(m_name) - 1] = '\0';
	}

	void Print() const noexcept
	{
		std::cout << "Alexey Malov: " << m_name << std::endl;
	}

private:
	char m_name[64] = {};
};

int main()
{
	Vanya vanya("Ivan");

	try
	{
		vanya.SetName("Vano");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	vanya.Print();

	std::cout << std::endl;

	Petya petya("Petr", 2000);

	try
	{
		petya.SetName("Petro", 1800);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	petya.Print();

	std::cout << std::endl;

	Masha masha("Maria", 2001);

	try
	{
		masha.SetName("Mariya", 1800);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	masha.Print();

	std::cout << std::endl;

	AlexeyMalov alexey("Alexey");

	alexey.SetName("Alexey Malov");
	alexey.Print();

	return 0;
}
