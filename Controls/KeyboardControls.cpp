#include "KeyboardControls.h"
#include <iostream>

void key_press_w(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the w key is pressed on the keyboard, we should move the camera toward the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //out shader
    View = glm::translate(View, glm::vec3(0, 0 , -0.01));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_s(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the s key is pressed on the keyboard, we should move the camera away from the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0, 0 , 0.01));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_a(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the a key is pressed on the keyboard, we should move the camera to the left the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(-0.01, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_d(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the d key is pressed on the keyboard, we should move the camera to the right of the object
    //this is done by translating the View matrix in the x direction and then resetting the value of the uniform in
    //our shader
    View = glm::translate(View, glm::vec3(0.01, 0 , 0));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_o(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the o key is pressed on the keyboard, we should scale the object up by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(1.01f, 1.01f, 1.01f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void key_press_p(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID)
{
    //when the p key is pressed on the keyboard, we should scale the object down by 10%.
    //this is done by scaling the model matrix in all directions and then resetting the value of the uniform in
    //our shader
    Model = glm::scale(Model, glm::vec3(0.99f, 0.99f, 0.99f));
    glm::mat4 MVP = Projection*View*Model;
    GLuint MatrixID = glGetUniformLocation(ShaderID, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}



