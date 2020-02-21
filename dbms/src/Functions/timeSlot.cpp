#include <Functions/IFunctionImpl.h>

#include <Functions/DateTimeTransforms.h>
#include <Functions/FunctionDateOrDateTimeToSomething.h>
#include <DataTypes/DataTypesNumber.h>


namespace DB
{

using FunctionTimeSlot = FunctionDateOrDateTimeToSomething<DataTypeDateTime, TimeSlotImpl>;

void registerFunctionTimeSlot(FunctionFactory & factory)
{
    factory.registerFunction<FunctionTimeSlot>();
}

}



