#pragma once

//////////////////////////////////////////////////////////////////////
// Check-out.h - Implements checking out of a file                  //            
// ver 1.0                                                         //		
// Source: Jim Fawcett											  //
//Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018      //
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides one class:
* Check_out -It implements checking out on a file
* The package provides function for performing checkout on a file:

* Required Files:
* ---------------
* RepositoryCore.h

* Maintenance History:
* --------------------
* ver 1.0 : 11 Mar 2018
* - first release

Public Interface :
* ------------------
* void Checkout::checkoutFile(std::string filename, std::string path) - checkout a file from server folder to client folder

*/


#include <fstream>
#include <string>
#include <vector>
#include "../RepositoryCore/RepositoryCore.h"
#include "../CppNoSqlDb/Utilities/StringUtilities/StringUtilities.h"
#include "../Version/Version.h"
//#include "../FileSystem/FileSystemDemo/FileSystem.h"

namespace checkout
{
	//The class implements the checkout function on the file

	class Check_out
	{
	public:
		//Constructor the class

		Check_out(RepoCore::RespositoryCore& rc) : rc_(rc) { rc_ = rc; }
		

		//Defines the functionality of checkout function

		bool checkout_file(std::string name, std::string localpath)
		{
			std::vector<std::string> v = Utilities::split(name, ':');
			std::string x = v[0];
			std::string y = v[2];

			Version vo(rc_);

			int vf = vo.versionOfFile(name);

			std::string s = rc_.path() + "//" + x + "//" + y+"." + std::to_string(vf);
			std::string d = localpath + "//" + x + "//" + y;
			/*if (!FileSystem::Directory::exists(localpath + "//" + x))
				FileSystem::Directory::create(localpath + "//" + x);

			FileSystem::File::copy(s, d, false);
			*/
			return true;
		}
	private:

		RepoCore::RespositoryCore& rc_;
	};

	//Demonstrating the requirement of the checkout funtion

	bool testCheckOut(RepoCore::RespositoryCore& r)
	{
		Check_out co(r);
		std::cout << "\n\n I am checking out for A::A.cpp. The file is now in Local2 \n\n";
		co.checkout_file("A::A.cpp", "..\\Local2");
		return true;
	}
}
