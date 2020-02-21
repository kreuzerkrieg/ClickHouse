#include <Functions/FunctionMathUnary.h>


namespace DB
{

struct ErfcName { static constexpr auto name = "erfc"; };
using FunctionErfc = FunctionMathUnary<UnaryFunctionPlain<ErfcName, std::erfc>>;

void registerFunctionErfc(FunctionFactory & factory)
{
    factory.registerFunction<FunctionErfc>();
}

}
