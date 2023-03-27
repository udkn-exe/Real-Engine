#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;//swap texture here (like if object gets hit and broken), can switch out texture here

	SpriteComponent(const char* path) {
		setTex(path);

	}
	void setTex(const char* path) {
		texture = TextureManager::LoadTexture(path);

	}

	void init()override {
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 48;
		destRect.w = destRect.h = 96;
	}

	void update()override {
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void draw()override {
		TextureManager::Draw(texture, srcRect, destRect);
	}
};