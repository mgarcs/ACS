/*******************************************************************************
* ALMA - Atacama Large Millimiter Array
* (c) European Southern Observatory, 2011
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* "@(#) $Id: bulkDataNTStream.cpp,v 1.28 2011/12/15 11:15:04 bjeram Exp $"
*
* who       when      what
* --------  --------  ----------------------------------------------
* bjeram  2011-04-19  created
*/
#include "bulkDataNTStream.h"
#include <iostream>
using namespace ACS_BD_Errors;
using namespace ACSErrTypeCommon;
using namespace ACS_DDS_Errors;

using namespace AcsBulkdata;

unsigned int BulkDataNTStream::factoryRefCount_m = 0;
unsigned int BulkDataNTStream::participantRefCount_m = 0;
//DDS::DomainParticipant* BulkDataNTStream::participant_m=0;

BulkDataNTStream::BulkDataNTStream(const char* name, const StreamConfiguration &cfg) :
	    streamName_m(name), configuration_m(cfg), factory_m(0), participant_m(0)
{
  AUTO_TRACE(__PRETTY_FUNCTION__);


  try
  {
      //RTI logging
      NDDSConfigLogger::get_instance()->set_verbosity_by_category(
          NDDS_CONFIG_LOG_CATEGORY_API,  (NDDS_Config_LogVerbosity)(configuration_m.DDSLogVerbosity)); //TBD: should be done just once

      //   if (factoryRefCount_m==0)
      //     {
      createDDSFactory();  //it is enough to have one factory
      //     }
      factoryRefCount_m++; //anyway we have to increase the counter that we know when to call finalize_instance

      addDDSQoSProfile(cfg);  //add QoS profile for stream (and flows)

  //    if (participantRefCount_m==0)
   //     {
          // TBD: for performance reason (number of threads) is better to have just one participant, but it might be good to have possibility to create
          // also a participant per stream
          createDDSParticipant();     //should be somewhere else in initialize or createStream
     //   }
     // participantRefCount_m++;   // but we need to know how many users of participant do we have
  }catch(const ACSErr::ACSbaseExImpl &e)
  {
      if (factory_m!=0)
        DDS::DomainParticipantFactory::finalize_instance();
      StreamCreateProblemExImpl ex (e, __FILE__, __LINE__, __PRETTY_FUNCTION__);
      ex.setStreamName(name);
      throw ex;
  }//try-catch
}//BulkDataNTStream


BulkDataNTStream::~BulkDataNTStream()
{
  AUTO_TRACE(__PRETTY_FUNCTION__);

  //participantRefCount_m--;
  //if (participantRefCount_m==0)
  destroyDDSParticipant();

  factoryRefCount_m--;
  if (factoryRefCount_m==0)  DDS::DomainParticipantFactory::finalize_instance();
}//~BulkDataNTStream


void BulkDataNTStream::createDDSFactory()
{
	AUTO_TRACE(__PRETTY_FUNCTION__);
	DDS::ReturnCode_t ret;
	DDS::DomainParticipantFactoryQos factory_qos;

	factory_m = DDS::DomainParticipantFactory::get_instance();

	// needed by RTI only
	ret = factory_m->get_qos(factory_qos);
	if (ret!=DDS::RETCODE_OK)
	{
		DDSQoSSetProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.setDDSTypeCode(ret);
		ex.setQoS("factory_m->get_qos");
		throw ex;
	}//if
	factory_qos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

	// if both values are true (default) we prevent that default values are taken from default places
	factory_qos.profile.ignore_user_profile = configuration_m.ignoreUserProfileQoS;
	factory_qos.profile.ignore_environment_profile = configuration_m.ignoreEnvironmentProfileQoS;
	//factory_qos.resource_limits.max_objects_per_thread = 4096; //if we want to have more than 10 participants

/***
	if (configuration_m.stringProfileQoS.length()>0)
	{
	    unsigned int profLen=factory_qos.profile.string_profile.length();
	    std::cout << "string_profile length: " << factory_qos.profile.string_profile.length() << std::endl;
	    std::cout << "string_profile max: " << factory_qos.profile.string_profile.maximum() << std::endl;
	    if (profLen!=0)
	      {
	        factory_qos.profile.string_profile.ensure_length(profLen+1, profLen+1);

	      }
	    else
	      {
	        factory_qos.profile.string_profile.ensure_length(3,3);
	        factory_qos.profile.string_profile[0] = DDS_String_dup("<dds><qos_library name=\"DynamicLib\">");
	        profLen=2;

	      }
              factory_qos.profile.string_profile[profLen-1]=DDS_String_dup(configuration_m.stringProfileQoS.c_str());
              factory_qos.profile.string_profile[profLen] = DDS_String_dup("</qos_library></dds>");

//		factory_qos.profile.string_profile.ensure_length(1,1);
//		factory_qos.profile.string_profile[0] = DDS_String_dup("<dds><qos_library name=\"DynamicLib\">");
//              factory_qos.profile.string_profile.ensure_length(3,3);
//		factory_qos.profile.string_profile[1] = DDS_String_dup(configuration_m.stringProfileQoS.c_str());
std::cout << "========> " << configuration_m.stringProfileQoS << std::endl;
std::cout << ">>>>>>>>> " << configuration_m.libraryQos << " " << configuration_m.profileQos << std::endl;
//		factory_qos.profile.string_profile[2] = DDS_String_dup("</qos_library></dds>");

		//cout << "string_profile: " << configuration_m.stringProfileQoS << endl;
	}//if
*/
//	std::cout << "========> " << configuration_m.stringProfileQoS << std::endl;
//	std::cout << ">>>>>>>>> " << configuration_m.libraryQos << " " << configuration_m.profileQos << std::endl;
	if (configuration_m.urlProfileQoS.length()>0)
	{
		factory_qos.profile.url_profile.ensure_length(1,1);
		factory_qos.profile.url_profile[0] = DDS_String_dup(configuration_m.urlProfileQoS.c_str());
	}//if
	ret = factory_m->set_qos(factory_qos);
	if (ret!=DDS::RETCODE_OK)
	{
		DDSQoSSetProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.setDDSTypeCode(ret);
		ex.setQoS("factory_m->set_qos");
		throw ex;
	}//if

}//createDDSFactory

void BulkDataNTStream::createDDSParticipant()
{
	AUTO_TRACE(__PRETTY_FUNCTION__);
	DDS::ReturnCode_t ret;
	DDS::DomainParticipantQos participant_qos;
	int domainID=0; //TBD: where to get domain ID

	if (factory_m==NULL)
	{
		NullPointerExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.setVariable("factory_m");
		throw ex;
	}

	if (participant_m!=NULL)
	{
		printf("participant already created\n");
		return;
	}

	ret = factory_m->get_participant_qos_from_profile(participant_qos, configuration_m.libraryQos.c_str(), configuration_m.profileQos.c_str());
	if (ret!=DDS::RETCODE_OK)
	{
		DDSQoSSetProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.setDDSTypeCode(ret);
		ex.setQoS("get_participant_qos_from_profile");
		throw ex;
	}//if

	participant_m =factory_m->create_participant(domainID, participant_qos, NULL, DDS::STATUS_MASK_NONE );
	if (participant_m==NULL)
	{
		DDSParticipantCreateProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.setDomainID(domainID);
		throw ex;
	}

	ret = participant_m->enable();
	if (ret!=DDS::RETCODE_OK)
	  {
	    DDSParticipantEnableProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
	    ex.setDDSTypeCode(ret);
	    ex.setDomainID(domainID);
	    throw ex;
	  }//if
}//createDDSParticipant

void BulkDataNTStream::destroyDDSParticipant()
{
	DDS::ReturnCode_t ret;
	AUTO_TRACE(__PRETTY_FUNCTION__);
	ret = factory_m->delete_participant(participant_m);
	if (ret != DDS_RETCODE_OK)
	{
		DDSParticipantDestroyProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
		ex.log();
	}//if
}//destroyDDSParticipant


void BulkDataNTStream::addDDSQoSProfile(const DDSConfiguration &cfg)
{
  DDS::ReturnCode_t ret;
  DDS::DomainParticipantFactoryQos factory_qos;
  unsigned int profLen;

  if (cfg.stringProfileQoS.length()<=0) return; // if QoSprofile is empty

  // needed by RTI only
  ret = factory_m->get_qos(factory_qos);
  if (ret!=DDS::RETCODE_OK)
    {
      DDSQoSSetProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
      ex.setDDSTypeCode(ret);
      ex.setQoS("factory_m->get_qos");
      throw ex;
    }//if

  profLen=factory_qos.profile.string_profile.length(); //how many profiles do we have already ?

  if (profLen!=0) // is is the first profile
    {
      factory_qos.profile.string_profile.ensure_length(profLen+1, profLen+1);
    }
  else
    {
      factory_qos.profile.string_profile.ensure_length(3,3);
      profLen=2;
    }

  std::string qoSlibTag("<dds><qos_library name=\"");
  qoSlibTag+=cfg.libraryQos;
  qoSlibTag+="\">";

  factory_qos.profile.string_profile[0] = DDS_String_dup(qoSlibTag.c_str());//"<dds><qos_library name=\"DynamicLib\">");
  factory_qos.profile.string_profile[profLen-1]=DDS_String_dup(cfg.stringProfileQoS.c_str());
  factory_qos.profile.string_profile[profLen] = DDS_String_dup("</qos_library></dds>");

  ret = factory_m->set_qos(factory_qos);
  if (ret!=DDS::RETCODE_OK)
    {
      DDSQoSSetProblemExImpl ex(__FILE__, __LINE__, __PRETTY_FUNCTION__);
      ex.setDDSTypeCode(ret);
      ex.setQoS("factory_m->set_qos");
      throw ex;
    }//if
}//addDDSQoSProfile
