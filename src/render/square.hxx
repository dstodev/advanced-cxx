#ifndef VAO_SQUARES_HXX
#define VAO_SQUARES_HXX

#include <GL/glew.h>

namespace project {

/// Renders a square or sequence of squares.
class Square
{
public:
	static unsigned constexpr vertices_per_square = 4u;  ///< top-left, top-right, bottom-right, bottom-left
	static unsigned constexpr indices_per_square = 6u;  ///< 2 triangles: TL, TR, BL and BR, TR, BL
	static unsigned constexpr shader_parameters_per_vertex = 3u;  ///< x y z
	static unsigned constexpr shader_parameters_per_square = vertices_per_square * shader_parameters_per_vertex;

	~Square();

	void init();
	void bind() const;

	void set_vertices(const float vertices[], unsigned num_squares = 1, int gl_mode = GL_STATIC_DRAW);  ///< Calls bind() and sets the vertices
	void draw() const;  ///< Assumes bind() has already been called

protected:
	unsigned _vao;
	unsigned _vbo;
	unsigned _ebo;

	void init_indices() const;

	unsigned _num_squares;
};

}  // namespace project

#endif  // VAO_SQUARES_HXX
