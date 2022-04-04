//
// Created by Winter on 12/02/2022.
//

#ifndef WIZENGINE_BASICGAME_H
#define WIZENGINE_BASICGAME_H


#include <unordered_set>
#include <functional>
#include "Game.h"

namespace wiz {
	class BasicGame;
}

class wiz::BasicGame : public Game {
	const std::shared_ptr<sf::RenderWindow> window;
	const std::shared_ptr<Logger> logger;
	const std::shared_ptr<AssetLoader> assetLoader;

	std::unordered_set<InputListener*> inputListeners, tmpInputListeners;
	std::unordered_set<WindowListener*> windowListeners, tmpWindowListeners;

	std::vector<std::function<void()>> runnables;

	std::shared_ptr<Screen> currentScreen = nullptr;

	std::chrono::time_point<std::chrono::high_resolution_clock> lastUpdate;
public:
	BasicGame(sf::RenderWindow* window, Logger* logger, AssetLoader* assetLoader);
	BasicGame(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Logger> logger, std::shared_ptr<AssetLoader> assetLoader);

	~BasicGame() override = default;

	void update() override;

	Screen& getScreen() override;
	const Screen& getScreen() const override;

	void setScreen(std::shared_ptr<Screen> screen) override;
	void setScreen(Screen* screen) override;

	Logger& getLogger() override;
	const Logger& getLogger() const override;

	sf::RenderWindow& getWindow() override;
	const sf::RenderWindow& getWindow() const override;

	AssetLoader& getAssets() override;
	const AssetLoader& getAssets() const override;

	void addInputListener(InputListener* listener) override;
	void removeInputListener(InputListener* listener) override;

	void addWindowListener(WindowListener* listener) override;
	void removeWindowListener(WindowListener* listener) override;

	void postRunnable(const std::function<void()>& runnable);
};


#endif //WIZENGINE_BASICGAME_H
