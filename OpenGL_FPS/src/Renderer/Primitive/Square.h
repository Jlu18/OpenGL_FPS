#pragma once

namespace square {
	const static float square_vertices[] = {
		-0.5f, -0.5f, 0.f, //v0
		 0.5f, -0.5f, 0.f, //v1
		 0.5f,  0.5f, 0.f, //v2
		-0.5f,  0.5f, 0.f //v3
	};
	const static unsigned int square_indices[] = {
		//bottom
		0,1,3,
		1,2,3
	};

	const static unsigned int v_count = 12;
	const static unsigned int i_count = 6;
}