#pragma once
#include <Interpreters/DDLWorker.h>


namespace DB
{

class DatabaseReplicated;

class DatabaseReplicatedDDLWorker : public DDLWorker
{
public:
    DatabaseReplicatedDDLWorker(DatabaseReplicated * db, const Context & context_);

    String enqueueQuery(DDLLogEntry & entry) override;

private:
    void initialize() override;

    DDLTaskPtr initAndCheckTask(const String & entry_name, String & out_reason, const ZooKeeperPtr & zookeeper) override;

    DatabaseReplicated * database;

};

}
