
#include <cstdio>
#include <cassert>

#include <dt.h>

int main()
{
	// basic test
	{
		int a = 1;
		try
		{
			a = 2;
			DT_DEFER a = 0;
			DT_TRY throw 10;
			DT_END;
			assert(a == 0);
		}
		catch (int err)
		{
			assert(err == 10);
			assert(a == 0);
		}
	}

	// nesting
	{
		int* p = new int(3);
		DT_DEFER;
		{
			DT_DEFER;
			{
				p = nullptr;
			}
			DT_TRY;
			{
				delete p;
			}
			DT_END;
		}
		DT_TRY;
		{
			int* q = new int(4);
			DT_DEFER;
			{
				delete q;
				q = nullptr;
			}
			DT_TRY;
			{
				assert(*p + *q == 7);
			}
			DT_END;
			assert(q == nullptr);
		}
		DT_END;
		assert(p == nullptr);
	}

	// exception propagation
	try
	{
		bool done = false;
		DT_DEFER;
		{
			assert(done);
			throw 100;
		}
		DT_TRY;
		{
			done = true;
			throw 200;
		}
		DT_END;
	}
	catch (int err)
	{
		assert(err == 100);
	}
}
