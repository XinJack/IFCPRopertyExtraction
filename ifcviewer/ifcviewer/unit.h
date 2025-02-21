#pragma once


#include	"ifcengine\include\ifcengine.h"
//#include	"GenericTreeItem.h"


#define		ABSORBEDDOSEUNIT					101
#define		AREAUNIT							102
#define		DOSEEQUIVALENTUNIT					103
#define		ELECTRICCAPACITANCEUNIT				104
#define		ELECTRICCHARGEUNIT					105
#define		ELECTRICCONDUCTANCEUNIT				106
#define		ELECTRICCURRENTUNIT					107
#define		ELECTRICRESISTANCEUNIT				108
#define		ELECTRICVOLTAGEUNIT					109
#define		ENERGYUNIT							110
#define		FORCEUNIT							111
#define		FREQUENCYUNIT						112
#define		ILLUMINANCEUNIT						113
#define		INDUCTANCEUNIT						114
#define		LENGTHUNIT							115
#define		LUMINOUSFLUXUNIT					116
#define		LUMINOUSINTENSITYUNIT				117
#define		MAGNETICFLUXDENSITYUNIT				118
#define		MAGNETICFLUXUNIT					119
#define		MASSUNIT							120
#define		PLANEANGLEUNIT						121
#define		POWERUNIT							122
#define		PRESSUREUNIT						123
#define		RADIOACTIVITYUNIT					124
#define		SOLIDANGLEUNIT						125
#define		THERMODYNAMICTEMPERATUREUNIT		126
#define		TIMEUNIT							127
#define		VOLUMEUNIT							128
#define		USERDEFINED							129

#define		STRUCT_TYPE_PROPERTY				203
#define		STRUCT_TYPE_PROPERTY_SET			204



struct STRUCT__SIUNIT {
	int_t							type;
	wchar_t							* unitType;

	wchar_t							* prefix;
	wchar_t							* name;

	STRUCT__SIUNIT					* next;
};

struct STRUCT__PROPERTY {
	int_t							structType;
	int_t							ifcInstance;

	wchar_t							* name;
	wchar_t							* description;

	wchar_t							* nominalValue;
	wchar_t							* lengthValue;
	wchar_t							* areaValue;
	wchar_t							* volumeValue;
	wchar_t							* countValue;
	wchar_t							* weigthValue;
	wchar_t							* timeValue;
	wchar_t							* unit;

	HTREEITEM						hTreeItem;

	wchar_t							* nameBuffer;

	STRUCT__PROPERTY				* next;
};

struct STRUCT__PROPERTY__SET {
	int_t							structType;
	int_t							ifcInstance;

	wchar_t							* name;
	wchar_t							* description;

	STRUCT__PROPERTY				* properties;

	HTREEITEM						hTreeItem;

	wchar_t							* nameBuffer;

	STRUCT__PROPERTY__SET			* next;
};



STRUCT__SIUNIT	* GetUnits(int_t ifcModel, int_t ifcProjectInstance);
void			CreateIfcInstanceProperties(int_t ifcModel, STRUCT__PROPERTY__SET ** propertySets, int_t ifcObjectInstance, STRUCT__SIUNIT * units);
bool			HasChildrenIfcInstanceProperties(int_t ifcModel,/* STRUCT__PROPERTY__SET ** propertySets,*/ int_t ifcObjectInstance);//, STRUCT__SIUNIT * units);
