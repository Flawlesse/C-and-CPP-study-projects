//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
#include "UnitMain.h"
#include <cstring>
#include <cstdlib>
#include <string>
class Data
{
public:
	std::string name;
	int amount, cost;
	TDateTime comingDate;
	Data();
	Data(const std::string& name, int amount, int cost, const TDateTime& comingDate);
	Data(const Data& rhs);
	~Data();
	void Show(TRichEdit* RE);
	bool operator==(const Data& rhs);
};
#endif
