target_sources(${target_name}
	PRIVATE
		renderer.cxx
		renderer.hxx
		scene-render-visitor.cxx
		scene-render-visitor.hxx
		texture.cxx
		texture.hxx
)
target_include_directories(${target_name}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

add_subdirectory(shader)
add_subdirectory(vao)
