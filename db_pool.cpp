#pragma once
#include "db_pool.h"
#include <iostream>


DbPool::DbPool(int max_cons) {
    try {
        for (int i = 0; i < max_cons; i++)           
            m_freeCons.push_back(createCon());
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }   
}
shared_ptr<connection> DbPool::createCon()
{
    m_connection.reset(new connection("host=localhost port=5432 dbname=TerraCRM user=postgres password=1234"));
    return m_connection;
}

const shared_ptr<connection> DbPool::getCon()
{
    const shared_ptr < connection > conn = *(m_freeCons.end() - 1);
    m_freeCons.pop_back();
    return conn;
}

void DbPool::releaseCon(shared_ptr<connection> con) {
    m_freeCons.push_back(shared_ptr<connection>(con));
}

result DbPool::runQuery(const string& query) { 
    auto conn = getCon();
    work trans(*conn);
    result res = trans.exec(query);
    trans.commit();
    releaseCon(conn);
    return res;
}

