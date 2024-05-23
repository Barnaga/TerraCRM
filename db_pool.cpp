#pragma once
#include "db_pool.h"

connection*  DbPool::createCon() {
    connection* conn = new connection("host='localhost' port='5432' dbname='TerraCRM' user='postgres' password ='1234'");
    
	return conn;
}
void DbPool::releaseCon(connection  *conn) {

    m_freeCons.push_back(shared_ptr <connection >(conn));
}

connection* DbPool::getCon() {

    shared_ptr <connection> conn = *(m_freeCons.end() - 1);
    m_freeCons.pop_back();
    return conn.get();
}

result DbPool::runQuery(const string& query) {

    connection* conn = getCon();
    work trans(*conn);
    result res = trans.exec(query);
    trans.commit();
    releaseCon(conn);

    return res;
}

DbPool::DbPool(uint32_t max_cons) {
    for (uint32_t i = 0; i < max_cons; i++) {
        connection* con = createCon();
        m_freeCons.push_back(shared_ptr<connection> (con));
    }
}