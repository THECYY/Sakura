// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include <Runtime/Engine/Public/EngineUtils.h>

TArray<UTexture2D*> UMyBlueprintFunctionLibrary::LoadTextureFromDir(FString Path) {
	TArray<UObject*> LoadedAsseObjects;
	TArray<UTexture2D*> Textures;
	if (EngineUtils::FindOrLoadAssetsByPath(Path, LoadedAsseObjects, EngineUtils::ATL_Regular)) {
		for (UObject* Object : LoadedAsseObjects) {
			UTexture2D* Texture = Cast<UTexture2D>(Object);
			if (Texture != NULL) {
				Textures.Add(Texture);
			}
		}
	}
	return Textures;
}


TArray<AActor*> UMyBlueprintFunctionLibrary::LoadActorFromDir(FString Path) {
	TArray<UObject*> LoadedAsseObjects;
	TArray<AActor*> Actors;
	if (EngineUtils::FindOrLoadAssetsByPath(Path, LoadedAsseObjects, EngineUtils::ATL_Regular)) {
		for (UObject* Object : LoadedAsseObjects) {
			AActor* Actor = Cast<AActor>(Object);
			Actors.Add(Actor);
		} 
	}
	return Actors;
}

AActor* UMyBlueprintFunctionLibrary::LoadActorFromPath(FString Path) {
	FSoftObjectPath Aim = Path;
	UObject* object = Aim.TryLoad();
	AActor* Actor = Cast<AActor>(object);
	return Actor;
} 


UClass* UMyBlueprintFunctionLibrary::GetClassFromPath(FString Path) {
	FSoftClassPath SoftBPClassPathName = Path;
	SoftBPClassPathName.TryLoadClass<AActor>();
	TSoftClassPtr<AActor> ActorClassPtr = TSoftClassPtr<AActor>(SoftBPClassPathName);
	UClass* pClass = ActorClassPtr.Get();
	return pClass;
}