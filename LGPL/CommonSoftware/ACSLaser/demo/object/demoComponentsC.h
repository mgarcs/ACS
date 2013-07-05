// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.1
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:149

#ifndef _TAO_IDL__TMP__DEMOCOMPONENTSC_H_
#define _TAO_IDL__TMP__DEMOCOMPONENTSC_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "acscomponentC.h"
#include "CosPropertyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from 
// be/be_visitor_root/root_ch.cpp:151
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:41

namespace alarmsystemdemo
{
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:785

#if !defined (_ALARMSYSTEMDEMO_PS__VAR_OUT_CH_)
#define _ALARMSYSTEMDEMO_PS__VAR_OUT_CH_
  
  class PS;
  typedef PS *PS_ptr;
  
  typedef
    TAO_Objref_Var_T<
        PS
      >
    PS_var;
  
  typedef
    TAO_Objref_Out_T<
        PS
      >
    PS_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:45
  
  class  PS
    : public virtual ::ACS::ACSComponent
  {
  public:
    friend class TAO::Narrow_Utils<PS>;
    typedef PS_ptr _ptr_type;
    typedef PS_var _var_type;
    typedef PS_out _out_type;
    
    // The static operations.
    static PS_ptr _duplicate (PS_ptr obj);
    
    static void _tao_release (PS_ptr obj);
    
    static PS_ptr _narrow (::CORBA::Object_ptr obj);
    static PS_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static PS_ptr _nil (void)
    {
      return static_cast<PS_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    faultPS (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    terminate_faultPS (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:204
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_PS_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    PS (void);
    
    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void alarmsystemdemo_PS_setup_collocation (void);
    
    // Concrete non-local interface only.
    PS (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    PS (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~PS (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    PS (const PS &);
    
    void operator= (const PS &);
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:39
  
  extern  ::CORBA::TypeCode_ptr const _tc_PS;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:785

#if !defined (_ALARMSYSTEMDEMO_MOUNT__VAR_OUT_CH_)
#define _ALARMSYSTEMDEMO_MOUNT__VAR_OUT_CH_
  
  class Mount;
  typedef Mount *Mount_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Mount
      >
    Mount_var;
  
  typedef
    TAO_Objref_Out_T<
        Mount
      >
    Mount_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:45
  
  class  Mount
    : public virtual ::ACS::ACSComponent
  {
  public:
    friend class TAO::Narrow_Utils<Mount>;
    typedef Mount_ptr _ptr_type;
    typedef Mount_var _var_type;
    typedef Mount_out _out_type;
    
    // The static operations.
    static Mount_ptr _duplicate (Mount_ptr obj);
    
    static void _tao_release (Mount_ptr obj);
    
    static Mount_ptr _narrow (::CORBA::Object_ptr obj);
    static Mount_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Mount_ptr _nil (void)
    {
      return static_cast<Mount_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    faultMount (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    terminate_faultMount (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:204
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Mount_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    Mount (void);
    
    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void alarmsystemdemo_Mount_setup_collocation (void);
    
    // Concrete non-local interface only.
    Mount (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    Mount (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~Mount (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Mount (const Mount &);
    
    void operator= (const Mount &);
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:39
  
  extern  ::CORBA::TypeCode_ptr const _tc_Mount;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:785

#if !defined (_ALARMSYSTEMDEMO_ANTENNA__VAR_OUT_CH_)
#define _ALARMSYSTEMDEMO_ANTENNA__VAR_OUT_CH_
  
  class Antenna;
  typedef Antenna *Antenna_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Antenna
      >
    Antenna_var;
  
  typedef
    TAO_Objref_Out_T<
        Antenna
      >
    Antenna_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:45
  
  class  Antenna
    : public virtual ::ACS::ACSComponent
  {
  public:
    friend class TAO::Narrow_Utils<Antenna>;
    typedef Antenna_ptr _ptr_type;
    typedef Antenna_var _var_type;
    typedef Antenna_out _out_type;
    
    // The static operations.
    static Antenna_ptr _duplicate (Antenna_ptr obj);
    
    static void _tao_release (Antenna_ptr obj);
    
    static Antenna_ptr _narrow (::CORBA::Object_ptr obj);
    static Antenna_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Antenna_ptr _nil (void)
    {
      return static_cast<Antenna_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    faultAntenna (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    terminate_faultAntenna (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:204
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Antenna_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    Antenna (void);
    
    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void alarmsystemdemo_Antenna_setup_collocation (void);
    
    // Concrete non-local interface only.
    Antenna (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    Antenna (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~Antenna (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Antenna (const Antenna &);
    
    void operator= (const Antenna &);
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:39
  
  extern  ::CORBA::TypeCode_ptr const _tc_Antenna;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:785

#if !defined (_ALARMSYSTEMDEMO_MF__VAR_OUT_CH_)
#define _ALARMSYSTEMDEMO_MF__VAR_OUT_CH_
  
  class MF;
  typedef MF *MF_ptr;
  
  typedef
    TAO_Objref_Var_T<
        MF
      >
    MF_var;
  
  typedef
    TAO_Objref_Out_T<
        MF
      >
    MF_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:45
  
  class  MF
    : public virtual ::ACS::ACSComponent
  {
  public:
    friend class TAO::Narrow_Utils<MF>;
    typedef MF_ptr _ptr_type;
    typedef MF_var _var_type;
    typedef MF_out _out_type;
    
    // The static operations.
    static MF_ptr _duplicate (MF_ptr obj);
    
    static void _tao_release (MF_ptr obj);
    
    static MF_ptr _narrow (::CORBA::Object_ptr obj);
    static MF_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static MF_ptr _nil (void)
    {
      return static_cast<MF_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    multiFault (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36
    
    virtual void
    terminate_multiFault (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:204
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_MF_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    MF (void);
    
    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void alarmsystemdemo_MF_setup_collocation (void);
    
    // Concrete non-local interface only.
    MF (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    MF (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~MF (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    MF (const MF &);
    
    void operator= (const MF &);
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:39
  
  extern  ::CORBA::TypeCode_ptr const _tc_MF;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:70

} // module alarmsystemdemo

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be/be_visitor_root/root_ch.cpp:193

extern 
TAO::Collocation_Proxy_Broker *
(*alarmsystemdemo__TAO_PS_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*alarmsystemdemo__TAO_Mount_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*alarmsystemdemo__TAO_Antenna_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*alarmsystemdemo__TAO_MF_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:60

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_ALARMSYSTEMDEMO_PS__TRAITS_)
#define _ALARMSYSTEMDEMO_PS__TRAITS_
  
  template<>
  struct  Objref_Traits< ::alarmsystemdemo::PS>
  {
    static ::alarmsystemdemo::PS_ptr duplicate (
        ::alarmsystemdemo::PS_ptr p);
    static void release (
        ::alarmsystemdemo::PS_ptr p);
    static ::alarmsystemdemo::PS_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::alarmsystemdemo::PS_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_ALARMSYSTEMDEMO_MOUNT__TRAITS_)
#define _ALARMSYSTEMDEMO_MOUNT__TRAITS_
  
  template<>
  struct  Objref_Traits< ::alarmsystemdemo::Mount>
  {
    static ::alarmsystemdemo::Mount_ptr duplicate (
        ::alarmsystemdemo::Mount_ptr p);
    static void release (
        ::alarmsystemdemo::Mount_ptr p);
    static ::alarmsystemdemo::Mount_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::alarmsystemdemo::Mount_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_ALARMSYSTEMDEMO_ANTENNA__TRAITS_)
#define _ALARMSYSTEMDEMO_ANTENNA__TRAITS_
  
  template<>
  struct  Objref_Traits< ::alarmsystemdemo::Antenna>
  {
    static ::alarmsystemdemo::Antenna_ptr duplicate (
        ::alarmsystemdemo::Antenna_ptr p);
    static void release (
        ::alarmsystemdemo::Antenna_ptr p);
    static ::alarmsystemdemo::Antenna_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::alarmsystemdemo::Antenna_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_ALARMSYSTEMDEMO_MF__TRAITS_)
#define _ALARMSYSTEMDEMO_MF__TRAITS_
  
  template<>
  struct  Objref_Traits< ::alarmsystemdemo::MF>
  {
    static ::alarmsystemdemo::MF_ptr duplicate (
        ::alarmsystemdemo::MF_ptr p);
    static void release (
        ::alarmsystemdemo::MF_ptr p);
    static ::alarmsystemdemo::MF_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::alarmsystemdemo::MF_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace alarmsystemdemo
{
   void operator<<= ( ::CORBA::Any &, PS_ptr); // copying
   void operator<<= ( ::CORBA::Any &, PS_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, PS_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, alarmsystemdemo::PS_ptr); // copying
 void operator<<= (::CORBA::Any &, alarmsystemdemo::PS_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, alarmsystemdemo::PS_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace alarmsystemdemo
{
   void operator<<= ( ::CORBA::Any &, Mount_ptr); // copying
   void operator<<= ( ::CORBA::Any &, Mount_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Mount_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, alarmsystemdemo::Mount_ptr); // copying
 void operator<<= (::CORBA::Any &, alarmsystemdemo::Mount_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, alarmsystemdemo::Mount_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace alarmsystemdemo
{
   void operator<<= ( ::CORBA::Any &, Antenna_ptr); // copying
   void operator<<= ( ::CORBA::Any &, Antenna_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Antenna_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, alarmsystemdemo::Antenna_ptr); // copying
 void operator<<= (::CORBA::Any &, alarmsystemdemo::Antenna_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, alarmsystemdemo::Antenna_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace alarmsystemdemo
{
   void operator<<= ( ::CORBA::Any &, MF_ptr); // copying
   void operator<<= ( ::CORBA::Any &, MF_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, MF_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, alarmsystemdemo::MF_ptr); // copying
 void operator<<= (::CORBA::Any &, alarmsystemdemo::MF_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, alarmsystemdemo::MF_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:46

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const alarmsystemdemo::PS_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, alarmsystemdemo::PS_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:46

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const alarmsystemdemo::Mount_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, alarmsystemdemo::Mount_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:46

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const alarmsystemdemo::Antenna_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, alarmsystemdemo::Antenna_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:46

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const alarmsystemdemo::MF_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, alarmsystemdemo::MF_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1786
#if defined (__ACE_INLINE__)
#include "demoComponentsC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

