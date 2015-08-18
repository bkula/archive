#ifndef __PUBLIC_VAR_H__
#define __PUBLIC_VAR_H__

#include "Common.h"

template<typename Type> class PublicBase
{
public:

    PublicBase(int _ownerWebId, std::string _name)
    : ownerWebId(_ownerWebId)
    , name(_name)
    {
        //this->set(initialValue);
    }

    virtual ~PublicBase() {}

    const int ownerWebId;
    const std::string name;

    void set(Type v)
    {
        this->setValue(v);
        std::cout << "New value! owner: " << ownerWebId << " name: " << name
            << " value: " << this->to_string(_val) << std::endl;
    }

    void distributeAgain();

    Type get() const;

protected:

    Type _val;

    virtual void setValue (Type v) = 0;

    virtual std::string to_string(Type v) = 0;// {DEB("y");return "";}
    virtual Type to_type(std::string str) = 0;//
};

template<typename Type> class PublicVar : public PublicBase<Type>
{
public:

    PublicVar(int _ownerWebId, std::string _name, Type initialValue = Type())
    : PublicBase<Type>(_ownerWebId, _name)
    {
        //this->_val = initialValue;
        this->set(this->_val);
    }

private:

    virtual void setValue (Type v) { this->_val = v; }

    virtual std::string to_string(Type v) override
    {
        std::stringstream ss;
        ss << v;
        return ss.str();
    }

    virtual Type to_type(std::string str) override
    {
        std::stringstream ss;
        ss << str;
        Type res;
        ss >> res;
        return res;
    }
};

template<typename Type> class PublicArray
{
public:

    PublicArray(int _ownerWebId, std::string _name) {}

private:

};

#endif // __PUBLIC_VAR_H__
