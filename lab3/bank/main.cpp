#include <iostream>
#include <ostream>
//
// Created by smmm on 15.03.2025.
//



class ContactList
{
public:
	ContactList()
	{
	}

private:
	Actor m_actor1;
};

class Actor
{
public:
	explicit Actor(const ContactList& contact_list)
		: m_cl{ contact_list }
	{
	}

private:
	ContactList m_cl;
};

int main(int argc, char* argv[])
{
	B b{};
	return 0;
}