#ifndef CAMERA_H
#define CAMERA_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class Camera {
    glm::mat4 view; //view matrix 
    glm::mat4 proj; //projection matrix
    glm::mat4 result; //multiply of view and projection matrix


    glm::vec3 pos;
    glm::vec3 up;
    glm::vec3 dir;

    float yaw, pitch, roll; //euler angle: x,y,z

    float fov;      //in radian
    float aspectRatio;

    void Update();
public:
    Camera(float fov, float aspectRatio, float near, float far);
    glm::mat4 getViewProjMatrix() { return result; };

    //Camera Transformation
    void Move(float x, float y, float z);
    void Rotate(float x, float y, float z);
    //void Zoom();
};

#endif