#include <iostream>
using namespace std;

class creature {
private:
	string title;
	double mass;
protected:
	creature() :mass(0.0) {}
	creature(const creature& obj) :title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) :title(_title), mass(_mass) {}
	virtual ~creature() { cout << "creature deleted" << endl << endl; }
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }
public:
	double get_mass() const
	{
		return mass;
	}
	void print() const {
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")" << endl;
	}
};

class animal :public creature
{
private:
	double speed;
public:
	animal() :creature() {};
	animal(const animal& obj) :creature(obj), speed(obj.speed) {}
	animal(const string& _title, double _mass, double _speed) :creature(_title, _mass), speed(_speed) {}
	double get_speed() const
	{
		return speed;
	}
	~animal() { cout << "animal deleted" << endl; }
protected:
	void _print() const override
	{
		creature::_print();
		cout << ", speed: " << speed;
	}
};

class bird :public virtual animal
{
private:
	double topfly;
public:
	bird() :animal() {}
	bird(const bird& obj) :animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly) :animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { cout << "bird deleted" << endl; }
protected:
	void _print() const override
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};

class fish :public animal
{
private:
	double maxdeep;
public:
	fish() :animal() {}
	fish(const fish& obj) :animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep) :animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { cout << "fish deleted" << endl; }
protected:
	void _print() const override
	{
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};

class predator :public virtual animal
{
protected:
	predator() {}
public:
	~predator() {}
	virtual bool hunt(const animal& obj) = 0;
};

class eagle :public bird, public predator
{
public:
	eagle() :bird() {}
	eagle(const eagle& obj) :bird(obj), animal(obj) {}
	eagle(double _mass, double _speed, double _topfly) :bird("", 0, 0, _topfly), animal("Орел", _mass, _speed) {}
	bool hunt(const animal& obj) override
	{
		return obj.get_mass() < bird::get_mass() && obj.get_speed() < bird::get_speed();
	}
};

int main()
{
	setlocale(0, "Rus");
	animal spider = animal("Паук", 0.003, 0.05);
	cout << "Spider mass :" << spider.get_mass() << endl;
	bird raven = bird("Ворона", 0.3, 10, 0.1);
	eagle eagle1(1, 100, 1);
	fish hammerhead("Рыба Молот", 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	cout << "Eagle vs raven : " << eagle1.hunt(raven) << endl;
	cout << "Eagle vs hammerhead : " << eagle1.hunt(hammerhead) << endl;
	cout << "Eagle vs spider : " << eagle1.hunt(spider) << endl;
}