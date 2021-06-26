#ifndef SQUARE_H
#define SQUARE_H

#include <glm/gtc/matrix_transform.hpp>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Util.h"

//based on this https://upload.wikimedia.org/wikipedia/commons/1/15/Vertex-Vertex_Meshes_%28VV%29.png
float square_vertices[] = {
	-0.5f, -0.5f,
	 0.5f, -0.5f,
	  0.5f,  0.5f,
	-0.5f,  0.5f
};
unsigned int square_indices[] = {
	//bottom
	0,1,2,3
};

struct Transformation {
	glm::vec3 position;
	glm::vec3 rotation;
	float angle;
	glm::vec3 scale;
};


class Square {
	VertexBuffer* vb;
	VertexBufferLayout* vbl;
	IndexBuffer* ib;
	VertexArray* va;
	Shader* shader;

	Transformation tran;
	glm::mat4 t_matrix; //transformation matrix
	glm::mat4 p_matrix;
public:
	Square(Shader* s) {
		va = new VertexArray();
		vb = new VertexBuffer(square_vertices, 4 * 2 * sizeof(float));
		ib = new IndexBuffer(square_indices, 4);

		vbl = new VertexBufferLayout();
		vbl->Push<float>(2);
		va->AddBuffer(*vb, *vbl);

		shader = s;

		t_matrix = glm::mat4(1.f);
		tran.position = glm::vec3(1.0f);
		tran.rotation = glm::vec3(1.0f);
		tran.angle = glm::radians(0.f);
		tran.scale = glm::vec3(1.0f);

		//p_matrix = glm::perspective(glm::radians(45.0f), 640.f / 480.f, 0.1f, 100.0f);

		move(0, 0, 0);
	}
	~Square() {
		delete(vb);
		delete(vbl);
		delete(ib);
		delete(va);
	};

	void UpdateTransformation() {
		t_matrix = glm::translate(glm::mat4(1.0f), tran.position);
		t_matrix = glm::rotate(t_matrix, tran.angle, tran.rotation);
		t_matrix = glm::scale(t_matrix, tran.scale);
		t_matrix *= p_matrix;
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
		shader->Bind();
		shader->SetUniformMat4fv("matrix", t_matrix);
		vb->Bind();
		va->Bind();
		ib->Bind();
		GLCall(glDrawElements(GL_TRIANGLE_FAN, ib->GetCount(), GL_UNSIGNED_INT, nullptr));
	}
};

#endif
