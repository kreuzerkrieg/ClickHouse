
#include <Storages/ColumnsDescription.h>
#include <Storages/StorageValues.h>
#include <DataStreams/OneBlockInputStream.h>


namespace DB
{

StorageValues::StorageValues(const StorageID & table_id_, const ColumnsDescription & columns_, const Block & res_block_)
    : IStorage(table_id_), res_block(res_block_)
{
    setColumns(columns_);
}

BlockInputStreams StorageValues::read(
    const Names & column_names,
    const SelectQueryInfo & /*query_info*/,
    const Context & /*context*/,
    QueryProcessingStage::Enum /*processed_stage*/,
    size_t /*max_block_size*/,
    unsigned /*num_streams*/)
{
    check(column_names, true);

    return BlockInputStreams(1, std::make_shared<OneBlockInputStream>(res_block));
}

}
