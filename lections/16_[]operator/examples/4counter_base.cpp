class Counter
{
	int value;

public:
	Counter(int v = 0)
		: value(v)
	{
	}
};

int main()
{
	Counter c{ 1 };
	// c++;
}
