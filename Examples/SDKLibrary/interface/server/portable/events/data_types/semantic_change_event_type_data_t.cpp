

/* ------------------------------------------------------------------------------------------------------------------

																				COPYRIGHT (c) 2009 - 2017

																				HONEYWELL INC.,

																				ALL RIGHTS RESERVED



						This software is a copyrighted work and/or information protected as a trade

						secret. Legal rights of Honeywell Inc. in this software are distinct from

						ownership of any medium in which the software is embodied. Copyright or trade

						secret notices included must be reproduced in any copies authorized by

						Honeywell Inc. The information in this software is subject to change without

						notice and should not be considered as a commitment by Honeywell Inc.

--------------------------------------------------------------------------------------------------------------------- */



#include "semantic_change_event_type_data_t.h"

#if (UASDK_INCLUDE_EVENTS > 0)

#include "opcua_node_id_numeric_t.h"
#include "opcua_server_state_t.h"
namespace uasdk
{

UA_DEFINE_RUNTIME_TYPE(SemanticChangeEventTypeData_t, BaseModelChangeEventTypeData_t);

SemanticChangeEventTypeData_t::SemanticChangeEventTypeData_t()
{
}

SemanticChangeEventTypeData_t::~SemanticChangeEventTypeData_t()
{
}

bool SemanticChangeEventTypeData_t::IsOfType(const uint32_t typeId, uint16_t namespaceindex) const
{
	if(namespaceindex != 0) return false;
	return typeId == 2738 || BaseModelChangeEventTypeData_t::IsOfType(typeId, namespaceindex);
}

Status_t SemanticChangeEventTypeData_t::Initialise()
{
	Status_t rtnStatus = OpcUa_Good;
	browseName = new SafeRefCount_t<String_t>();
	UASDK_RETURN_OUT_OF_MEMORY_IF_NULL(browseName);
	rtnStatus = browseName->CopyFrom("SemanticChangeEventType");
	UASDK_RETURN_STATUS_ONLY_IF_BAD(rtnStatus.Value());
	
	changes_Affected.reset();
	
	changes_AffectedType.reset();
	
	changes.Initialise(0);
	
	
	return BaseModelChangeEventTypeData_t::Initialise();
}

uint32_t SemanticChangeEventTypeData_t::TypeId(uint16_t& namespaceIndex) const
{
	namespaceIndex = 0;
	return SemanticChangeEventTypeData_t::TYPE_ID;
}

IntrusivePtr_t<BaseDataType_t> SemanticChangeEventTypeData_t::AttributeValue(const uint32_t& typeId, const ArrayUA_t<QualifiedName_t>&browsePath, const uint32_t &_attributeId, const String_t& _indexRange, const ArrayUA_t<String_t> & locales,  Status_t &result)
{
	
    UASDK_UNUSED(_indexRange);
	result = OpcUa_BadInvalidArgument;
	IntrusivePtr_t<BaseDataType_t> emptyResult;
	emptyResult.reset();
	
	uint16_t namespaceIndex = 0;
	if (!IsOfType(typeId, namespaceIndex))
	{
		return emptyResult;
	}
		
		char nameStr[1024] = { 0 };
    char *loc = &nameStr[0];
		uint32_t nameStrSize = static_cast<uint32_t>(sizeof(nameStr));
    for (uint32_t index = 0; index < browsePath.Count() && static_cast<uint32_t>(loc - nameStr) < (nameStrSize - 2); ++index)
    {
      UASDK_strncat(loc, nameStrSize - (loc - nameStr), (char*)(browsePath[index]->Name().Payload().Data()), browsePath[index]->Name().Payload().Length());
      loc += browsePath[index]->Name().Payload().Length();
      if (index < (browsePath.Count() - 1) && static_cast<uint32_t>(loc - nameStr) < (nameStrSize - 2))
      {
        *loc = '.';
        ++loc;
        *loc = '\0';
      }
	  	nameStrSize = static_cast<uint32_t>(sizeof(nameStr));
		}

	
	/* Start class specific attributes */
	if(UASDK_strcmp(nameStr, "Changes.Affected") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE) //From 1
	
	{
	
		result = OpcUa_Good;
	
		return changes_Affected;
	
	};
	
	
	
	if(UASDK_strcmp(nameStr, "Changes.AffectedType") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE) //From 1
	
	{
	
		result = OpcUa_Good;
	
		return changes_AffectedType;
	
	};
	
	
	
	if(UASDK_strcmp(nameStr, "Changes") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE)  //From  5
	
	{
	
		if(_indexRange.IsNull() == false || _indexRange.Length() == 0)
	
		{
	
			result = OpcUa_Good;
	
			return changes;
	
		}
	
		else
	
		{
	
			Array_t<IndexRange_t> subRanges;
	
			result = Utilities_t::ValidateIndexRange(_indexRange, subRanges);
	
			if(result == OpcUa_Good)
	
			{
	
				IntrusivePtr_t<BaseDataType_t> subArray;
	
				result = changes.WriteSubsetTo(subRanges, subArray);
	
				return subArray;
	
			}
	
		}
	
	};
	
	
	
	
	/* end class specific attributes */
	
		return BaseModelChangeEventTypeData_t::AttributeValue(typeId, browsePath, _attributeId, _indexRange, locales, result); 
	}
	
	IntrusivePtr_t<const BaseDataType_t> SemanticChangeEventTypeData_t::AttributeValue(const uint32_t& typeId, const ArrayUA_t<QualifiedName_t>&browsePath, const uint32_t &_attributeId, const String_t& _indexRange, const ArrayUA_t<String_t> & locales, Status_t &result) const
	{
		
    UASDK_UNUSED(_indexRange);
		IntrusivePtr_t<BaseDataType_t> emptyResult;
		emptyResult.reset();
		result = OpcUa_BadInvalidArgument;
		
		uint16_t namespaceIndex = 0;
		if (!IsOfType(typeId, namespaceIndex))
		{
			return emptyResult;
		}
			
		char nameStr[1024] = { 0 };
    char *loc = &nameStr[0];
		uint32_t nameStrSize = static_cast<uint32_t>(sizeof(nameStr));
    for (uint32_t index = 0; index < browsePath.Count() && static_cast<uint32_t>(loc - nameStr) < (nameStrSize - 2); ++index)
    {
      UASDK_strncat(loc, nameStrSize - (loc - nameStr), (char*)(browsePath[index]->Name().Payload().Data()), browsePath[index]->Name().Payload().Length());
      loc += browsePath[index]->Name().Payload().Length();
      if (index < (browsePath.Count() - 1) && static_cast<uint32_t>(loc - nameStr) < (nameStrSize - 2))
      {
        *loc = '.';
        ++loc;
        *loc = '\0';
      }
	  	nameStrSize = static_cast<uint32_t>(sizeof(nameStr));
		}

		
		/* Start class specific attributes */
		if(UASDK_strcmp(nameStr, "Changes.Affected") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE) //From 1
		
		{
		
			result = OpcUa_Good;
		
			return changes_Affected;
		
		};
		
		
		
		if(UASDK_strcmp(nameStr, "Changes.AffectedType") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE) //From 1
		
		{
		
			result = OpcUa_Good;
		
			return changes_AffectedType;
		
		};
		
		
		
		if(UASDK_strcmp(nameStr, "Changes") == 0 && _attributeId == AttributeId_t::ATTRIBUTE_ID_VALUE)  //From  5
		
		{
		
			if(_indexRange.IsNull() == false || _indexRange.Length() == 0)
		
			{
		
				result = OpcUa_Good;
		
				return changes;
		
			}
		
			else
		
			{
		
				Array_t<IndexRange_t> subRanges;
		
				result = Utilities_t::ValidateIndexRange(_indexRange, subRanges);
		
				if(result == OpcUa_Good)
		
				{
		
					IntrusivePtr_t<BaseDataType_t> subArray;
		
					result = changes.WriteSubsetTo(subRanges, subArray);
		
					return subArray;
		
				}
		
			}
		
		};
		
		
		
		
		/* end class specific attributes */
		
		return BaseModelChangeEventTypeData_t::AttributeValue(typeId, browsePath, _attributeId, _indexRange, locales, result); 
	}
	
	Status_t SemanticChangeEventTypeData_t::CopyTo(IntrusivePtr_t<BaseDataType_t>& destination) const
	{
		return CopyToDestination(*this, destination);
	}
	
	Status_t SemanticChangeEventTypeData_t::CopyFrom(const BaseDataType_t& source)
	{
		IntrusivePtr_t<const SemanticChangeEventTypeData_t> ptr = RuntimeCast<const SemanticChangeEventTypeData_t*>(source);
		if (!ptr.is_set())
		{
			return OpcUa_BadTypeMismatch;
		}
		
		return CopyFrom(*ptr);
	}
	
	Status_t SemanticChangeEventTypeData_t::CopyFrom(const SemanticChangeEventTypeData_t& source)
	{
		Status_t result = OpcUa_Good;
		changes_Affected.reset();
		
		if(source.changes_Affected.is_set())
		
		{
		
		  result = source.changes_Affected->CopyToNodeId(changes_Affected);
		
		  if(result.IsBad())
		
		  {
		
		    return result;
		
		  }
		
		}
		
		
		
		changes_AffectedType.reset();
		
		if(source.changes_AffectedType.is_set())
		
		{
		
		  result = source.changes_AffectedType->CopyToNodeId(changes_AffectedType);
		
		  if(result.IsBad())
		
		  {
		
		    return result;
		
		  }
		
		}
		
		
		
		changes.Initialise(0);
		
		result = changes.CopyFrom(source.changes);
		
		if(result.IsBad())
		
		{
		
		  return result;
		
		}
		
		
		
		
		result = BaseModelChangeEventTypeData_t::CopyFrom(source);
		return result;
	}
	
} // namespace

#endif //(UASDK_INCLUDE_EVENTS > 0)

