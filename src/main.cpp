#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>

#include <Window.h>
#include <shader.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

int main() {

    Window myWindow(800, 800, "My Window");

    float vertices[] = {
         0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f,       1.0f, 1.0f,     // upper right
         0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,       1.0f, 0.0f,     // lower right
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,       0.0f, 0.0f,     // lower left
        -0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 1.0f,       0.0f, 1.0f      // upper left
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

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8, 0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8, 3);
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8, 6);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // ======================================
    // Textures
    // ======================================

    int widthImage, heightImage, numColCh;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load("Textures/la_peace.png", &widthImage, &heightImage, &numColCh, 0);

    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImage, heightImage, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint tex0Uni = glGetUniformLocation(ourShader.ID, "tex0");
    ourShader.use();
    glUniform1i(tex0Uni, 0);

    // ======================================
    // Render Loop
    // ======================================
    while (!myWindow.ShouldClose()) {
        myWindow.Update();
        myWindow.Clear(0.07f, 0.13f, 0.17f, 1.0f);

        ourShader.use();

        glBindTexture(GL_TEXTURE_2D, texture);

        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        VAO1.Unbind();
    }

    glDeleteTextures(1, &texture);
    
    return 0;
}