/////////////////////////////////////////////////////////////////////////
//Version.cpp - Implements version fucntonalities                     //            
// ver 1.0                                                           //		
// Source: Jim Fawcett											    //
//Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018        //
////////////////////////////////////////////////////////////////////

#include "Version.h"


#ifdef TEST_VERSION

/*----< test stub >--------------------------------------------------*/

int main()
{
	RepoCore::RespositoryCore r;
	r.path("..\\Repository");
	testversion(r);
	return 0;
}
#endif // TEST_VERSION



