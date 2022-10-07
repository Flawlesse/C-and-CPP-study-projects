//---------------------------------------------------------------------------


#pragma hdrstop

#include "Firm.h"

Firm::Firm()
{
	name = "";
	spec = "";
	pos = OfficeWorker;
	rate = 0;
	vacDays = 0;
	minYears = 0;
	maxYears = 100;
    highEdNeeded = false;
}
Firm::Firm(AnsiString nm, AnsiString sp, uint rt, uint vd,
		   uint mny, uint mxy, bool ed, Position p)
{
	name = nm;
	spec = sp;
	pos = p;
	rate = rt;
	vacDays = vd;
	minYears = mny;
	maxYears = mxy;
	highEdNeeded = ed;
}
Firm::Firm(const char* nm, const char* sp, uint rt, uint vD, uint mny, uint mxy,
		   bool ed, Position p)
{
	name = nm;
	spec = sp;
	pos = p;
	rate = rt;
	vacDays = vD;
	minYears = mny;
	maxYears = mxy;
	highEdNeeded = ed;
}
Firm::Firm(const Firm& rhs)
{
	name = rhs.name;
	spec = rhs.spec;
	pos = rhs.pos;
	rate = rhs.rate;
	vacDays = rhs.vacDays;
	minYears = rhs.minYears;
	maxYears = rhs.maxYears;
	highEdNeeded = rhs.highEdNeeded;
}
Firm::~Firm()
{
}
bool Firm::operator==(const Firm& rhs)
{
	if (name != rhs.name || spec != rhs.spec ||
		pos != rhs.pos || rate != rhs.rate || vacDays != rhs.vacDays ||
		minYears != rhs.minYears || maxYears != rhs.maxYears ||
		highEdNeeded != rhs.highEdNeeded)
		return false;
    return true;
}
Firm& Firm::operator=(const Firm& rhs)
{
	 if(*this == rhs)
		return *this;

	 name = rhs.name;
	 spec = rhs.spec;
	 pos = rhs.pos;
	 rate = rhs.rate;
	 vacDays = rhs.vacDays;
	 minYears = rhs.minYears;
	 maxYears = rhs.maxYears;
	 highEdNeeded = rhs.highEdNeeded;

	 return *this;
}
#pragma package(smart_init)
