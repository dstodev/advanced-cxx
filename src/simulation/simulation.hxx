#ifndef SIMULATION_HXX
#define SIMULATION_HXX

#include <dll-export.h>
#include <player.hxx>
#include <point.hxx>
#include <scene.hxx>

namespace project {

// 16:9 aspect ratio
int constexpr DEFAULT_WIDTH = 1280;
int constexpr DEFAULT_HEIGHT = 720;

class DLL Simulation : public Scene
{
public:
	explicit Simulation(int view_width = DEFAULT_WIDTH, int view_height = DEFAULT_HEIGHT);

	void tick(uint64_t delta_ms) override;
	void accept(SceneVisitor& visitor) override;

	void resize(int width, int height);

	int width() const;
	int height() const;

	auto player() const -> Player const&;
	auto player() -> Player&;

	Point<int> center() const;

	struct Control
	{
		bool up;
		bool down;
		bool left;
		bool right;
		bool shift;
	};

	auto control() const -> Control const&;
	auto control() -> Control&;

protected:
	Control _intent {};

	void move_player(uint64_t delta_ms);

	int _width;
	int _height;

	Player _player;
};

}  // namespace project

#endif  // SIMULATION_HXX
