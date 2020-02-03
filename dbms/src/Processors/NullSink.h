#pragma once
#include <Processors/IProcessor.h>

namespace DB
{

class NullDataSink : public IProcessor
{
public:
    explicit NullDataSink(Block header) : IProcessor({std::move(header)}, {}) {}
    String getName() const override { return "NullSink"; }

    Status prepare() override
    {
        inputs.front().close();
        return Status::Finished;
    }

    InputPort & getPort() { return inputs.front(); }
};

}
