#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <shader.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "My Window", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, 800, 800);

    float vertices[] = {
         0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f, 
         0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f, 
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f, 
        -0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 1.0f  
    };
    unsigned int indices[] = { 
        0, 1, 3,    
        1, 2, 3     
    };

    // ======================================
    // إنشاء كائن الشيدر بمسار الملفات
    // ======================================
    Shader ourShader("assets/default.vert", "assets/default.frag");

    // ======================================
    // VAOs, VBOs, EBOs
    // ======================================
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // ======================================
    // Render Loop
    // ======================================
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // استخدام البرنامج عن طريق الكلاس
        ourShader.use();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    // ======================================
    // Terminators
    // ======================================
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}