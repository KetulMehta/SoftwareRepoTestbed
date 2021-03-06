

///////////////////////////////////////////////////////////////////////
// Browse.cpp - Returns information from db metadata and payload      //
// ver 1.1															 //
// Source: Jim Jawcett												 //	
// Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////

/*----< test stub >--------------------------------------------------*/
 
#ifdef TEST_BROWSE

#include "Browse.h"
#include "../Check-in/Check-in.h"


int main()
{
	RepoCore::RespositoryCore r;
	checkin::testCheckIn(r);
	NoSqlDb::showDb(r.db());
	testB1(r);
	testB2(r);
	return 0;
}
#endif 



