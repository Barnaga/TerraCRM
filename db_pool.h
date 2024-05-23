#pragma once
#include <pqxx/pqxx>

using namespace pqxx;
using namespace std;

class DbPool {
public:
	DbPool(uint32_t max_cons);
	result runQuery(const string& query);
private:
	connection* createCon();
	connection*  getCon();
	void releaseCon(connection* con);
	vector<shared_ptr<connection>> m_freeCons;

};