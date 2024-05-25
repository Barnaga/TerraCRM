#pragma once
#include <pqxx/pqxx>
#include <QDebug>

using namespace pqxx;
using namespace std;

class DbPool {
public:
	DbPool(int max_cons);

	shared_ptr<connection> createCon();
	result runQuery(const string& query);
private:
	shared_ptr<connection> m_connection;

	shared_ptr<connection> getCon();
	void releaseCon(shared_ptr<connection> con);
	vector<shared_ptr<connection>> m_freeCons;
};