#ifndef EVENT_HANDLER_HXX
#define EVENT_HANDLER_HXX

#include <SDL_events.h>

#include <point.hxx>

namespace project {

class EventHandler
{
public:
	void update_event_state();
	void reset();

	bool signal_quit() const;
	bool signal_refresh_render() const;
	bool signal_window_resized() const;

	auto mouse_pos() const -> Point<int> const&;
	bool mouse_left() const;
	bool mouse_right() const;

	bool intent_escape() const;
	bool intent_up() const;
	bool intent_down() const;
	bool intent_left() const;
	bool intent_right() const;
	bool intent_shift() const;

	bool key_r() const;

private:
	void handle_scancode(SDL_Scancode code, bool pressed);

	SDL_Event _event {};

	bool _signal_quit {};
	bool _signal_window_resized {};
	bool _signal_render_targets_reset {};
	bool _signal_render_device_reset {};

	Point<int> _mouse_pos {};
	bool _mouse_left {};
	bool _mouse_right {};

	bool _key_escape {};
	bool _key_up {};
	bool _key_w {};
	bool _key_down {};
	bool _key_s {};
	bool _key_left {};
	bool _key_a {};
	bool _key_right {};
	bool _key_d {};
	bool _key_lshift {};
	bool _key_rshift {};
	bool _key_r {};
};

}  // namespace project

#endif  // EVENT_HANDLER_HXX
