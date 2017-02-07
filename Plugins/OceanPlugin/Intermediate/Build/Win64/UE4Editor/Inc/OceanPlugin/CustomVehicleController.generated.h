// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef OCEANPLUGIN_CustomVehicleController_generated_h
#error "CustomVehicleController.generated.h already included, missing '#pragma once' in CustomVehicleController.h"
#endif
#define OCEANPLUGIN_CustomVehicleController_generated_h

#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnableBuoyancy) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnableBuoyancy(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDrawBuoyancyPoints) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DrawBuoyancyPoints(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsDriving) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsDriving(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExitVehicle) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ExitVehicle(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnterVehicle) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Vehicle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnterVehicle(Z_Param_Vehicle); \
		P_NATIVE_END; \
	}


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnableBuoyancy) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnableBuoyancy(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDrawBuoyancyPoints) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DrawBuoyancyPoints(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsDriving) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsDriving(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExitVehicle) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ExitVehicle(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnterVehicle) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Vehicle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnterVehicle(Z_Param_Vehicle); \
		P_NATIVE_END; \
	}


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesACustomVehicleController(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_ACustomVehicleController(); \
	public: \
	DECLARE_CLASS(ACustomVehicleController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/OceanPlugin"), NO_API) \
	DECLARE_SERIALIZER(ACustomVehicleController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS \
	private: \
	static void StaticRegisterNativesACustomVehicleController(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_ACustomVehicleController(); \
	public: \
	DECLARE_CLASS(ACustomVehicleController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/OceanPlugin"), NO_API) \
	DECLARE_SERIALIZER(ACustomVehicleController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomVehicleController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomVehicleController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomVehicleController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomVehicleController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomVehicleController(ACustomVehicleController&&); \
	NO_API ACustomVehicleController(const ACustomVehicleController&); \
public:


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomVehicleController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomVehicleController(ACustomVehicleController&&); \
	NO_API ACustomVehicleController(const ACustomVehicleController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomVehicleController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomVehicleController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomVehicleController)


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerPawn() { return STRUCT_OFFSET(ACustomVehicleController, PlayerPawn); }


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_29_PROLOG
#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_PRIVATE_PROPERTY_OFFSET \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_PRIVATE_PROPERTY_OFFSET \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS_NO_PURE_DECLS \
	Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CustomVehicleController."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Kibbutz_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
