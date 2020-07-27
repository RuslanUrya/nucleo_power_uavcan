/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/acyc/src/libuavcan/libuavcan/test/dsdl_test/root_ns_a/20000.MavlinkMessage.uavcan
 */

#ifndef ROOT_NS_A_MAVLINKMESSAGE_HPP_INCLUDED
#define ROOT_NS_A_MAVLINKMESSAGE_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# This thing is only needed for testing
#

uint8 seq
uint8 sysid
uint8 compid
uint8 msgid

uint8[<256] payload
******************************************************************************/

/********************* DSDL signature source definition ***********************
root_ns_a.MavlinkMessage
saturated uint8 seq
saturated uint8 sysid
saturated uint8 compid
saturated uint8 msgid
saturated uint8[<=255] payload
******************************************************************************/

#undef seq
#undef sysid
#undef compid
#undef msgid
#undef payload

namespace root_ns_a
{

template <int _tmpl>
struct UAVCAN_EXPORT MavlinkMessage_
{
    typedef const MavlinkMessage_<_tmpl>& ParameterType;
    typedef MavlinkMessage_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > seq;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sysid;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > compid;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > msgid;
        typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 255 > payload;
    };

    enum
    {
        MinBitLen
            = FieldTypes::seq::MinBitLen
            + FieldTypes::sysid::MinBitLen
            + FieldTypes::compid::MinBitLen
            + FieldTypes::msgid::MinBitLen
            + FieldTypes::payload::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::seq::MaxBitLen
            + FieldTypes::sysid::MaxBitLen
            + FieldTypes::compid::MaxBitLen
            + FieldTypes::msgid::MaxBitLen
            + FieldTypes::payload::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::seq >::Type seq;
    typename ::uavcan::StorageType< typename FieldTypes::sysid >::Type sysid;
    typename ::uavcan::StorageType< typename FieldTypes::compid >::Type compid;
    typename ::uavcan::StorageType< typename FieldTypes::msgid >::Type msgid;
    typename ::uavcan::StorageType< typename FieldTypes::payload >::Type payload;

    MavlinkMessage_()
        : seq()
        , sysid()
        , compid()
        , msgid()
        , payload()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<2080 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 20000 };

    static const char* getDataTypeFullName()
    {
        return "root_ns_a.MavlinkMessage";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool MavlinkMessage_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        seq == rhs.seq &&
        sysid == rhs.sysid &&
        compid == rhs.compid &&
        msgid == rhs.msgid &&
        payload == rhs.payload;
}

template <int _tmpl>
bool MavlinkMessage_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(seq, rhs.seq) &&
        ::uavcan::areClose(sysid, rhs.sysid) &&
        ::uavcan::areClose(compid, rhs.compid) &&
        ::uavcan::areClose(msgid, rhs.msgid) &&
        ::uavcan::areClose(payload, rhs.payload);
}

template <int _tmpl>
int MavlinkMessage_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::seq::encode(self.seq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sysid::encode(self.sysid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::compid::encode(self.compid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::msgid::encode(self.msgid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::payload::encode(self.payload, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int MavlinkMessage_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::seq::decode(self.seq, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sysid::decode(self.sysid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::compid::decode(self.compid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::msgid::decode(self.msgid, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::payload::decode(self.payload, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature MavlinkMessage_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x5B936A2F6DDB49CAULL);

    FieldTypes::seq::extendDataTypeSignature(signature);
    FieldTypes::sysid::extendDataTypeSignature(signature);
    FieldTypes::compid::extendDataTypeSignature(signature);
    FieldTypes::msgid::extendDataTypeSignature(signature);
    FieldTypes::payload::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef MavlinkMessage_<0> MavlinkMessage;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::root_ns_a::MavlinkMessage > _uavcan_gdtr_registrator_MavlinkMessage;

}

} // Namespace root_ns_a

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::root_ns_a::MavlinkMessage >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::root_ns_a::MavlinkMessage::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::root_ns_a::MavlinkMessage >::stream(Stream& s, ::root_ns_a::MavlinkMessage::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "seq: ";
    YamlStreamer< ::root_ns_a::MavlinkMessage::FieldTypes::seq >::stream(s, obj.seq, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "sysid: ";
    YamlStreamer< ::root_ns_a::MavlinkMessage::FieldTypes::sysid >::stream(s, obj.sysid, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "compid: ";
    YamlStreamer< ::root_ns_a::MavlinkMessage::FieldTypes::compid >::stream(s, obj.compid, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "msgid: ";
    YamlStreamer< ::root_ns_a::MavlinkMessage::FieldTypes::msgid >::stream(s, obj.msgid, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "payload: ";
    YamlStreamer< ::root_ns_a::MavlinkMessage::FieldTypes::payload >::stream(s, obj.payload, level + 1);
}

}

namespace root_ns_a
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::root_ns_a::MavlinkMessage::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::root_ns_a::MavlinkMessage >::stream(s, obj, 0);
    return s;
}

} // Namespace root_ns_a

#endif // ROOT_NS_A_MAVLINKMESSAGE_HPP_INCLUDED
