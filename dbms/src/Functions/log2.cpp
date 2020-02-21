#include <Functions/FunctionMathUnary.h>


namespace DB
{

struct Log2Name { static constexpr auto name = "log2"; };
using FunctionLog2 = FunctionMathUnary<UnaryFunctionVectorized<Log2Name, log2>>;

void registerFunctionLog2(FunctionFactory & factory)
{
    factory.registerFunction<FunctionLog2>(FunctionFactory::CaseInsensitive);
}

}
