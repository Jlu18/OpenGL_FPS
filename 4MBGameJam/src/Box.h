#ifndef BOX_H
#define BOX_H

#include <glm/gtc/matrix_transform.hpp>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Util.h"

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

struct Transformation {
	glm::vec3 position;
	glm::vec3 rotation;
	float angle;
	glm::vec3 scale;
};


class Box {
	VertexBuffer* vb;
	VertexBufferLayout* vbl;
	IndexBuffer*  ib;
	VertexArray*  va;
	Shader* shader;

	Transformation tran;
	glm::mat4 t_matrix; //transformation matrix
	glm::mat4 p_matrix;
public:
	Box(Shader*s) {
		vb = new VertexBuffer(verts, 3 * 8 * sizeof(float));
		vbl = new VertexBufferLayout();
		vbl->Push<float>(3);
		va = new VertexArray();
		va->AddBuffer(*vb, *vbl);

		ib = new IndexBuffer(indices, 12 * 3);
		shader = s;

		t_matrix = glm::mat4(1.f);
		tran.position = glm::vec3(1.0f);
		tran.rotation = glm::vec3(1.0f);
		tran.angle	  = glm::radians(0.f);
		tran.scale    = glm::vec3(1.0f);

		p_matrix = glm::perspective(glm::radians(45.0f), 640.f /480.f, 0.1f, 100.0f);

		move(0, 0, 0);
	}
	~Box() {
		delete(vb);
		delete(vbl);
		delete(ib);
		delete(va);
	};
	void BindAll() {
		vb->Bind();
		ib->Bind();
		va->Bind();
		shader->Bind();
	}

	void UpdateTransformation() {
		t_matrix = glm::translate(glm::mat4(1.0f), tran.position);
		t_matrix = glm::rotate(t_matrix, tran.angle, tran.rotation);
		t_matrix = glm::scale(t_matrix, tran.scale);
		//t_matrix *= p_matrix;
	}

	void move(float x, float y, float z) {
		tran.position = glm::vec3(x, y, z);
		UpdateTransformation();
	}
	void rotate(float angle, float x, float y, float z) {
		tran.rotation = glm::normalize(glm::vec3(x, y, z));
		tran.angle = glm::radians(angle);
		UpdateTransformation();
	}

	void Draw() {
		//shader.SetUniform4f("u_Color", 0.8f, 1.f, 0.5f, 1.f);

		shader->SetUniformMat4fv("matrix", t_matrix); //matrix

		GLCall(glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr));
	}
};

#endif // ! BOX_H
