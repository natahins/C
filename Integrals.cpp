// Integrals.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using std::cout;

class Point_0 {		//класс точка
private:
	double  x, y;

public:
	Point_0();
	Point_0(double x, double y);
	void SetX(double x);
	void SetY(double y);
	double GetX();
	double GetY();
	void Move(double x, double y);
	double Rasst(double x, double y);
	double Rasst(Point_0 t);

};

Point_0::Point_0(){
	x = 0;  y = 0;
}

Point_0::Point_0(double x1, double y1){
	x = x1; y = y1;
}

void Point_0::SetX(double x1) {
	x = x1; return;
}

void Point_0::SetY(double y1) {
	y = y1; return;
}

double Point_0::GetX(){
	return x;
}

double Point_0::GetY(){
	return y;
}

void Point_0::Move(double dx, double dy)
{
	x += dx;
	y += dy;
}

double Point_0::Rasst(double x1, double y1)
{
	double rast = (x - x1)*(x - x1) + (y - y1)*(y - y1);
	return sqrt(rast);

}
double Point_0::Rasst(Point_0 t)
{
	double rast = (x - t.x)*(x - t.x) + (y - t.y)*(y - t.y);
	return sqrt(rast);

}


double f1(double x){			//функция
	return x*sin(x);
}


typedef double(*fun)(double);

class Baza_tab{
private:
	double a, b;
	int n;
	fun f;
protected:
	Point_0 *p;
public:
	Baza_tab() {}
	Baza_tab(double av, double bv, int nv, fun ff){
		a = av;
		b = bv;
		n = nv;
		f = ff;

		p = new Point_0[n];
	}
	double get_a() { return a; }
	double get_b() { return b; }
	int get_n() { return n; }

	Point_0* tabuf(){
		double x, y, h;
		int i;
		h = (b - a) / n;
		for (i = 0; i<n; i++){
			x = a + i*h;
			y = f(x);
			p[i] = Point_0(x, y);
		}
		return p;
	}
	};


class Int_Rect : public Baza_tab{	
public:
	Int_Rect() :Baza_tab(){}
	Int_Rect(double av, double bv, int nv, fun ff) :Baza_tab(av, bv, nv, ff){}
	double integral();
	double integral_tr();
	double integral_par();

};

double Int_Rect::integral(){		//вычисление интеграла методом прямоугольников

	double h, s;
	int i, n;
	n = get_n();
	h = p[1].GetX() - p[0].GetX();
	for (i = 0, s = 0; i<n; i++)
		s += (p[i].GetY()*h);
	return s;
	}
double Int_Rect::integral_tr(){			//вычисление интеграла методом трапеции

	double h, s1, s2;
	int i, n;
	n = get_n();
	h = p[1].GetX() - p[0].GetX();
	s1 = (p[0].GetY() + p[n - 1].GetY())*h / 2;

	for (i = 0, s2 = 0; i<n - 1; i++)
		s2 += (p[i].GetY()*h);
	return s1 + s2;
	}
double Int_Rect::integral_par(){		//вычисление интеграла методом параболы

	double h, s1, s2;
	int i, n;
	n = get_n();
	h = p[1].GetX() - p[0].GetX();
	s1 = (p[0].GetY() + p[n - 1].GetY())*h / 3;


	for (i = 0, s2 = 0; i<n - 1; i++)

		if (i % 2)
			s2 += 4 * (p[i].GetY()*h / 3);
		else
			s2 += 2 * (p[i].GetY()*h / 3);
	return s1 + s2;
	}


int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "RUS");

	cout << "\n" << "\n" << "Вычисление площади функции x*sin(x)";
	Int_Rect pr;
	Int_Rect *pr1;
	pr = Int_Rect(0, 1, 10000, f1);
	pr.tabuf();

	//pr1 = new Int_Rect(0, 1, 10000, f1);
	//pr1->tabuf();
	cout << "\n" << "\n" << "Площадь по методу прямоугольников равна " << pr.integral();
	cout << "\n" << "\n" << "Площадь по методу трапеции равна " << pr.integral_tr();
	cout << "\n" << "\n" << "Площадь по методу парабол равна " << pr.integral_par();
	//cout << "\n" << "\n" << "Площадь2 равна" << pr1->integral();
	
	_getch();
	return 0;
	}


