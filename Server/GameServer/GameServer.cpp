#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

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

int main()
{
	{
		shared_ptr<Player> player = MakeShared<Knight>();

		shared_ptr<Archer> archer = TypeCast<Archer>(player);
		bool canCast = CanCast<Mage>(player);

	}

	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([]()
			{
				while (true)
				{
				}
			});
	}

	GThreadManager->Join();
}