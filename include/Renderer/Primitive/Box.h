#pragma once

namespace Box {
	//vertex with normal
	//sign of the normal corresponds with sign of vertex (eg. v0 has all normal directed in negative axis, which is same as vertex)
	static float vertices[] = {

		//		   vertex				normal
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, //v0: -x, -y, -z
			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,

			 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, //v1: +x, -y, -z
			 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,

			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, //v2: +x, +y, -z 
			 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,

			-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, //v3: -x, +y, -z 
			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, //v4: -x, -y, +z
			-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

			 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, //v5: +x, -y, +z
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, //v6: +x, +y, +z
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			
			-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, //v7: -x, +y, +z
			-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f
	};

	static uint32_t indices[] = {
		//Back(-z)
		 0, 3, 9,
		 3, 6, 9,

		//Bottom(-y)
		13, 1, 16,
		 1, 4, 16,

		//Right(+x)
		17, 5, 20,
		 5, 8, 20,

		//Top(+y)
		19, 7, 22,
		7, 10, 22,

		//Left(-x)
		 2, 11, 14,
		11, 23, 14,

		//Front(+z)
		21, 12, 18,
		12, 15, 18
	};

	static uint32_t v_count = 144;
	static uint32_t i_count = 36;
};

/*
	Note to myself - always account for the actual size of the array when passes into buffer
	(not only the size of array but multiply with the data type (ie. float))
*/

/*
static float verts[] = {
	-0.5f, -0.5f, -0.5f, //v0 
	 0.5f, -0.5f, -0.5f, //v1
	 0.5f,  0.5f, -0.5f, //v2
	-0.5f,  0.5f, -0.5f, //v3
	-0.5f, -0.5f,  0.5f, //v4
	 0.5f, -0.5f,  0.5f, //v5
	 0.5f,  0.5f,  0.5f, //v6
	-0.5f,  0.5f,  0.5f, //v7
};

static uint32_t indices[] = {
	//bottom
	0, 1, 3,
	1, 2, 3,
	//left
	4, 0, 5,
	0, 1, 5,
	//front
	5, 1, 6,
	1, 2, 6,
	//right
	6, 2, 7,
	2, 3, 7,
	//back
	0, 3, 4,
	3, 7, 4,
	//top
	7, 4, 6,
	4, 5, 6
};

const static uint32_t v_count = 24;
const static uint32_t i_count = 36;

*/

////based on this https://upload.wikimedia.org/wikipedia/commons/1/15/Vertex-Vertex_Meshes_%28VV%29.png
//const static float verts[] = {
//	//back clock wise 
//	-0.5f, -0.5f, -0.5f, //0 
//	 0.5f, -0.5f, -0.5f, //1
//	 0.5f,  0.5f, -0.5f, //2
//	 0.5f,  0.5f, -0.5f, //2
//	-0.5f,  0.5f, -0.5f, //3
//	-0.5f, -0.5f, -0.5f, //0
//
//	-0.5f, -0.5f,  0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//	-0.5f, -0.5f,  0.5f,
//
//	-0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f, -0.5f,
//	-0.5f, -0.5f, -0.5f,
//	-0.5f, -0.5f, -0.5f,
//	-0.5f, -0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//
//	-0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f, -0.5f,  0.5f,
//	-0.5f, -0.5f,  0.5f,
//	-0.5f, -0.5f, -0.5f,
//
//	-0.5f,  0.5f, -0.5f,
//	 0.5f,  0.5f, -0.5f,
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f, -0.5f
//};
//static unsigned int v_count = 108;
//
//static float vertices_texture[] = {
//	   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//};

//static unsigned int vt_count = 180;