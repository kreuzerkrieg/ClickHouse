#include "InternalTextLogsRowOutputStream.h"

#include <Interpreters/InternalTextLogsQueue.h>
#include <Common/typeid_cast.h>

#include <Columns/ColumnsNumber.h>
#include <Columns/ColumnString.h>
#include <IO/WriteHelpers.h>


namespace DB
{

Block InternalTextLogsRowOutputStream::getHeader() const
{
    return InternalTextLogsQueue::getSampleBlock();
}

void InternalTextLogsRowOutputStream::write(const Block & block)
{
    auto & array_event_time = typeid_cast<const ColumnUInt32 &>(*block.getByName("event_time").column).getData();
    auto & array_microseconds = typeid_cast<const ColumnUInt32 &>(*block.getByName("event_time_microseconds").column).getData();

    auto & column_host_name = typeid_cast<const ColumnString &>(*block.getByName("host_name").column);
    auto & column_query_id = typeid_cast<const ColumnString &>(*block.getByName("query_id").column);

    auto & array_thread_id = typeid_cast<const ColumnUInt64 &>(*block.getByName("thread_id").column).getData();
    auto & array_priority = typeid_cast<const ColumnInt8 &>(*block.getByName("priority").column).getData();
    auto & column_source = typeid_cast<const ColumnString &>(*block.getByName("source").column);
    auto & column_text = typeid_cast<const ColumnString &>(*block.getByName("text").column);

    for (size_t row_num = 0; row_num < block.rows(); ++row_num)
    {
        auto host_name = column_host_name.getDataAt(row_num);
        if (host_name.size)
        {
            writeCHCString("[", wb);
            writeString(host_name, wb);
            writeCHCString("] ", wb);
        }

        auto event_time = array_event_time[row_num];
        writeDateTimeText<'.', ':'>(event_time, wb);

        auto microseconds = array_microseconds[row_num];
        writeChar('.', wb);
        writeChar('0' + ((microseconds / 100000) % 10), wb);
        writeChar('0' + ((microseconds / 10000) % 10), wb);
        writeChar('0' + ((microseconds / 1000) % 10), wb);
        writeChar('0' + ((microseconds / 100) % 10), wb);
        writeChar('0' + ((microseconds / 10) % 10), wb);
        writeChar('0' + ((microseconds / 1) % 10), wb);

        auto query_id = column_query_id.getDataAt(row_num);
        if (query_id.size)
        {
            writeCHCString(" {", wb);
            writeString(query_id, wb);
            writeCHCString("}", wb);
        }

        UInt64 thread_id = array_thread_id[row_num];
        writeCHCString(" [ ", wb);
        writeIntText(thread_id, wb);
        writeCHCString(" ] <", wb);

        Int8 priority = array_priority[row_num];
        writeString(InternalTextLogsQueue::getPriorityName(priority), wb);
        writeCHCString("> ", wb);

        auto source = column_source.getDataAt(row_num);
        writeString(source, wb);
        writeCHCString(": ", wb);

        auto text = column_text.getDataAt(row_num);
        writeString(text, wb);

        writeChar('\n', wb);
    }
}

}
