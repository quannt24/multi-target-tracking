//
// Generated file, do not edit! Created by opp_msgc 4.3 from sensedsignal.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "sensedsignal_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(SensedSignal);

SensedSignal::SensedSignal(const char *name, int kind) : cMessage(name,kind)
{
    this->tarId_var = 0;
    this->signal_var = 0;
    this->distance_var = 0;
}

SensedSignal::SensedSignal(const SensedSignal& other) : cMessage(other)
{
    copy(other);
}

SensedSignal::~SensedSignal()
{
}

SensedSignal& SensedSignal::operator=(const SensedSignal& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void SensedSignal::copy(const SensedSignal& other)
{
    this->tarId_var = other.tarId_var;
    this->signal_var = other.signal_var;
    this->distance_var = other.distance_var;
}

void SensedSignal::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->tarId_var);
    doPacking(b,this->signal_var);
    doPacking(b,this->distance_var);
}

void SensedSignal::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->tarId_var);
    doUnpacking(b,this->signal_var);
    doUnpacking(b,this->distance_var);
}

int SensedSignal::getTarId() const
{
    return tarId_var;
}

void SensedSignal::setTarId(int tarId)
{
    this->tarId_var = tarId;
}

const char * SensedSignal::getSignal() const
{
    return signal_var.c_str();
}

void SensedSignal::setSignal(const char * signal)
{
    this->signal_var = signal;
}

double SensedSignal::getDistance() const
{
    return distance_var;
}

void SensedSignal::setDistance(double distance)
{
    this->distance_var = distance;
}

class SensedSignalDescriptor : public cClassDescriptor
{
  public:
    SensedSignalDescriptor();
    virtual ~SensedSignalDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SensedSignalDescriptor);

SensedSignalDescriptor::SensedSignalDescriptor() : cClassDescriptor("SensedSignal", "cMessage")
{
}

SensedSignalDescriptor::~SensedSignalDescriptor()
{
}

bool SensedSignalDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SensedSignal *>(obj)!=NULL;
}

const char *SensedSignalDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SensedSignalDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SensedSignalDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SensedSignalDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tarId",
        "signal",
        "distance",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SensedSignalDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tarId")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "signal")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "distance")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SensedSignalDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SensedSignalDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SensedSignalDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SensedSignal *pp = (SensedSignal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SensedSignalDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SensedSignal *pp = (SensedSignal *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTarId());
        case 1: return oppstring2string(pp->getSignal());
        case 2: return double2string(pp->getDistance());
        default: return "";
    }
}

bool SensedSignalDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SensedSignal *pp = (SensedSignal *)object; (void)pp;
    switch (field) {
        case 0: pp->setTarId(string2long(value)); return true;
        case 1: pp->setSignal((value)); return true;
        case 2: pp->setDistance(string2double(value)); return true;
        default: return false;
    }
}

const char *SensedSignalDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *SensedSignalDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SensedSignal *pp = (SensedSignal *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


