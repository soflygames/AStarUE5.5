#pragma once

#include "CoreMinimal.h"
#include "NavigationData.h"
#include "GraphAStar.h"
#include "WorldGridPathfinding.h"
#include "WorldGridNavigationData.generated.h"

class AWorldGrid;

UCLASS(config = Engine, defaultconfig, hidecategories = (Input, Rendering, Tags, "Utilities|Transformation", Actor, Layers, Replication), notplaceable)
class ASTAR425_API AWorldGridNavigationData : public ANavigationData
{
	GENERATED_BODY()

	AWorldGridNavigationData(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

public:
	static FPathFindingResult FindPath(const FNavAgentProperties& AgentProperties, const FPathFindingQuery& Query);

	bool ProjectPoint(const FVector& Point, FNavLocation& OutLocation, const FVector& Extent, FSharedConstNavQueryFilter Filter = NULL, const UObject* Querier = NULL) const override;

private:
	AWorldGrid* WorldGridActor;

	WorldGridGraph Graph;
	FGraphAStar<WorldGridGraph>* Pathfinder;
};
