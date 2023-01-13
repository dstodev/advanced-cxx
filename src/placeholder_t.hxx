#ifndef PLACEHOLDER_T_HXX
#define PLACEHOLDER_T_HXX

#include <compare>

class placeholder_t
{
public:
	virtual ~placeholder_t() = default;

	template <typename... Args>
	explicit constexpr placeholder_t([[maybe_unused]] Args&&... args) noexcept
	{}

	constexpr placeholder_t(placeholder_t const& copy) noexcept = default;
	constexpr placeholder_t(placeholder_t&& move) noexcept = default;

	placeholder_t& operator=(placeholder_t const& copy) noexcept = default;
	placeholder_t& operator=(placeholder_t&& move) noexcept = default;

	auto operator<=>(placeholder_t const& rhs) const = default;

	template <typename T>
	placeholder_t const& operator[](T) const
	{
		return *this;
	}

	template <typename... Ts>
	placeholder_t const& operator()(Ts...) const
	{
		return *this;
	}

#define generic_operator(symbol) \
	template <typename... Args> \
	[[maybe_unused]] auto& operator symbol(Args...) \
	{ \
		return *this; \
	}

	generic_operator(+);  // Semicolons for correct auto-format
	generic_operator(+=);
	generic_operator(-);
	generic_operator(-=);
	generic_operator(*);
	generic_operator(*=);
	generic_operator(/);
	generic_operator(/=);
	generic_operator(%);
	generic_operator(%=);
};

#endif  // PLACEHOLDER_T_HXX