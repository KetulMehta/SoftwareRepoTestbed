///////////////////////////////////////////////////////////////////////
// Check-in.cpp - Implements checkin fucntionality                   //            
// ver 1.0                                                           //		
// Source: Jim Fawcett											     //
// Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////

#include "Check-in.h"

/*----< test stub >--------------------------------------------------*/

#ifdef TEST_CHECK_IN

int main()
{
	RepoCore::RespositoryCore r;
	r.path("..\\Repository");
	checkin::testCheckIn(r);
	return 0; 
}
#endif

