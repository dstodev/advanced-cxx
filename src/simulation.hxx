#ifndef SIMULATION_HXX
#define SIMULATION_HXX

namespace project {

/* TODO: Apply type erasure pattern & add metadata to container like position,
         velocity (vector), acceleration, etc. */
class Simulation
{
public:
	static constexpr auto TICKS_PER_SECOND = 30;

	Simulation();
	virtual ~Simulation() = default;

	/** @brief Process one cycle of the simulation
	 * @param seconds_elapsed Number of seconds elapsed since the tick()
	 *          function was last called.
	 */
	void tick(float seconds_elapsed);
};

}  // namespace project

#endif  // SIMULATION_HXX
