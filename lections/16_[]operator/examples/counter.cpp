class Counter
{
	int value;

public:
	Counter(int v = 0)
		: value(v)
	{
	}

	Counter& operator++()
	{
		value += 1;
		return *this;
	}

	Counter operator++(int)
	{
		Counter temp = *this;
		value += 1;
		return temp;
	}
};

int main()
{
	Counter c{ 1 };
	c++;
}
