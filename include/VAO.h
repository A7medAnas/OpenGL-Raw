#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO {

public:
    unsigned int ID;
    VAO() {
        glGenVertexArrays(1, &ID);
    }

    ~VAO() {
        glDeleteVertexArrays(1, &ID);
    }

    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, GLuint offset) {
        VBO.Bind();

        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride * sizeof(type), (void*) (offset * sizeof(type)));
        glEnableVertexAttribArray(layout);

        VBO.Unbind();
    }

    void Bind() {
        glBindVertexArray(ID);
    }
    void Unbind() {
        glBindVertexArray(0);
    }
};