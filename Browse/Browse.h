#pragma once
//////////////////////////////////////////////////////////////////////
// Browsing.h - Implements Browsing Operations                    //
// ver 1.0										    		      	//
// Source: Jim Jawcett												//
// Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018        //
//////////////////////////////////////////////////////////////////////

/*
* Package Operations:
* -------------------
* This package provides one class:
* Browsing - The package provides function for performing browsing operation:
* 
* Required Files:
* ---------------
* RepositoryCore.h
* Query.h
* DateTime.h

* Maintenance History:
* --------------------
* ver 1.0 : 11 Mar 2018
* - first release

Public Interface :
* ------------------
*  	Browsing(RepositoryCore& repo) : NoSqlDb::Query<NoSqlDb::PayLoad>(repo.db()), repo_{ repo } -  constructor of the class
*  void showFileContent(std::ostream& out = std::cout) - opens the file content in notepad
*/

#include "../RepositoryCore/RepositoryCore.h"
#include "../CppNoSqlDb/Query/Query.h"
#include "../CppNoSqlDb/PayLoad/PayLoad.h"
#include "../CppNoSqlDb/Utilities/StringUtilities/StringUtilities.h"
#include "../CppNoSqlDb/Utilities/TestUtilities/TestUtilities.h"
#include "../Process/Process/Process.h"
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

//Defines the class browse where the object of repository is made.

class Browse : public NoSqlDb::Query<NoSqlDb::PayLoad>
{
public:

	//Constructor of the class

	Browse(RepoCore::RespositoryCore& rc) : NoSqlDb::Query<NoSqlDb::PayLoad>(rc.db()), rc_(rc) {}

	void show(bool openFile = false)
	{
		NoSqlDb::Query<NoSqlDb::PayLoad>::show();
		if (openFile)
		{
			for (auto it : keys())
			{
				Process p;
				p.title("open file");
				std::string appPath = "c:/windows/system32/notepad.exe";
				p.application(appPath);

				std::vector<std::string> v = Utilities::split(it, ':');
				std::string x = v[0];
				std::string y = v[2];

				std::string cmdLine = "/A " + rc_.path() + "//" + x + "//" + y;
				p.commandLine(cmdLine);

				std::cout << "\n  starting process: \"" << appPath << "\"";
				std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
				p.create();
			}
			
			
			std::cout << "\n  after OnExit";
		}
		
	}


private:
	RepoCore::RespositoryCore& rc_;
};

using namespace NoSqlDb;

//Demonstrates the requirements as test funcion for browsing

bool testB1(RepoCore::RespositoryCore& r)
{
	Utilities::title(" \n Demonstrating Requirement - Browsing");
	Utilities::putline();
	showDb(r.db());
	
	// Browse demonstrating  description that starts with letter 'A::A.cpp'.

	std::cout << "\n\n Description that contains 'A::A.cpp'.\n";
	Browse b1(r);
	Conditions<PayLoad> conds1;
	conds1.description("(.*)A::A.cpp(.*)");
	b1.select(conds1).show();
	Utilities::putline();

	// Browse demonstrating name that starts with letter 'K'.

	std::cout << "\n\n  Name starting with letter K.\n";
	Browse b2(r);
	Conditions<PayLoad> conds2;
	conds2.name("K(.*)");
	b2.select(conds2).show();
	Utilities::putline();

	// Browse demonstrating  description that starts with letter 'B::B.cpp'.

	std::cout << "\n\n  Description that contains 'B::B.cpp. This will open file'.\n";
	Browse b3(r);
	Conditions<PayLoad> conds3;
	conds3.description("(.*)B::B.cpp(.*)");
	b3.select(conds3);
	b3.show(true);
	Utilities::putline();

	return true;
}

//Demonstrating the requirement of payload

bool testB2(RepoCore::RespositoryCore& r)
{
	Utilities::title(" Demonstrating Requirement - PayLoad Queries");
	Utilities::putline();

	Browse b1(r);

	std::string category = "F#";
	std::cout << "\n  Select on payload categories for \"" << category << "\"\n";
	std::cout << "\n";

	auto hasCategory = [&category](DbElement<PayLoad>& elem) {
		return (elem.payLoad()).hasCategory(category);
	};

	b1.select(hasCategory).show();
	std::cout << "\n\n";

	return true;
}

