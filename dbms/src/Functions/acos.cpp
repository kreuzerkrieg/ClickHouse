#include <Functions/FunctionMathUnary.h>



namespace DB
{

struct AcosName { static constexpr auto name = "acos"; };
using FunctionAcos = FunctionMathUnary<UnaryFunctionVectorized<AcosName, acos>>;

void registerFunctionAcos(FunctionFactory & factory)
{
    factory.registerFunction<FunctionAcos>(FunctionFactory::CaseInsensitive);
}

}
