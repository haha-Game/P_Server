#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include <chrono>

#include "RefCounting.h"
#include "Memory.h"
#include "Allocator.h"

using TL = TypeList<class Player, class Mage, class Knight, class Archer>;

class Player
{
public:
	Player()
	{
		INIT_TL(Player);
	}
	virtual ~Player() {}

	DECLARE_TL
};

class Knight : public Player
{
public:
	Knight() { INIT_TL(Knight); }
};

class Mage : public Player
{

public:
	Mage() { INIT_TL(Mage); }
};

class Archer : public Player
{

public:
	Archer() { INIT_TL(Archer) }
};

class Dog
{

};

class Healer
{
public:
	int32 _hp = rand() % 1000;
};

int main()
{
	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([]()
			{
				while (true)
				{
					Healer* healer = xnew<Healer>();

					cout << healer->_hp << endl;

					this_thread::sleep_for(200ms);

					xdelete(healer);
				}
			});
	}

	GThreadManager->Join();
}