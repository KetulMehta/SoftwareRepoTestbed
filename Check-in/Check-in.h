#pragma once

//////////////////////////////////////////////////////////////////////////
// Check-in.h - Implements checking in of a file                        //            
// ver 1.0                                                              //		
// Source: Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018    //
// Author : Ketul Mehta										            //
//////////////////////////////////////////////////////////////////////////
/*
*Package Operations :
*------------------ -
*This package provides one class :
	*checkin - it implements checkin on a file
	* The package provides function for performing checkin on a file :

*Required Files :
*-------------- -
*RepositoryCore.h
* DateTime.h

* Maintenance History :
*--------------------
* ver 1.0 : 11 Mar 2018
* -first release

Public Interface :
*------------------
*  	CheckIn(RepositoryCore& repo) : repo_{ repo } -constructor for checkin class
* 	void checkIn(std::string fileName, std::string path, NoSqlDb::DbElement<NoSqlDb::PayLoad> dbElem) - checkin a file from local folder to repository
*  void closeFile(std::string fileName) - Makes the staus of file close pending if all it dependent file are open or close pending else makes the status as close
*  void testCheckIn() - performs series of checkin operation

*/

#include "../RepositoryCore/RepositoryCore.h"
#include "../Version/Version.h"
#include "../CppNoSqlDb/Utilities/StringUtilities/StringUtilities.h"
#include "../CppNoSqlDb/DbCore/DbCore.h"
#include "../CppNoSqlDb/PayLoad/PayLoad.h"
//#include "../FileSystem/FileSystemDemo/FileSystem.h"

namespace checkin {

	//The class implements the checkin on the file

	class CheckIn{
	public:
		//Constructor of the class
		CheckIn(RepoCore::RespositoryCore& rc) : rc_(rc) { rc_ = rc; }
		NoSqlDb::DbElement<NoSqlDb::PayLoad> demoElem;
		std::string checkin(std::string name, std::string path, NoSqlDb::DbElement<NoSqlDb::PayLoad> dbElem){
			//std::vector<std::string> v = Utilities::split(name, ':');
			//std::string x = v[0];
			//std::string y = v[2];
			Version vo(rc_);
			int vf = vo.versionOfFile(name); int flag = 0;
			if (vf == 0){
				rc_.db().addRecord(name + "." + std::to_string(vf+1), dbElem);
				std::string var1 = name + "." + std::to_string(vf+1);
				NoSqlDb::showDb(rc_.db());
				return var1;}
			else {
				flag = rc_.db().operator[](name + "." + std::to_string(vf)).payLoad().flag();
				if (flag == 1) {
					std::string var2 = name + "." + std::to_string(vf);
					NoSqlDb::showDb(rc_.db());
					return var2;}
				else {
					rc_.db().addRecord(name + "." + std::to_string(vf + 1), dbElem);
					std::string var3 = name + "." + std::to_string(vf + 1);
					NoSqlDb::showDb(rc_.db());
					return var3;}
			}		
			//std::string src = path + "//" + x + "//" + y;
			//std::string dst = rc_.path() + "//" + x + "//" + y + "." + std::to_string(vf);		
			//Checking the condition weather the directory is empty of not.
			/*if (!FileSystem::Directory::exists(rc_.path() + "//" + x))
				FileSystem::Directory::create(rc_.path() + "//" + x);
			FileSystem::File::copy(src, dst, false);*/			
			if (flag == 2)
				return false;
			//Db Insert
			rc_.db().addRecord(name + "." + std::to_string(vf), dbElem);
			std::string var = name +"."+ std::to_string(vf);
			NoSqlDb::showDb(rc_.db());
			return var;
		}
		//Defining the close operation on the file
		bool closeStatus(std::string name){
			Version vo(rc_);
			int vf = vo.versionOfFile(name);
			rc_.db().operator[](name + "." + std::to_string(vf)).payLoad().flag(0);
			NoSqlDb::showDb(rc_.db());
			return true;
		}
	private:
		RepoCore::RespositoryCore& rc_;	};

	//Demonstrating the requirement of the checkin function
	
	bool testCheckIn(RepoCore::RespositoryCore& r)
	{
		//The new file is checkedin

		CheckIn c(r);
		std::cout << "\n I am checking for A::A.cpp\n\n";
	//c.checkin("A::A.cpp", "..\\Local", db);
		NoSqlDb::showDb(r.db());

		//Checking of the same file when it is still open
		std::cout << "\n\n I am checking again for A::A.cpp while open status\n\n";
		//c.checkin("A::A.cpp", "..\\Local");
		NoSqlDb::showDb(r.db());

		//Closing the file
		std::cout << "\n\n Closing status for A::A.cpp\n\n";
		c.closeStatus("A::A.cpp");

		//Checkin of same file after it is closed
		std::cout << "\n\n I am checking again for A::A.cpp while close status\n\n";
		//c.checkin("A::A.cpp", "..\\Local");
		NoSqlDb::showDb(r.db());

		std::cout << "\n\n Closing status for A::A.cpp\n\n";
		c.closeStatus("A::A.cpp");

		//Checking the new file after the prvious file is closed.
		std::cout << "\n\n I am checking for B::B.cpp while close status of A::A.cpp \n\n";
		//c.checkin("B::B.cpp", "..\\Local");
		NoSqlDb::showDb(r.db());

		return true;
	}

}