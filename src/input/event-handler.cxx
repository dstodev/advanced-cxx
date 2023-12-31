#include "event-handler.hxx"

#include <log.hxx>

namespace project {

void EventHandler::update_event_state()
{
	_signal_quit = false;
	_signal_window_resized = false;
	_signal_render_targets_reset = false;
	_signal_render_device_reset = false;

	while (SDL_PollEvent(&_event) != 0) {
		switch (_event.type) {
		case SDL_QUIT: _signal_quit = true; return;
		case SDL_KEYDOWN: handle_scancode(_event.key.keysym.scancode, true); break;
		case SDL_KEYUP: handle_scancode(_event.key.keysym.scancode, false); break;
		case SDL_WINDOWEVENT:
			switch (_event.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED: _signal_window_resized = true; break;
			default: break;
			}
			break;
		case SDL_RENDER_TARGETS_RESET:
			log::debug("Render targets reset_color\n");
			_signal_render_targets_reset = true;
			break;
		case SDL_RENDER_DEVICE_RESET:
			log::debug("Render device reset_color\n");
			_signal_render_device_reset = true;
			break;
		case SDL_MOUSEMOTION:
			_mouse_pos.x() = _event.motion.x;
			_mouse_pos.y() = _event.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (_event.button.button) {
			case SDL_BUTTON_LEFT: _mouse_left = true; break;
			case SDL_BUTTON_RIGHT: _mouse_right = true; break;
			default: break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (_event.button.button) {
			case SDL_BUTTON_LEFT: _mouse_left = false; break;
			case SDL_BUTTON_RIGHT: _mouse_right = false; break;
			default: break;
			}
			break;

		default: break;
		}
	}
}

void EventHandler::handle_scancode(SDL_Scancode code, bool pressed)
{
	switch (code) {
	case SDL_SCANCODE_ESCAPE: _key_escape = pressed; break;
	case SDL_SCANCODE_UP: _key_up = pressed; break;
	case SDL_SCANCODE_DOWN: _key_down = pressed; break;
	case SDL_SCANCODE_LEFT: _key_left = pressed; break;
	case SDL_SCANCODE_RIGHT: _key_right = pressed; break;
	case SDL_SCANCODE_W: _key_w = pressed; break;
	case SDL_SCANCODE_S: _key_s = pressed; break;
	case SDL_SCANCODE_A: _key_a = pressed; break;
	case SDL_SCANCODE_D: _key_d = pressed; break;
	case SDL_SCANCODE_LSHIFT: _key_lshift = pressed; break;
	case SDL_SCANCODE_RSHIFT: _key_rshift = pressed; break;
	case SDL_SCANCODE_R: _key_r = pressed; break;
	default: break;
	}
}

void EventHandler::reset()
{
	*this = EventHandler {};
}

bool EventHandler::signal_quit() const
{
	return _signal_quit;
}

bool EventHandler::signal_refresh_render() const
{
	return _signal_render_targets_reset;
}

bool EventHandler::signal_window_resized() const
{
	return _signal_window_resized;
}

auto EventHandler::mouse_pos() const -> Point<int> const&
{
	return _mouse_pos;
}

bool EventHandler::mouse_left() const
{
	return _mouse_left;
}

bool EventHandler::mouse_right() const
{
	return _mouse_right;
}

bool EventHandler::intent_escape() const
{
	return _key_escape;
}

bool EventHandler::intent_up() const
{
	return _key_up || _key_w;
}

bool EventHandler::intent_down() const
{
	return _key_down || _key_s;
}

bool EventHandler::intent_left() const
{
	return _key_left || _key_a;
}

bool EventHandler::intent_right() const
{
	return _key_right || _key_d;
}

bool EventHandler::intent_shift() const
{
	return _key_lshift || _key_rshift;
}

bool EventHandler::key_r() const
{
	return _key_r;
}

}  // namespace project
