#include "Math_Knight.h"

namespace MK
{
	float Basic::LinearInterp(float v0, float v1, float t)
	{
		return (1 - t) * v0 + t * v1;
	}

	float Basic::DegToRad(float Deg)
	{
		float Rad = 0;

		Rad += ((Deg / 180) * PI);

		return Rad;
	}

	float Basic::RadToDeg(float Rad)
	{
		float Deg = 0;

		Deg += ((Rad / PI) * 180);

		return Deg;
	}

	bool Basic::IsPowerOfTwo(unsigned int num)
	{
		while ((num % 2) == 0 && num > 1)
		{
			num /= 2;
		}

		if (num == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}