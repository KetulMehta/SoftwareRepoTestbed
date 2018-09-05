#pragma once

/////////////////////////////////////////////////////////////////////////
//Version.h - Implements versioning of a file                         //            
// ver 1.0                                                           //		
// Source: Jim Fawcett											    //
//Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018        //
////////////////////////////////////////////////////////////////////

/*
* Package Operations:
* -------------------
* This package provides one class:
* Version - it maintains vesions on a file
* The package provides function for maintaining version on a file:

* Required Files:
* ---------------
* RepositoryCore.h

* Maintenance History:
* --------------------
* ver 1.0 : 11 Mar 2018
* - first release

Public Interface :
* ------------------
* Version(RepositoryCore& repo) : repo_ {repo} - constructor of the class
* int getVersion(std::string); - returns the version of the file
*/


#include "../RepositoryCore/RepositoryCore.h"
#include "../CppNoSqlDb/DbCore/DbCore.h"
#include <iostream>

//The class maintains versions of the file

class Version
{
public:
	//Constructor of the class

	Version(RepoCore::RespositoryCore& rc) : rc_(rc) {}

	int versionOfFile(std::string name)
	{
		int version = 0;
		while (rc_.db().contains(name + "." + std::to_string(version + 1)))
		{
			version++;
		}
		return version;
	}

private:
	RepoCore::RespositoryCore& rc_;
};

//Demonstrates the requirement of the version class

bool testversion(RepoCore::RespositoryCore& r)
{
	Version v(r);
	int ver = v.versionOfFile("A::A.cpp");
	std::cout << "Version of the file is : " << ver;
	return true;

}
