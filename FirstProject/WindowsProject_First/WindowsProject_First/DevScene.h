#pragma once
#include "Scene.h"

class actor;
class GameObject;
class UI;
class TilemapActor;
class Player;

struct PQNode
{
    PQNode(int32 cost, VectorInt pos) : cost(cost), pos(pos) { }

    bool operator<(const PQNode& other) const { return cost < other.cost; }
    bool operator>(const PQNode& other) const { return cost > other.cost; }

    int32 cost;
    VectorInt pos;
};

class DevScene :
    public Scene
{

    using Super = Scene;

public:
    DevScene();
    virtual ~DevScene() override;

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;

    virtual void AddActor(actor* Actor) override;
    virtual void RemoveActor(actor* Actor) override;

    void LoadMap();
    void LoadPlayer();
    void LoadMonster();
    void LoadProjectile();
    void LoadEffect();
    void LoadTilemap();

    // Template type trait
    template<typename T>
    T* SpawnObject(VectorInt pos)
    {
        auto isGameObject = std::is_convertible_v<T*, GameObject*>;
        assert(isGameObject);

        T* ret = new T();
        ret->SetCellPos(pos, true);
        AddActor(ret);

        ret->BeginPlay();
        return ret;
    }

    template<typename T>
    T* SpawnObjectRandomPos()
    {
        VectorInt randPos = GetRandomEmptyCellPos();
        return SpawnObject<T>(randPos);
    }

    Player* FindClosestPlayer(VectorInt cellPos);
    bool FindPath(VectorInt src, VectorInt dest, vector<VectorInt>& path, int32 maxDepth = 10);

    bool CanGo(VectorInt cellPos);
    Vector ConvertPos(VectorInt cellPos);
    VectorInt GetRandomEmptyCellPos();

private:
    void TickMonsterSpawn();

private:
    const int32 DESIRED_MONSTER_COUNT = 20;
    int32 _monsterCount = 0;

    class TilemapActor* _tilemapActor = nullptr;

};

