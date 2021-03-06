// Generated by gencpp from file landing/center.msg
// DO NOT EDIT!


#ifndef LANDING_MESSAGE_CENTER_H
#define LANDING_MESSAGE_CENTER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace landing
{
template <class ContainerAllocator>
struct center_
{
  typedef center_<ContainerAllocator> Type;

  center_()
    : width(0)
    , height(0)
    , x(0.0)
    , y(0.0)
    , iffind(false)  {
    }
  center_(const ContainerAllocator& _alloc)
    : width(0)
    , height(0)
    , x(0.0)
    , y(0.0)
    , iffind(false)  {
  (void)_alloc;
    }



   typedef uint32_t _width_type;
  _width_type width;

   typedef uint32_t _height_type;
  _height_type height;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef uint8_t _iffind_type;
  _iffind_type iffind;





  typedef boost::shared_ptr< ::landing::center_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::landing::center_<ContainerAllocator> const> ConstPtr;

}; // struct center_

typedef ::landing::center_<std::allocator<void> > center;

typedef boost::shared_ptr< ::landing::center > centerPtr;
typedef boost::shared_ptr< ::landing::center const> centerConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::landing::center_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::landing::center_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::landing::center_<ContainerAllocator1> & lhs, const ::landing::center_<ContainerAllocator2> & rhs)
{
  return lhs.width == rhs.width &&
    lhs.height == rhs.height &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.iffind == rhs.iffind;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::landing::center_<ContainerAllocator1> & lhs, const ::landing::center_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace landing

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::landing::center_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::landing::center_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::landing::center_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::landing::center_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::landing::center_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::landing::center_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::landing::center_<ContainerAllocator> >
{
  static const char* value()
  {
    return "435bfc8b0a9a23f7ba5ab3357a37f574";
  }

  static const char* value(const ::landing::center_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x435bfc8b0a9a23f7ULL;
  static const uint64_t static_value2 = 0xba5ab3357a37f574ULL;
};

template<class ContainerAllocator>
struct DataType< ::landing::center_<ContainerAllocator> >
{
  static const char* value()
  {
    return "landing/center";
  }

  static const char* value(const ::landing::center_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::landing::center_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 width\n"
"uint32 height\n"
"float64 x\n"
"float64 y\n"
"bool iffind\n"
;
  }

  static const char* value(const ::landing::center_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::landing::center_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.iffind);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct center_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::landing::center_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::landing::center_<ContainerAllocator>& v)
  {
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "iffind: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.iffind);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LANDING_MESSAGE_CENTER_H
