//0.2

#include <iostream>

using namespace std;



struct List
{
	List* Front;
	int Value;
	List* Back;
};


void push_back(List* _Current, const int& _Value);
void insert(List* _Current, const int _Where, const int& _Value);
void erase(List* _Current, const int _Where);

void Output(const List* _Current);


int main(void)
{
	List* NumberList = new List;

	NumberList->Value = 0;
	NumberList->Back = nullptr;


	for (int i = 0; i < 10; ++i)
		push_back(NumberList, i * 10 + 10);


	insert(NumberList, 2, 15);
	Output(NumberList);


	erase(NumberList, 2);
	Output(NumberList);


	return 0;
}

void push_back(List* _Current, const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;
		
		//¹º°¡ ºñ¾îÀÕÀ½

		Temp->Back = nullptr;

		_Current->Back = Temp;
	}
	else
		push_back(_Current->Back, _Value);
}

void insert(List* _Current, const int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Value = _Value;

		Temp->Back = _Current->Back;
		_Current->Back = Temp;
	}
	else
		insert(_Current->Back, _Where - 1, _Value);
}


List* Front = nullptr;

void erase(List* _Current, const int _Where)
{
	if (_Where == 0)
	{
		//_Current->Front;
		//Temp->Front = _Current;

		

		delete _Current;
		_Current = nullptr;
	}
	else
	{
		Front = _Current;
		erase(_Current->Back, _Where - 1);
	}
}

void Output(const List* _Current)
{
	cout << _Current->Value << endl;

}

/*


*/