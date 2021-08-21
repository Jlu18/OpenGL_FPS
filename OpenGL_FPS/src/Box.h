#pragma once

//based on this https://upload.wikimedia.org/wikipedia/commons/1/15/Vertex-Vertex_Meshes_%28VV%29.png
const static float verts[] = {
	-0.5f, -0.5f, -0.5f, //v0
 	 0.5f, -0.5f, -0.5f, //v1
 	 0.5f,  0.5f, -0.5f, //v2
	-0.5f,  0.5f, -0.5f, //v3
	-0.5f, -0.5f,  0.5f, //v4
     0.5f, -0.5f,  0.5f, //v5
	 0.5f,  0.5f,  0.5f, //v6
	-0.5f,  0.5f,  0.5f  //v7
};
const static unsigned int indices[] = {
	//bottom
	0, 1, 3,
	1, 2, 3,
	//left
	0, 1, 4,
	0, 5, 4,
	//front
	1, 2, 5,
	2, 6, 5,
	//right
	2, 3, 6,
	3, 7, 6,
	//back
	3, 0, 7,
	0, 4, 7,
	//top
	7, 4, 6,
	4, 5, 6
};

const static unsigned int v_count = 24;
const static unsigned int i_count = 36;
