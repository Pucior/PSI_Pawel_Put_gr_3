//nauka perceptronu funkcji logicznej OR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
class Perceptron
{
public:
	bool *in; //wektor liczb 0 i 1 na wejsciu
	float *weight; //wektor wag
	float out; //liczba na wyjsciu
	int numberOfNeurons; //w tym wypadku bedzie zawsze 2 (funkcja logiczna dwoch zmiennych)
	float learnCoefficient; //wspolczynnik nauczania
	bool expectAnswer; //w tym wypadku bool, bo wartosc oczekiwana bedzie 0 lub 1
	float bias; //wartosc odchylenia
	Perceptron (bool *tab1, float *tab2, float b, int n, float l, bool e) //konstruktor
	{
		in = tab1;
		weight = tab2;
		bias = b;
		numberOfNeurons = n;
		learnCoefficient = l;
		expectAnswer = e;
	}
	void learnOneCase(int *numberOfCases, int *numberOfLoops) //funkcja dobierajaca wagi i uczaca dla pojedynczego przypadku
	{
		checkPerceptronActivity(); //sprawdzanie wartosci na wyjsciu dla podanych wag
		if (expectAnswer == out) //jezeli wartosc wychodzi taka jak oczekiwana, przechodzimy do nastepnego przypadku bez zmiany wag
			(*numberOfCases)++;
		while (expectAnswer != out) //dopoki oczekiwana odpowiedz rozni sie od uzyskanej zmieniamy wagi
		{
			(*numberOfCases) = 0; //przy zmianie wag powrot do pierwszego przypadku i sprawdzanie od nowa
			for (int i = 0; i < numberOfNeurons; i++)
			{
				weight[i] += learnCoefficient * (expectAnswer - out) * in[i];
			}
			bias += learnCoefficient * (expectAnswer - out);
			checkPerceptronActivity();
			(*numberOfLoops)++; //zwiekszamy liczbe petli nauki
		}
	}
	void checkPerceptronActivity() //funkcja sprawdzaj¹ca, czy perceptron zwraca 1 czy 0
	{
		out = 0;
		for (int i = 0; i < numberOfNeurons; i++)
			out += in[i] * weight[i];
		out += bias;
		if (out < 0)
			out = 0;
		else
			out = 1;
	}
	void learn() //funkcja nauczajaca dla wszystkich przypadkow funkcji logicznej and
	{
		int numberOfLoops = 0;
		int numberOfCases = 0;
		while (numberOfCases < 4)
		{
			if (numberOfCases == 0) //przypadek pierwszy, na wejsciu 0, 0, oczekujemy 0
			{
				in[0] = 0;
				in[1] = 0;
				expectAnswer = 0;
				learnOneCase(&numberOfCases, &numberOfLoops);
			}
			if (numberOfCases == 1) //przypadek drugi, na wejsciu 1, 0, oczekujemy 1
			{
				in[0] = 1;
				in[1] = 0;
				expectAnswer = 1;
				learnOneCase(&numberOfCases, &numberOfLoops);
			}
			if (numberOfCases == 2) //przypadek pierwszy, na wejsciu 0, 1, oczekujemy 1
			{
				in[0] = 0;
				in[1] = 1;
				expectAnswer = 1;
				learnOneCase(&numberOfCases, &numberOfLoops);
			}
			if (numberOfCases == 3) //przypadek pierwszy, na wejsciu 1, 1, oczekujemy 1
			{
				in[0] = 1;
				in[1] = 1;
				expectAnswer = 1;
				learnOneCase(&numberOfCases, &numberOfLoops);
			}
		}
		cout<<"number of loops: "<<numberOfLoops<<endl; //wyswietlamy liczbe petli
	}
};
int main()
{
	srand(time(NULL));
	bool tab[2];
	float tab2[2];
	//inkrementacja poczatkowych wartosci do konstruktora
	tab[0] = 0;
	tab[1] = 0;
	for (int i=0; i<2; i++) //losowanie poczatkowych wag
		tab2[i] = ((rand()%1000) - 500)/1000.0;
	Perceptron p(tab, tab2, -0.001, 2, 1, 0);
	cout<<"wagi na wejsciu wynosza: "<<endl;
	for (int i=0; i<2; i++)
		cout<< p.weight[i]<<endl;
	cout<<"wspolczynnik odchylenia na wejsciu:"<<endl;
	cout<<p.bias<<endl;
	p.learn();
	cout<<"wagi na wyjsciu wynosza: "<<endl;
	for (int i=0; i<2; i++)
		cout<< p.weight[i]<<endl;
	cout<<"wspolczynnik odchylenia na wyjsciu:"<<endl;
	cout<<p.bias<<endl;
	cin.sync();
	cin.get();
	return 0;
}