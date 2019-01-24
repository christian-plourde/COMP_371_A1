#ifndef COMP_371_A1_KEYBOARDCONTROLS_H
#define COMP_371_A1_KEYBOARDCONTROLS_H
#endif

#include <glew.h>
#include <GLFW/glfw3.h>
#include "../GLM/glm/matrix.hpp"
#include "../GLM/glm/gtc/matrix_transform.hpp"

/*
 * This method defines what occurs when the w key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_w(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the s key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_s(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the a key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_a(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);

/*
 * This method defines what occurs when the d key is pressed on the keyboard. For this assignment, it modifies
 * the viewing angle of the camera and so to change this, we need to pass in the View, Projection, and Model
 * matrices, as well as the shader ID since we will need to update the value in the uniform in the shader program
 * once we have recalculated the location of the camera.
 */
void key_press_d(GLFWwindow* window, glm::mat4& View, glm::mat4& Projection, glm::mat4& Model, GLuint& ShaderID);