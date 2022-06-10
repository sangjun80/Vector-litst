//0.1 

#include <iostream>

using namespace std;



struct List
{
	int Value;
	List* Back;
};

void AddObject(List* _Next, const int& _Value);

void Output(List* _Next);

//숙제 인설트 함수 만들기 하면 지우개만들기

void Instert();

int main(void)
{
	List* NumberList = new List;

	NumberList->Value = 0;
	NumberList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
		AddObject(NumberList, 1 * 10 + 10);
	Output(NumberList);


	//cout << NumberList->Value << endl;
	//cout << NumberList->Back->Value << endl;
	//cout << NumberList->Back->Back->Value << endl;
	



	return 0;
}

void AddObject(List* _Next, const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Next->Back = Temp;

	}
	else
		AddObject(_Next->Back, _Value);
}


void Output(List* _Next)
{
	cout << _Next->Value << endl;
	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

