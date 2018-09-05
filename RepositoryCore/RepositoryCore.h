/////////////////////////////////////////////////////////////////////////
//RepositoryCore.h - provides means to check-in, version, browse,      //
//                   and check-out source code packages.              //            
// ver 1.0                                                           //		
// Source: Jim Fawcett											    //
//Ketul Mehta, CSE687 - Object Oriented Design, Spring 2018        //
////////////////////////////////////////////////////////////////////

/*
* Package Operations:
* -------------------
* This package provides one class:
* RepositoryCore -it holds the database
* The package provides function for maintaining database:

* Required Files:
* ---------------
* DbCore.h
* PayLoad.h

* Maintenance History:
* --------------------
* ver 1.0 : 11 Mar 2018
* - first release

Public Interface :
* ------------------
* NoSqlDb::DbCore<NoSqlDb::PayLoad> db() const { return db_; } - returns the db
* NoSqlDb::DbCore<NoSqlDb::PayLoad>& db() { return db_; } - returns refernece of db
* void db(const NoSqlDb::DbCore<NoSqlDb::PayLoad>& db) { db_ = db; } - sets the db

* std::string& path() { return path_; } - returns the path
* std::string path() const { return path_; } - returns the refernece of path
* void path(const std::string& path) { path_ = path; - sets the path

*/

#ifndef INC_REPO
#define INC_REPO


#include <vector>
#include <string>
#include "../CppNoSqlDb/PayLoad/PayLoad.h"
#include "../CppNoSqlDb/DbCore/DbCore.h"

namespace RepoCore
{

	//Class to hold Database
	class RespositoryCore
	{
	public:

		//Getter-Setter methods of data members of the class.
		std::string path() const { return path_; }
		std::string& path() { return path_; }
		void path(const std::string& path) { path_ = path; }

		NoSqlDb::DbCore<NoSqlDb::PayLoad> db() const { return db_; }
		NoSqlDb::DbCore<NoSqlDb::PayLoad>& db() { return db_; }
		void db(const NoSqlDb::DbCore<NoSqlDb::PayLoad>& db) { db_ = db; }

	private:
		std::string path_;
		NoSqlDb::DbCore<NoSqlDb::PayLoad> db_;
	};

	//Demonstrating the fnctionality of respository class
	bool testRepo(RespositoryCore  r)
	{
		r.path("..\\Repository");
		std::cout << r.path() << std::endl;
		return true;
	}

}

#endif

