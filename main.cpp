#include <iostream>
#include <glew.h>
#include <GLFW/glfw3.h>
#include "GLM/glm/matrix.hpp"
#include "GLM/glm/gtc/matrix_transform.hpp"
#include "Loaders/ShaderLoader.h"
#include "Loaders/ObjectLoader.h"

/*
 * Method to handle the initialization process of the window
 */
static GLFWwindow* initialize()
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
        return nullptr;

    // Create a windowed mode window and its OpenGL context
    int width =  640;
    int height = 480;
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return nullptr;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return nullptr;
    }

    return window;
}

int main()
{
    std::cout << glfwGetVersionString() << std::endl;
    GLFWwindow* window = initialize();

    if(window == nullptr)
    {
        std::cout << "ERROR -- Initialization failed." << std::endl;
        return -1;
    }

    //we need to load the data for the object that we would like to draw from an object file
    //we can do this using the method that we have defined
    std::vector<glm::vec3> vertices, normals;
    std::vector<glm::vec2> uvs;
    //we try to load the object file and if we fail, then we simply exit the program since we won't be able to draw anything
    if(!LoadOBJ("../ObjectFiles/cat.obj", vertices, normals, uvs))
        return -1;

    //We will try to create a cube by using a vertex array object
    GLuint VertexArrayID; //this is our reference to our vao
    glGenVertexArrays(1, &VertexArrayID); //this will generate the actual array for us and we want only one
    glBindVertexArray(VertexArrayID); //then we make it the current one (pass to GPU)

    //Now in order for openGL to be able to draw this triangle we need to pass it then data by creating a vertex buffer
    //object
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*vertices.size(), &vertices.front(), GL_STATIC_DRAW);

    GLuint programID = LoadShaders("../Shaders/BasicVertexShader.shader", "../Shaders/BasicFragmentShader.shader");
    glUseProgram(programID);

    //in order for this object to be viewed from a perspective view, we need a Model View Projection matrix
    //we wish to draw the triangle from a perspective view
    //this is the projection matrix for a perspective view
    int width; //the width of the window
    int height; //the height of the window
    glfwGetWindowSize(window, &width, &height);
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) width/(float) height, 0.1f, 100.0f);

    //in order to make the camera ortho, we would use the following projection matrix
    //glm::mat4 Projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);

    //we then need a camera matrix
    //this specifies that the camera should be at 40, 40, -10
    //and looking at -5, 10, 15 which is the origin, while pointing in the direction (1, 1, 1)
    glm::mat4 View = glm::lookAt(glm::vec3(40, 40, -10), glm::vec3(-5,10,15), glm::vec3(1, 1, 1));

    //this is the model matrix (the identity matrix since we are placing the mode (our triangle) at the origin.
    //also changing this will modify what the final triangle looks like. This is where we apply transformations
    //such as scaling, translation, etc.
    glm::mat4 Model = glm::mat4(1.0f);

    //this is the model view projection matrix that we will pass to GLSL
    glm::mat4 MVP = Projection*View*Model;

    //now that we have created our matrix, we need to get a handle for it
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    //now that we have an identifier for it, we should set it to our bound shader, the vertex shader
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        //each time we draw we should clear both the color and the depth buffer bit so that the sorting process can
        //begin again from scratch
        //if we don't clear the depth buffer, then on the next frame everything we want to draw will be further than the
        //last closest item (obviously) and we won't have anything drawn
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //now we can draw our triangle
        //to do this we need to tell open GL about our vertex array (id 0) and also our color array(id 1)
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //this will allow us to access that buffer in GLSL

        //this configures the z-buffer so that only elements that are closer will be drawn
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        //here we need to specify 36 since we are drawing 36 vertices as explained above
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        glDisableVertexAttribArray(0);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        //check if there was input
        //this includes clicking the close button on the window
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}