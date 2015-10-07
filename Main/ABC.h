/* ABC class created by Sam Rivera and further edited by Darrell Smith */

#pragma once

//d3d includes and libraries
// SAM
#include "D3DUtils.h"
// #include <d3d9.h>
// #include <d3dx9.h>
// #pragma comment(lib, "d3d9.lib")

namespace GSP420
{
	enum ObjType {
		OT_BEGIN = -1,
		OT_LARGE_ASTEROID,
		OT_SMALL_ASTEROID,
		OT_ENEMY1,
		OT_ENEMY2,
		OT_ENEMY3,
		OT_ENEMYBOSS,
		OT_PICKUP,
		OT_PLAYER_BULLET,
		OT_ENEMY_BULLET,
		OT_PLAYER_MISSILE,
		OT_ENEMY_MISSILE,
		OT_PLAYER,
		OT_END
	};

	class ABC
	{
	public:
		ABC() : bEnabled(true) {}
		ABC(const ObjType t) : eType(t), bEnabled(true) {}
		ABC(const D3DXVECTOR3 p, const ObjType t) :
			position(p), eType(t), bEnabled(true), velocity(D3DXVECTOR3(0.f, 0.f, 0.f)) {}
		ABC(const D3DXVECTOR3 p, const D3DXVECTOR3 v, const ObjType t) :
			position(p), velocity(v), eType(t), bEnabled(true) {}
		ABC(const D3DXVECTOR3 p, const int h, const ObjType t) :
			position(p), velocity(D3DXVECTOR3(0.f, 0.f, 0.f)), nHealth(h), eType(t), bEnabled(true) {}
		ABC(const D3DXVECTOR3 p, const D3DXVECTOR3 v, const int h, const ObjType t) :
			position(p), velocity(v), nHealth(h), eType(t), bEnabled(true) {}

		virtual bool init(const int modelId, const int textureId) { 
			nModelId = modelId; nTextureId = textureId;
			return true; }
		virtual void update(const float dt) {}
		virtual void shutdown() {}

		inline D3DXVECTOR3& getPosition() { return position; }
		inline D3DXVECTOR3& getVelocity() { return velocity; }
		inline int getHealth() { return nHealth; }
		inline int getModelId() { return nModelId; }
		inline int getTextureId() { return nTextureId; }
		inline ObjType getObjectType() { return eType; }
		inline bool isEnabled() { return bEnabled; }
		inline void setPosition(const D3DXVECTOR3& pos) { position = pos; }
		inline void setVelocity(const D3DXVECTOR3& velo) { velocity = velo; }
		inline void setFixedRotation(const D3DXVECTOR3& rot) { fixedRotation = rot; }
		inline void setHealth(const int health) { nHealth = health; }
		inline void toggleEnabled() { bEnabled = !bEnabled; }
		inline void setEnabled(const bool enabled) { bEnabled = enabled; }
		inline void setObjectType(ObjType t) { eType = t; }

		inline const D3DXVECTOR3& getPosition() const;
		inline const D3DXVECTOR3& getVelocity() const;
		inline const D3DXVECTOR3& getFixedRotation() const;
		inline const D3DXVECTOR3& getScale() const;
	//	inline int getHealth() const;
		inline int getModelId() const;
		inline int getTextureId() const;

		//ABC(const ABC&);
		virtual ~ABC() {}

	protected:
		D3DXVECTOR3		position;
		D3DXVECTOR3		velocity;
		D3DXVECTOR3		fixedRotation;
		D3DXVECTOR3		scale;

		ObjType		eType;

		int		nHealth;
		int		nTextureId;
		int		nModelId;
		int		nObjectId;

		bool	bEnabled;
	};


	const D3DXVECTOR3& GSP420::ABC::getPosition() const	{ return position; }
	const D3DXVECTOR3& GSP420::ABC::getVelocity() const { return velocity; }
	const D3DXVECTOR3& GSP420::ABC::getFixedRotation() const { return fixedRotation; }
	const D3DXVECTOR3& GSP420::ABC::getScale() const { return scale; }
	int GSP420::ABC::getModelId() const	{ return nModelId; }
	int GSP420::ABC::getTextureId() const { return nTextureId; }
}