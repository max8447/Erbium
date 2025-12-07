#pragma once

#include "../../pch.h"

#include "../SDK/Engine.h"
#include "../Erbium/FortniteGame/Public/FortInventory.h"

class UFortCampsiteAccountItemDefinition : public UFortItemDefinition
{
public:

	UCLASS_COMMON_MEMBERS(UFortCampsiteAccountItemDefinition);
};

struct FCampsiteAccountData
{
public:

	USCRIPTSTRUCT_COMMON_MEMBERS(FCampsiteAccountData);
};

class AAbandonedCampsitePlacedSpawner : public AActor
{
public:

	UCLASS_COMMON_MEMBERS(AAbandonedCampsitePlacedSpawner);

	DEFINE_FUNC(SpawnCampsite, void);
};

class UFortGameStateComponent_Campsite : public UActorComponent
{
public:

	UCLASS_COMMON_MEMBERS(UFortGameStateComponent_Campsite);

	DEFINE_PROP(PlacedCampsiteSpawnPoints, TArray<AAbandonedCampsitePlacedSpawner*>);
};

class UCampsiteFunctionLibraryNative : public UObject
{
public:

	UCLASS_COMMON_MEMBERS(UCampsiteFunctionLibraryNative);

	DEFINE_STATIC_FUNC(GetItemEntryCopyFromWeapon, FFortItemEntry);
};

class UFortControllerComponent_CampsiteAccountItem : public UActorComponent
{
public:

	UCLASS_COMMON_MEMBERS(UFortControllerComponent_CampsiteAccountItem);

	DEFINE_PROP(CampsiteAccountItemDefinition, UFortCampsiteAccountItemDefinition*);
	DEFINE_PROP(CampsiteAccountData, FCampsiteAccountData);
	DEFINE_PROP(CurrentlyStashedItemEntries, TArray<FFortItemEntry>);

	InitPostLoadHooks;
};