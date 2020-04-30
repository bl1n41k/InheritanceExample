#include <iostream>
#include <string>
using namespace std;

class ComputerGameObject
{
private:
	string Name;
protected:
	ComputerGameObject(const string& _Name) :Name(_Name) {}
	ComputerGameObject(const ComputerGameObject& obj) : Name(obj.Name) {}
	virtual ~ComputerGameObject() {}
	virtual void  _print() const {
		cout << "Name: " << Name;
	}
public:
	virtual void draw() = 0;
	void  print() const
	{
		cout << typeid(*this).name() << endl; 
		_print();
		cout << endl << endl;
	}
};

class Creature : public ComputerGameObject
{
private:
	int dx;
	int dy;
	int HealthPoints;
	int ActionPoints;
public:
	Creature(const string& _Name, int _HealthPoints, int _ActionPoints) :ComputerGameObject(_Name), HealthPoints(_HealthPoints), ActionPoints(_ActionPoints), dx(0), dy(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), HealthPoints(obj.HealthPoints), dx(obj.dx), dy(obj.dy), ActionPoints(obj.ActionPoints) {}
	Creature(const string& _Name, int _HealthPoints, int _dx, int _dy, int _ActionPoints) :
		ComputerGameObject(_Name), HealthPoints(_HealthPoints), dx(_dx), dy(_dy), ActionPoints(_ActionPoints) {}
	void _move(int x, int y) {
		dx = x;
		dy = y;
	}
	int get_x() {
		return dx;
	}
	int get_y() {
		return dy;
	}
	~Creature() {}
protected:
	virtual void move(int, int) = 0;
	void  _print()const override
	{
		ComputerGameObject::_print();
		cout << endl <<"Health points: " << HealthPoints << endl <<"Coordinate x: " << dx << endl <<"Coordinate y: " << dy << endl <<"Action points: " << ActionPoints;
	}
};
class MythicalAnimal : public Creature
{
private:
	bool Enemy;
	int Level;
	string LifeStyle;
public:
	MythicalAnimal(const string& _Name, int _HealthPoints, int _ActionPoints, bool _Enemy, int _Level, string _LifeStyle) :Creature(_Name, _HealthPoints, _ActionPoints), Enemy(_Enemy), Level(_Level), LifeStyle(_LifeStyle) {}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), Enemy(obj.Enemy), Level(obj.Level), LifeStyle(obj.LifeStyle) {}
	MythicalAnimal(const string& _Name, int _HealthPoints, int _dx, int _dy, int _ActionPoints, bool _Enemy, int _Level, string _LifeStyle) :
		Creature(_Name, _HealthPoints, _dx, _dy, _ActionPoints), Enemy(_Enemy), Level(_Level), LifeStyle(_LifeStyle) {}
	~MythicalAnimal() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Mythical animal moved to: (" << get_x() << ";" << get_y() << ")" << endl;
	}
	void draw()
	{
		cout << "Coordinates of a mythical animal: (" << get_x() << ";" << get_y() << ")" << endl;
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << endl <<"Enemy: " << Enemy << endl <<"Level: " << Level << endl << "LifeStyle: " << LifeStyle;
	}
};

class HumanoidHero : public Creature
{
private:
	int Level;
	int AttackDamage;
	bool Enemy;
	
public:
	HumanoidHero(const string& _Name, int _HealthPoints, int _ActionPoints, int _AttackDamage, int _Level, bool _Enemy) :Creature(_Name, _HealthPoints, _ActionPoints), AttackDamage(_AttackDamage), Level(_Level), Enemy(_Enemy) {}
	HumanoidHero(const HumanoidHero& obj) : Creature(obj), AttackDamage(obj.AttackDamage), Level(obj.Level), Enemy(obj.Enemy) {}
	HumanoidHero(const string& _Name, int _healthPoints, int _dx, int _dy, int _ActionPoints, int _AttackDamage, int _Level, bool _Enemy) :
		Creature(_Name, _healthPoints, _dx, _dy, _ActionPoints), AttackDamage(_AttackDamage), Level(_Level), Enemy(_Enemy) {}
	~HumanoidHero() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "HumanoidHero moved to: (" << get_x() << ";" << get_y() << ")" << endl;
	}
	void draw() override
	{
		cout << "Coordinates of a HumanoidHero: (" <<  get_x() << ";" << get_y() << ")"<< endl;
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << endl << "Level: " << Level << endl <<"Humanoid damage: " << AttackDamage << endl << "Enemy: " << Enemy;
	}
};

class MagicHero : public Creature
{
private:
	bool MagicWand;
	int ManaPoint;
	int DamageMagicWand;
	int SpellDamage;

public:
	MagicHero(const string& _Name, int _HealthPoints, int _ActionPoints, int _ManaPoint, bool _MagicWand, int _DamageMagicWand, int _SpellDamage) : Creature(_Name, _HealthPoints, _ActionPoints), ManaPoint(_ManaPoint), MagicWand (_MagicWand), DamageMagicWand(_DamageMagicWand), SpellDamage(_SpellDamage) {}
	MagicHero(const MagicHero& obj) : Creature(obj), ManaPoint(obj.ManaPoint), MagicWand(obj.MagicWand), DamageMagicWand(obj.DamageMagicWand), SpellDamage(obj.SpellDamage) {}
	MagicHero(const string& _Name, int _HealthPoints, int _dx, int _dy, int _ActionPoints, int _ManaPoint, bool _MagicWand, int _DamageMagicWand, int _SpellDamage) :
		Creature(_Name, _HealthPoints, _dx, _dy, _ActionPoints), ManaPoint(_ManaPoint), MagicWand(_MagicWand), DamageMagicWand(_DamageMagicWand), SpellDamage(_SpellDamage) {}
	~MagicHero() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Magic hero moved to: (" << get_x() << ";" << get_y() << ")" << endl;
	}
	void draw() override
	{
		cout << "Coordinates of a magic hero: (" << get_x() << ";" << get_y() << ")" << endl;
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << endl <<"MagicWand: "<< MagicWand << endl <<"Amount of mana: " << ManaPoint << endl << "Spell Damage: " << SpellDamage << endl << "Damage a magic wand: " << DamageMagicWand << endl << "AttackDamage: " << int(SpellDamage + DamageMagicWand * 0.07 * ManaPoint);
	}
};

class MagicItem : public ComputerGameObject
{
private:
	int id;
	int dx;
	int dy;
	int Strength;
	int Agility;
	int Intelligence;
public:
	MagicItem(const string& _id) :ComputerGameObject(_id), dx(0), dy(0), id(0), Strength(0), Agility(0), Intelligence(0) {}
	MagicItem(const string& _Name, int _id, int _strength, int _agility, int _intelligence) :ComputerGameObject(_Name), id(_id), Strength(_strength), Agility(_agility), Intelligence(_intelligence), dx(0), dy(0) {}
	MagicItem(const string& _Name, int _id, int _strength, int _agility, int _intelligence, int _dx, int _dy) :
		ComputerGameObject(_Name), id(_id), Strength(_strength), Agility(_agility), Intelligence(_intelligence), dx(_dx), dy(_dy) {}
	MagicItem(const MagicItem& obj) :ComputerGameObject(obj), dx(obj.dx), dy(obj.dy), id(obj.id), Strength(obj.Strength), Agility(obj.Agility), Intelligence(obj.Intelligence) {}
	~MagicItem() {}
	void draw() override
	{
		cout << "Coordinates of a magic item: (" << dx << ";" << dy << ")" << endl;
	}
protected:
	void _print()const override
	{
		ComputerGameObject::_print();
		cout << endl <<"Id: " << id << endl <<"Strength: " << Strength << endl << "Agility: " << Agility << endl << "Intelligence: " <<Intelligence;
	}
};

int main()
{
	HumanoidHero Hero("Kitava", 350, 5, 12, 7, 140, 10, 1);
	Hero.move(28, 46);
	Hero.draw();
	Hero.print();

	MythicalAnimal Unicorn("Unicorn", 110, 50, 50, 3, 1, 7, "Omnivorous");
	Unicorn.move(16, 3);
	Unicorn.draw();
	Unicorn.print();

	MythicalAnimal Dryad("Dryad", 80, 7, 0, 5, "Herbivorous");
	Dryad.draw();
	Dryad.print();

	MagicHero Magician("Bobert", 100, 65, 46, 12, 135, 1, 28, 110);
	Magician.move(200, 200);
	Magician.draw();
	Magician.print();

	MagicItem Bracer("Nightsilver", 12328, 8, 3, 1, 28, 35);
	Bracer.draw();
	Bracer.print();
}