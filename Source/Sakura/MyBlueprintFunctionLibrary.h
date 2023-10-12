// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SAKURA_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
		static TArray<UTexture2D*> LoadTextureFromDir(FString path);


	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
		static TArray<AActor*> LoadActorFromDir(FString Path);

	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
		static AActor* LoadActorFromPath(FString Path);

	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
		static UClass* GetClassFromPath(FString Path);

};
