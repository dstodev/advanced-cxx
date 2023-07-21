#include "renderer.hxx"

#include <SDL_render.h>

#include <event-handler.hxx>
#include <player.hxx>
#include <point_t.hxx>
#include <simulation.hxx>
#include <texture-cache.hxx>

namespace project {

Renderer::Renderer(EventHandler const& handler)
    : _renderer(nullptr)
    , _handler(handler)
    , _simulation(nullptr)
{}

void Renderer::init(SDL_Renderer* renderer)
{
	_renderer = renderer;
	refresh();
}

void Renderer::deinit()
{
	SDL_DestroyRenderer(_renderer);
}

void Renderer::refresh()
{
	textures::init_all(_renderer);
}

void Renderer::render()
{
	SDL_RenderPresent(_renderer);
}

void Renderer::clear()
{
	SDL_SetRenderDrawColor(_renderer, 0xe0, 0xf0, 0xff, 0xff);
	SDL_RenderClear(_renderer);
}

void Renderer::draw(Simulation const& simulation)
{
	_simulation = &simulation;
	draw(simulation.player());
	draw(_handler.mouse_pos());
}

void Renderer::draw(Player const& player)
{
	auto const& texture = textures::player;
	auto const x = _simulation->width() / 2;
	auto const y = _simulation->height() / 2;
	auto const rect = texture.rect_centered(x, y);

	int color_r = 0x80;
	int color_g = 0xff;
	int color_b = 0x9f;

	if (_handler.mouse_left()) {
		color_r -= 0x40;
		color_g -= 0x20;
		color_b += 0x30;
	}
	if (_handler.mouse_right()) {
		color_r -= 0x40;
		color_g -= 0x20;
		color_b += 0x30;
	}

	SDL_SetTextureColorMod(texture.data(), color_r, color_g, color_b);
	SDL_RenderCopy(_renderer, texture.data(), nullptr, &rect);

	if (_handler.intent_shift()) {
		auto const& texture = textures::shift;
		auto const rect = texture.rect_centered(x, y);

		SDL_SetTextureColorMod(texture.data(), 0xe0, 0x11, 0x5f);
		SDL_RenderCopy(_renderer, texture.data(), nullptr, &rect);
	}

	draw(player.position().cast<int>() + _simulation->center());
}

void Renderer::draw(point_t<int> const& point)
{
	SDL_Rect const square {static_cast<int>(point.x() - 1), static_cast<int>(point.y() - 1), 3, 3};

	SDL_SetRenderDrawColor(_renderer, 0xff, 0x00, 0x00, 0xff);
	SDL_RenderDrawRect(_renderer, &square);
}

}  // namespace project