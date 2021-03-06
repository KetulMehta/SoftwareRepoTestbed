///////////////////////////////////////////////////////////////////////
// Check-out.cpp - Implements checkout fucntionality                 //            
// ver 1.0                                                           //		
// Source: Jim Fawcett											    //
//Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018        //
/////////////////////////////////////////////////////////////////////

#include "Check-out.h"
#include "..//Check-in/Check-in.h"

/*----< test stub >--------------------------------------------------*/

#ifdef TEST_CHECK_OUT

int main()
{
	RepoCore::RespositoryCore r;
	r.path("..\\Repository");
	checkin::testCheckIn(r);
	checkout::testCheckOut(r);
	return 0;
}

#endif // TEST_CHECK_OUT



