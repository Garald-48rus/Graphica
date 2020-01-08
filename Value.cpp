nclude "value.h"

Value::Value()
{
mHoper = false;
}
//-------------------------
void Value::setHoper(int index)
{
    if(index == 1)
    {
        mHoper = true;
    }
    else {
        mHoper = false;
    }

}
//------------------------------------
bool Value::getHoper()
{
    return  mHoper;
}
